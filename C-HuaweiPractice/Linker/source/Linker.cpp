#include "Linker.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#define	MaxVex	255
#define	TRUE	1
#define	FALSE	0


int visited[MaxVex];

typedef struct FunNode {		//边表结点
	int				fun_id;		//该邻接点在顶点数组中的下标
	FunNode	*next;		//链域 指向下一个邻接点
}FunNode;

typedef struct VertexNode {
	unsigned int	data;
	FunNode	*firstedge;		//边表头指针
}VertexNode, FunList[MaxVex];

typedef struct {
	FunList		funList;
	unsigned int	numVertexes, numEdges;		//图中当前的结点数以及边数
}GraphAdjList;
/****************************************/
//广度优先遍历需要的循环队列
typedef struct {
	int	data[MaxVex];
	int	front, rear;
}Queue;
/****************************************/
//队列的相关操作
typedef struct FileStructType {
	unsigned int file_id;
	unsigned int fun_id_array[100];
	unsigned int fun_num;
	FileStructType	*next;
}FileStructType;

FileStructType *gFileList = NULL;

GraphAdjList *gFunMap;
//初始化

GraphAdjList *gFunArrsy[100];
void initFile(FileStructType *FileNode)
{
	FileNode->file_id = 0;
	for (unsigned int i = 0; i < 100; i++)
	{
		FileNode->fun_id_array[i] = 0;
	}
	//memset(FileNode->fun_id_array, 0, sizeof(gFileList->fun_id_array));
	FileNode->next = NULL;
	FileNode->fun_num = 0;
}
void updateFile(FileStructType *FileNode, unsigned int func_id_array[], unsigned int func_num)
{
	unsigned int fun_num = FileNode->fun_num;
	for (unsigned int i = fun_num; i < (fun_num + func_num); i++)
	{
		FileNode->fun_id_array[i] = func_id_array[i - fun_num];
	}
	//memcpy(FileNode->fun_id_array + sizeof(FileNode->fun_id_array[0]) * FileNode->fun_num, func_id_array, sizeof(FileNode->fun_id_array[0]) * func_num);
	FileNode->fun_num += func_num;

}
/******************************************************************************
功能：添加一个文件，以及这个文件内的所有函数
输入：
file_id 	              文件id
func_id_array          函数id数组，用例保证数组内元素不重复
func_num               函数个数
输出：
无
返回：
0：成功，-1：失败
******************************************************************************/

int AddFile(unsigned int file_id, unsigned int func_id_array[], unsigned int func_num)
{
	if (gFileList == NULL)
	{
		gFileList = (FileStructType *)malloc(sizeof(FileStructType));
		IF_INVALID_RETURN(gFileList, -1);
		initFile(gFileList);
		gFileList->file_id = file_id;
		updateFile(gFileList, func_id_array, func_num);
		gFileList->next = NULL;
		return 0;
	}
	FileStructType *tempFileNode = gFileList;
	FileStructType *endFileNode = NULL;
	while (tempFileNode)
	{
		if (tempFileNode->file_id == file_id)
		{
			updateFile(tempFileNode, func_id_array, func_num);
			return 0;
		}
		endFileNode = tempFileNode;
		tempFileNode = tempFileNode->next;
	}
	FileStructType *newFileNode = NULL;
	newFileNode = (FileStructType *)malloc(sizeof(FileStructType));
	IF_INVALID_RETURN(newFileNode, 0);
	initFile(newFileNode);
	newFileNode->file_id = file_id;
	updateFile(newFileNode, func_id_array, func_num);
	endFileNode->next = newFileNode;

	return 0;
}

unsigned int *gFunTable;
GraphAdjList *gFunArray = NULL;
void initFunNode(unsigned int *table)
{
	table = (unsigned int *)malloc(sizeof(unsigned int) * 100);
	for (int i = 0; i < 100; i++)
	{
		table[i] = 0;
	}
}
void CreateALGraph(unsigned int caller_id, unsigned int callee_id_array[], unsigned int callee_num);
/******************************************************************************
功能：添加一个函数的直接调用关系，可以多次增加
输入：
		caller_id   	    调用者函数id
		callee_id_array 	被调用的函数id数组，用例保证数组内元素不重复，数组内元素个数不为0
		callee_num          被调用的函数个数，用例保证函数个数不为0

输出： 
		无
返回：  
		0：成功，-1：失败
******************************************************************************/
int AddCallList(unsigned int caller_id, unsigned int callee_id_array[], unsigned int callee_num)
{
	int i, j, k;
	FunNode *p;
	if (gFunMap == NULL)
	{
		gFunMap = (GraphAdjList *)malloc(sizeof(GraphAdjList));
		memset(gFunMap, 0, sizeof(GraphAdjList));
	}
	gFunMap->numVertexes = callee_num + 1;
	gFunMap->numEdges = callee_num;

	for (i = 0; i<gFunMap->numVertexes; ++i)
	{
		if (i == 0)
		{
			gFunMap->funList[caller_id].data = caller_id;
			gFunMap->funList[caller_id].firstedge = NULL;
			continue;
		}
		gFunMap->funList[callee_id_array[i - 1]].data = callee_id_array[i - 1];
		gFunMap->funList[callee_id_array[i - 1]].firstedge = NULL;

	}

	for (k = 0; k<gFunMap->numEdges; ++k)
	{
		i = caller_id;
		j = callee_id_array[k];
		p = (FunNode *)malloc(sizeof(FunNode));
		p->fun_id = j;
		p->next = gFunMap->funList[i].firstedge;
		gFunMap->funList[i].firstedge = p;

		p = (FunNode *)malloc(sizeof(FunNode));
		p->fun_id = i;
		p->next = gFunMap->funList[j].firstedge;
		gFunMap->funList[j].firstedge = p;
	}
	return 0;
}


/******************************************************************************
功能：判断一个文件是否会被Link进来
输入：
	  file_id 			文件id
输出：
	  无
返回：
	  该文件会被Link进来返回0，不会被Link进来返回-1（包括文件id不存在等）
******************************************************************************/
//深度优先遍历
unsigned int startMain = 11;
unsigned int startState = 0;

int DFS(GraphAdjList G, unsigned int id, unsigned int fun_id)
{
	FunNode *p;
	visited[id] = TRUE;
	if (startState == 0)
	{
		startState = 1;
		id = 11;
		p = G.funList[11].firstedge;
	}
	else
		p = G.funList[id].firstedge;
	if (G.funList[id].data == fun_id)
		return 0;
	while (p)
	{
		if (!visited[p->fun_id])
			return DFS(G, p->fun_id, fun_id);
		p = p->next;
	}
	return -1;
}


int DFSTraverse(GraphAdjList G, unsigned int fun_id)
{
	int i;
	int ret=-1;
	for (i = 0; i<G.numVertexes; ++i)
		visited[i] = FALSE;

	for (i = 0; i < G.numVertexes; ++i)
	{
		if (!visited[i])
			ret = DFS(G, i, fun_id);
	}
	return ret;
}

int IsFileLinked(unsigned int file_id)
{
	FileStructType *tempFileList = gFileList;
	int ret = -1;
	while (tempFileList)
	{
		if (tempFileList->file_id == file_id)
		{
			for (int i = 0; i < tempFileList->fun_num; i++)
			{
				ret = DFSTraverse(*gFunMap, tempFileList->fun_id_array[i]);
				if (ret == 0)
					return 0;
			}
		}
		tempFileList = tempFileList->next;
	}
	return -1;
}


