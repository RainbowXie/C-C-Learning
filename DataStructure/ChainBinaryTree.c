#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct BTNode
{
	char data;
	struct BTNode * pLchild;	//p是指针，L是左，child是孩子
	struct BTNode * pRchild;
}BTNODE;

BTNODE* CreateBTree(void);
void PreTraverseBTree(BTNODE*);
void InTraverseBTree(BTNODE*);
void PostTraverseBTree(BTNODE*);

int main(void)
{
	BTNODE* pT = CreateBTree();
	
	PreTraverseBTree(pT);
//	InTraverseBTree(pT);
//	PostTraverseBTree(pT);

	return 0;
}

BTNODE* CreateBTree(void)
{
	BTNODE* pA = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pB = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pC = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pD = (BTNODE*)malloc(sizeof(BTNODE));
	BTNODE* pE = (BTNODE*)malloc(sizeof(BTNODE));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;

}

void PreTraverseBTree(BTNODE *pT)
{
	if ( NULL != pT )
	{
		printf("%c\t", pT->data);
		if ( NULL != pT->pLchild )
			PreTraverseBTree(pT->pLchild);
		if ( NULL != pT->pRchild )
			PreTraverseBTree(pT->pRchild);
	}
}

void InTraverseBTree(BTNODE *pT)
{
	if ( NULL != pT )
	{
		if ( NULL != pT->pLchild )
			InTraverseBTree(pT->pLchild);

		printf("%c\t", pT->data);

		if ( NULL != pT->pRchild )
			InTraverseBTree(pT->pRchild);
	}
}

void PostTraverseBTree(BTNODE *pT)
{
	if ( NULL != pT )
	{
		if ( NULL != pT->pLchild )
			PostTraverseBTree(pT->pLchild);
		if ( NULL != pT->pRchild )
			PostTraverseBTree(pT->pRchild);

		printf("%c\t", pT->data);

	}
}
