#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define PR   printf
#define TRUE  1
#define FALSE 0

typedef struct peo {
	char name[20];
	char qq[20];
	char home[20];
	char tel[20];
	char email[20];
	struct peo* next;
}PEO;
PEO* search_add_pt(PEO*head, char name[])
{
	PEO* temp = head;
	PEO* temp_parent = NULL;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name)!=0)
		{
			temp_parent = temp;
			temp = temp->next;
		}
		else
		{
			if (strcmp(temp->name, name) == 0)
			{
				printf("***********有这么个人!!!************");
				return head;
			}
			else
			{
				break;
			}
		}
	}
	return temp_parent;//返回父节点，将在其后插入
}
PEO* add(PEO* head)//
{
	// char name[20],qq[20],home[20],tel[20],email[20];
	PEO *pt, *pt_insert;
	PEO *temp = head;
	pt = (PEO*)malloc(sizeof(PEO));
	printf("************请输入新的同学记录!!!!***************\n");
	printf("姓名 :"); scanf("%s", pt->name);
	printf("QQ :"); scanf("%s", pt->qq);
	printf("住址  :"); scanf("%s", pt->home);
	printf("电话  :"); scanf("%s", pt->tel);
	printf("Email:"); scanf("%s", pt->email);
	pt->next = NULL;
	if (head == NULL)
	{
		head = pt;
	}
	else
	{
		pt_insert = search_add_pt(head, pt->name);
		if (pt_insert != NULL)
		{
			temp = pt_insert->next;
			pt_insert->next = pt;
			pt->next = temp;
		}
		else //在头结点前面插入
		{
			temp = head;
			head = pt;
			head->next = temp;
		}
	}
	printf("*************输入记录成功!*****************\n");
	return head;
}
PEO* search_del_find_pt(PEO* head, char name[])
{
	PEO* temp = head;
	PEO* temp_parent = NULL;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)//表示name【20】的值第一次小于
		{
			return temp_parent;
		}
		else
		{
			temp_parent = temp;
			temp = temp->next;
		}
	}
	return temp_parent;
}
PEO* search_revise_p(PEO* head, char str[20])
{
	PEO *temp;
	temp = head;
	while (temp != NULL)
	{
		if (strcmp(str, temp->name) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
PEO* delet(PEO*head)
{
	PEO* temp = head;
	PEO* temp_parent = NULL;
	char name[20];
	printf("Input the name you what to delete: ");
	scanf("%s", name);
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)//表示name【20】的值第一次小于
		{
			if (temp_parent == NULL)//待删除节点为第一个节点
			{
				head = temp->next;
				printf("**************又没了个哥们!!!****************\n");
				return head;
			}
			else//待删除节点为一般节点
			{
				temp_parent->next = temp->next;
				printf("**************又没了个哥们!!!****************\n");
				return head;
			}
		}
		else
		{
			temp = temp->next;
		}
	}
	printf("***************没这么个人!******************\n");
	return head;
}
void find(PEO*head, char str[20])
{
	PEO* temp = head;

	if (head == NULL)
	{
		printf("the directory is blank!!");
		return;
	}
	while (temp != NULL)
	{
		if (strcmp(temp->name, str) == 0 || strcmp(temp->tel, str) == 0 || strcmp(temp->email, str) == 0)
		{
			printf("the result is :");
			printf("%s, %s, %s, %s, %s\n", temp->name, temp->qq, temp->home, temp->tel, temp->email);
			printf("呵呵，找到了!\n");
			return;
		}
		temp = temp->next;
	}
	printf("没这么个人啊!\n");
	return;
}
void sort_by_email(PEO * head)
{
	PEO *p = head, *q;
	char temp[20];
	while (p != NULL)
	{
		q = p;
		while (q->next != NULL)
		{
			if (strcmp(q->email, q->next->email) > 0)
			{
				strcpy(temp, q->name);
				strcpy(q->name, q->next->name);
				strcpy(q->next->name, temp);
				strcpy(temp, q->qq);
				strcpy(q->qq, q->next->qq);
				strcpy(q->next->qq, temp);
				strcpy(temp, q->home);
				strcpy(q->home, q->next->home);
				strcpy(q->next->home, temp);
				strcpy(temp, q->tel);
				strcpy(q->tel, q->next->tel);
				strcpy(q->next->tel, temp);
				strcpy(temp, q->email);
				strcpy(q->email, q->next->email);
				strcpy(q->next->email, temp);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void sort_by_tel(PEO * head)
{
	PEO *p = head, *q;
	char temp[20];
	while (p != NULL)
	{
		q = p;
		while (q->next != NULL)
		{
			if (strcmp(q->tel, q->next->tel) > 0)
			{
				strcpy(temp, q->name);
				strcpy(q->name, q->next->name);
				strcpy(q->next->name, temp);
				strcpy(temp, q->qq);
				strcpy(q->qq, q->next->qq);
				strcpy(q->next->qq, temp);
				strcpy(temp, q->home);
				strcpy(q->home, q->next->home);
				strcpy(q->next->home, temp);
				strcpy(temp, q->tel);
				strcpy(q->tel, q->next->tel);
				strcpy(q->next->tel, temp);
				strcpy(temp, q->email);
				strcpy(q->email, q->next->email);
				strcpy(q->next->email, temp);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void sort_by_name(PEO * head)
{
	PEO *p = head, *q;
	char temp[20];
	while (p != NULL)
	{
		q = p;
		while (q->next != NULL)
		{
			if (strcmp(q->name, q->next->name) > 0)
			{
				strcpy(temp, q->name);
				strcpy(q->name, q->next->name);
				strcpy(q->next->name, temp);
				strcpy(temp, q->qq);
				strcpy(q->qq, q->next->qq);
				strcpy(q->next->qq, temp);
				strcpy(temp, q->home);
				strcpy(q->home, q->next->home);
				strcpy(q->next->home, temp);
				strcpy(temp, q->tel);
				strcpy(q->tel, q->next->tel);
				strcpy(q->next->tel, temp);
				strcpy(temp, q->email);
				strcpy(q->email, q->next->email);
				strcpy(q->next->email, temp);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void list(PEO*head)
{
	PEO* pt = head;
	if (pt == NULL)
	{
		printf("*********无记录，请先输入记录!*********\n");
	}
	else
	{
		printf(" 姓名      | QQ        |   住址         |  电话     |  Email       \n");
		printf("----------- ----------- ---------------  -----------  -------------\n");
		while (pt != NULL)
		{
			printf("%-16s% -12s%-11s%-16s%s\n", pt->name, pt->qq, pt->home, pt->tel, pt->email);
			pt = pt->next;
		}

	}
}
PEO *revise(PEO*head)
{
	char str[20], str1[20], str2[20], str3[20], str4[20], str5[20];
	PEO *p;
	//p=(PEO*)malloc(sizeof(PEO));
	printf("please input a name :");
	scanf("%s", str);
	p = search_revise_p(head, str);
	if (p == NULL)
	{
		return head;
	}
	printf(" 姓名      | QQ        |   住址         |  电话     |  Email       \n");
	printf("----------- ----------- ---------------  -----------  -------------\n");
	printf("%-16s% -12s%-11s%-16s%s\n", p->name, p->qq, p->home, p->tel, p->email);
	printf("输入上边的: \n");
	printf("name: ");
	scanf("%s", str1);
	printf("qq: ");
	scanf("%s", str2);
	printf("home: ");
	scanf("%s", str3);
	printf("tel: ");
	scanf("%s", str4);
	printf("email: ");
	scanf("%s", str5);
	strcpy(p->name, str1);
	strcpy(p->qq, str2);
	strcpy(p->home, str3);
	strcpy(p->email, str4);
	strcpy(p->tel, str5);

	printf("*******修改成功!**********\n");
	return head;
}
void save(PEO*head)
{
	PEO* temp = head;
	FILE * fp;
	if ((fp = fopen("c:\\info.txt", "w")) == NULL)
	{
		printf("无法打开文档!!!!!!!!!!!!!!!!!!!!\n");
		exit(0);
	}
	else
	{
		while (temp != NULL)
		{
			fprintf(fp, "%15s%15s%12s%12s%20s\n", temp->name, temp->qq, temp->home, temp->tel, temp->email);
			temp = temp->next;
		}
		printf("************保存成功了耶!************\n");
	}
	if (fclose(fp))
	{
		printf("关不了文档!!!!!!!!!\n");
		exit(0);
	}
}
PEO* load()
{
	PEO* head = NULL;
	PEO* temp, *temp_parent;//temp用于存储产生的新节点，temp_parent用于存储前一节点，以便建立链表
	FILE * fp;
	if ((fp = fopen("c:\\info.txt", "r")) == NULL)
	{
		printf("关不了文档!!!!!!!!!!!!\n");
		exit(0);
	}
	else
	{
		while (!feof(fp))
		{
			temp = (PEO*)malloc(sizeof(PEO));
			fscanf(fp, "%15s%15s%12s%12s%20s\n", temp->name, temp->qq, temp->home, temp->tel, temp->email);
			temp->next = NULL;
			if (head == NULL)
			{
				head = temp;
			}
			else
			{
				temp_parent->next = temp;
			}
			temp_parent = temp;
			temp = temp->next;
		}
		printf("**********已有信息已经读入!***********\n");
	}
	if (fclose(fp))
	{
		printf("关不了文档!!!!!!!!!\n");
		exit(0);
	}
	return head;
}
void main()
{
	PEO* head = NULL;
	int c;
	printf("\t\t欢迎使用同学录!\n ");
	while (1)
	{
		PR("\n====================同学录==============================\n");
		PR("          1  添加同学，这个要经常用咧\n");
		PR("          2  删除同学，这个最好没有\n");
		PR("          3  显示同学信息\n");
		PR("          4  保存同学信息\n");
		PR("          5  读入已经信息\n");
		PR("          6  查找同学\n");
		PR("          7  修改记录\n");
		PR("          8  按分类排序\n");
		PR("          9  退出系统\n");
		PR("=========================================================\n");
		PR("\n请输入选项:");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			head = add(head);
			break;
		case 2:
			head = delet(head);
			break;
		case 3:
			list(head);
			break;
		case 4:
			save(head);
			break;
		case 5:
			head = load();
			break;
		case 6:
		{
			char str[20];
			printf("请输入姓名，电话，Email其中的一个:");
			scanf("%s", str);
			find(head, str);
			break;
		}
		case 7:
			head = revise(head);
			break;
		case 8:
		{ int s;
		printf("请选择分类 1 姓名, 2 电话,3 Email:  ");
		scanf("%d", &s);
		switch (s)
		{
		case 1:
			sort_by_name(head);
			break;
		case 2:
			sort_by_tel(head);
			break;
		case 3:
			sort_by_email(head);
			break;
		default:
			break;
		}
		printf("*********新的分类结果***********\n");
		list(head);
		break;
		}
		case 9:
			exit(0);
		default:
			break;
		}
	}

}



