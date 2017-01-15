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

typedef struct FunNode {		//�߱���
	int				fun_id;		//���ڽӵ��ڶ��������е��±�
	FunNode	*next;		//���� ָ����һ���ڽӵ�
}FunNode;

typedef struct VertexNode {
	unsigned int	data;
	FunNode	*firstedge;		//�߱�ͷָ��
}VertexNode, FunList[MaxVex];

typedef struct {
	FunList		funList;
	unsigned int	numVertexes, numEdges;		//ͼ�е�ǰ�Ľ�����Լ�����
}GraphAdjList;
/****************************************/
//������ȱ�����Ҫ��ѭ������
typedef struct {
	int	data[MaxVex];
	int	front, rear;
}Queue;
/****************************************/
//���е���ز���
typedef struct FileStructType {
	unsigned int file_id;
	unsigned int fun_id_array[100];
	unsigned int fun_num;
	FileStructType	*next;
}FileStructType;

FileStructType *gFileList = NULL;

GraphAdjList *gFunMap;
//��ʼ��

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
���ܣ����һ���ļ����Լ�����ļ��ڵ����к���
���룺
file_id 	              �ļ�id
func_id_array          ����id���飬������֤������Ԫ�ز��ظ�
func_num               ��������
�����
��
���أ�
0���ɹ���-1��ʧ��
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
���ܣ����һ��������ֱ�ӵ��ù�ϵ�����Զ������
���룺
		caller_id   	    �����ߺ���id
		callee_id_array 	�����õĺ���id���飬������֤������Ԫ�ز��ظ���������Ԫ�ظ�����Ϊ0
		callee_num          �����õĺ���������������֤����������Ϊ0

����� 
		��
���أ�  
		0���ɹ���-1��ʧ��
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
���ܣ��ж�һ���ļ��Ƿ�ᱻLink����
���룺
	  file_id 			�ļ�id
�����
	  ��
���أ�
	  ���ļ��ᱻLink��������0�����ᱻLink��������-1�������ļ�id�����ڵȣ�
******************************************************************************/
//������ȱ���
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


