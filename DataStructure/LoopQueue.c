# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct Queue
{
	int *pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE*, int);
void traverse_queue(QUEUE*);
bool full_queue(QUEUE*);
bool out_queue(QUEUE*, int *);
bool empty_queue(QUEUE*);

int main(void)
{
	int val;
	QUEUE Q;

	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	traverse_queue(&Q);
	if (out_queue(&Q, &val))
		printf("dequeue complete!\nThe element is:%d\n", val);
	else
		printf("dequeue fail!\n");
	traverse_queue(&Q);


	return 0;
}

void init(QUEUE *pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int) * 6);	//pBase指向有24个字节的一个整型的数组。
	pQ->front = 0;
	pQ->rear = 0;

}

bool en_queue(QUEUE* pQ, int val)
{
	if ( full_queue (pQ))
	{
		return false;
	}
	else 
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}
}

void traverse_queue(QUEUE* pQ)
{
	int i;
	i = pQ->front;
	for (; i != pQ->rear; i = (i + 1) % 6)
		printf("%d\t", pQ->pBase[i]);
	printf("\n");
	return;
}

bool full_queue(QUEUE* pQ)
{
	if ( (pQ->rear + 1) % 6 == pQ->front )
		return true;
	else
		return false;
}

bool empty_queue(QUEUE *pQ)
{
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}

bool out_queue(QUEUE* pQ, int * pVal)
{
	if ( empty_queue(pQ) )
		return false;
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}

}
