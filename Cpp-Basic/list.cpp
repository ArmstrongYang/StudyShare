#include <iostream>

using namespace std;

typedef struct node {
	int value;
	struct node* next;
	node(int x) :value(x) {}
}NODE;

NODE* reverseList(NODE* pNode)
{
	if (pNode == NULL || pNode->next == NULL)
		return pNode;

	NODE* pHead = pNode, *pNext = NULL;
	while (pHead != NULL)
	{
		NODE* pTemp = pHead->next;
		pHead->next = pNext;
		pNext = pHead;
		pHead = pTemp;
	}
	return pNext;
}

int main_list()
{
	node* first = new node(1);
	node* second = new node(2);
	node* third = new node(3);
	node* forth = new node(4);
	node* fifth = new node(5);
	first->next = second;
	second->next = third;
	third->next = forth;
	forth->next = fifth;
	fifth->next = NULL;
	//�ǵݹ�ʵ��
	node* H1 = first;
	H1 = reverseList(H1);    //��ת
							 //�ݹ�ʵ��
	node* H2 = H1;    //���ڴ����öϵ�鿴H1�仯������H2�ٷ�ת��H1�Ѿ������仯
	//H2 = In_reverseList(H2); //�ٷ�ת

	return 0;
}