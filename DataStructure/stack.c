#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE, *PNODE;

//栈的数据结构
typedef struct Stack
{
	PNODE pTop;	//一个指针指向栈顶
	PNODE pBottom;	//一个指针指向栈底，pBottom实际指向头节点，pTop指向尾节点
}STACK, *PSTACK;		//PSTACK等价于 struct Stack*

//函数
void initStack(PSTACK);
void pushStack(PSTACK, int);
void traverse(PSTACK);
bool popStack(PSTACK, int*);
void clear(PSTACK);

//主函数入口
int main(void)
{
	STACK S;	//STACK等价于struct Stack
	int val;	//保存出栈元素

	initStack(&S);	//初始化栈
	pushStack(&S, 1);
	pushStack(&S, 2);
	pushStack(&S, 4);
	pushStack(&S, 7);
	pushStack(&S, 24);
	traverse(&S);
	popStack(&S, &val);
	traverse(&S);
	clear(&S);
	traverse(&S);
	
	return 0;
}

void initStack(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("Allocation Fail.\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
}

void pushStack(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
/*这个是已存在节点指向新节点
	pS->pTop->pNext = pNew;
	pNew->pNext = NULL;
	pS->pTop = pNew;
*/
//这个是新节点指向已存在节点
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;

	while (pS->pBottom != p)
	{
		printf("%d\t", p->data);
		p = p->pNext;
	}
	printf("\n");
	
}

bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}

//把pS所指向的栈出栈一次，并把出栈的元素存入pVal所指向的变量中；如果出栈失败，返回false，否则返回true。
bool popStack(PSTACK pS, int* pVal)
{
	if (empty(pS))	
	{

		return false;
	}
	else
	{

		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = pS->pTop->pNext;
		free(r);
		r = NULL;
		return true;
	}
}

void clear(PSTACK pS)
{
	if (empty(pS))
		return;
	else
	{
		PNODE p, q;
		p = pS->pTop;
		q = pS->pTop->pNext;
		while (p != pS->pBottom)	
		{
			free(p);
			p = q;
			q = q->pNext;
		}
		pS->pTop = p;
	}

}
