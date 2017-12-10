#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node 
{
	int data;
	struct Node *pNext;
}NODE, *PNODE;

PNODE create_list(void);	//函数申明
void traverse_list(PNODE);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int*);	//第二个参数为第几个节点，第三个参数为删除节点的地址。
void sort_list(PNODE);

int main (void)
{
	PNODE pHead = NULL;	//等价于struct Node *pHead = NULL;
	pHead = create_list();	//创建一个非循环单链表，并将该链表的头节点的地址赋给pHead
	int len = length_list(pHead);
	int Val = 0;

	traverse_list(pHead);

	if (is_empty(pHead))
		printf("Linked is empty!\n");
	else
		printf("Linked not empty!\n");

	printf("The length of the linked is: %d\n", len);
	sort_list(pHead);
	traverse_list(pHead);

	insert_list(pHead, 4, 33);
	traverse_list(pHead);

	if (delete_list(pHead, 4, &Val))
		printf("delete complete!\nthe deleted value is: %d\n", Val);
	else 
		printf("delete fail!\n");
	traverse_list(pHead);

	return 0;
}

PNODE create_list(void)
{
	int len;	//用来存放有效节点的个数
	int i;
	int val;	//用来临时存放用户输入的节点的值

	//分配头节点，pHead为头指针
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("Memory allocation failure!\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	//输入节点个数
	printf("please input the number of Node:");
	scanf("%d", &len);

	//输入节点存放要存放的值
	for (i = 0; i < len; i++)
	{
		printf("Please input the Value of the %dth Node:", i+1);
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));	//每个循环申请一个内存空间，pNew指向这个空间
		if (NULL == pNew)
		{
			printf("Memory allocation failure!\n");
			exit(-1);
		}
		//假设分配第一个空间，此时pTail为头指针，pTail的指针域为空
		pNew->data = val;	//将输入的数据放入新节点的数据域
		pTail->pNext = pNew;	//pHead的指针域存放pNew的地址
		pNew->pNext = NULL;	//pNew的指针域置空
		pTail = pNew;		//pTail指向pNew
		//此时pNew指向第二个节点，既是尾节点，也是首节点；pTail指向首节点，也是尾节点；pHead依然指向头节点；pHead的指针域指向pNew；中间节点没有名字。
		//pTail永远指向尾节点。
		//pNew永远指向新的节点，
		/*
		   pHead->pNext = pNew;	//将pNew挂到pHead的指针域上
		   pNew->pNext = NULL;	//pNew的指针域置空
		   每次都将新的节点的地址放到首节点的指针域了，前面的空间就丢失了。
		   */

	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		printf("%d\t", p->data);
		p = p->pNext;
	}
	
	printf("\n");
}

bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else 
		return false;
}
int length_list(PNODE pHead)
{
	int cnt = 0;
	pHead = pHead->pNext;
	while (NULL != pHead)
	{
		cnt++;
		pHead = pHead->pNext;
	}
	return cnt;
}

void sort_list(PNODE pHead)
{
	int i, j, t, len;
	PNODE p;
	len = length_list(pHead);

	for (i = 0, pHead = pHead->pNext; i < len-1; i++, pHead = pHead->pNext)
	{
		for (j = i+1, p = pHead->pNext; j < len; j++, p = p->pNext)
		{
			if (pHead->data > p->data)
			{
				t = p->data;
				p->data = pHead->data;
				pHead->data = t;
			}

		}
	}
	
	return;
}


//在pHead所指向链表的第pos个节点的前面插入一个新的节点，该节点的值是val，并且pos的值是从1开始
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p && i < pos-1)	//如果p节点不为尾节点，则指针停在pos前一个节点。
	{
		p = p->pNext;
		++i;
	}
	if (i > pos-1 || NULL == p)	//如果pos <= 0，或p节点是尾节点，则返回错误。
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(PNODE));
	if (NULL == pNew)
	{
		printf("Dynamic allocated memory fail!\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;
}

bool delete_list(PNODE pHead, int pos, int *pVal)
{
	int i = 0;
	PNODE pTmp = NULL;
	while (NULL != pHead->pNext && i < pos-1)	//指针停在要删除节点的前一个节点，如果待删除节点的指针域为空，则跳出循环
	{
		pHead = pHead->pNext;
		i++;
	}
	if (i > pos-1 || NULL == pHead->pNext)		
		return false;

	pTmp = pHead->pNext;			//将待删除节点的地址放到临时变量
	*pVal = pHead->pNext->data;		//将待删除节点的值取出来
	pHead->pNext = pHead->pNext->pNext;	//将待删除节点的下一个节点地址放入待删除节点的前一个节点的指针域中

	free(pTmp);				//释放待删除节点空间
	pTmp = NULL;
	return true;
}
