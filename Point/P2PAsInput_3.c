# include <stdio.h>
# include <stdlib.h>
# include <string.h>


char** getMem(int);
int printArr(char**, int);
int SortArr_1(char**, int);
int SortArr_2(char**, int);


int main()
{
	char** p2 = NULL;
	int num = 5;
	int i;

	p2 = getMem(num);
	printArr(p2, num);
	//SortArr_1(p2, num);
	//printArr(p2, num);
	SortArr_2(p2, num);
	printArr(p2, num);
	
	
	return 0;
}

//分配内存
char** getMem(int num)
{
	int i;	
	char** p2 = NULL;

	p2 = (char**)malloc(sizeof(char*) * num);
	if ( NULL == p2 )
		return NULL;

	for ( i = 0; i < num; i++ )
	{
		p2[i] = (char*)malloc(sizeof(char) * 100); 	//char buf[100];
		sprintf(p2[i], "%d%d%d", i+1, i+1, i+1);	//以%d的格式将i+1输入到p[i]中
	}



	return p2;
}

//打印
int printArr(char** p2, int num)
{
	int i;
	for ( i = 0; i < num; i++ )
	{
		printf("%s\n", p2[i]);
	}
	
	return 0;
}

//排序，交换指针指向
int SortArr_1(char** p2, int num)
{
	int i, j;
	char* tmp;
	for ( i = 0; i < num; i++ )
	{
		for ( j = i + 1; j < num; j++ )
		{
			if ( strcmp(p2[i], p2[j]) < 0 )
			{
				tmp = p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}

	return 0;
}

//排序，交换内存
int SortArr_2(char** p2, int num)
{
	char tmpbuf[100];
	int i, j;
	for ( i = 0; i < num; i++ )
	{
		for ( j = i + 1; j < num; j++ )
		{
			if ( strcmp(p2[i], p2[j]) < 0 )
			{
				strcpy(tmpbuf, p2[i]);
				strcpy(p2[i], p2[j]);
				strcpy(p2[j], tmpbuf);
			}
		}
	}	
	
	return 0;
}

//释放内存
int getMem_Free(char** p, int num)
{	
	int i;
	for ( i = 0; i < num; i++ )
	{
		if ( NULL != p[i] )
		{
			free(p[i]);
			p[i] = NULL;
		}
	}

	if ( NULL != p )
	{
		free(p);
	}

}
