# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct man
{
	int ID;
	char* name;
	char** child;
}Man;

int createMan(Man**, int, int);
void freeMan(Man** , int, int);
void QkSort(Man* str, int low, int high);
int FindPos(Man* str, int low, int high);
void PrintMan(Man* str, int Mnum, int Cnum);

int main()
{
	int Mnum = 2;
	int Cnum = 3;
	int ret = 0;
	int i, j;

	Man* manArr = NULL;

	ret = createMan(&manArr, Mnum, Cnum);
	if ( ret )
	{
		printf("createManerr:%d", ret);
		return -1;
	}

	for ( i = 0; i < Mnum; i++ )
	{
		printf("Please input no.%d Man's name:", i+1);
		scanf("%s", manArr[i].name);

		for ( j = 0; j < Cnum; j++ )
		{
			printf("Please input Man's no.%d Childs name:", j+1);
			scanf("%s", manArr[i].child[j]);
		}
	}

	QkSort(manArr, 0, Mnum-1);
	PrintMan(manArr, Mnum, Cnum);
	freeMan(&manArr, Mnum, Cnum);


	return 0;
}

int createMan(Man** pM, int Mnum, int Cnum)
{
	int i = 0, j = 0;
	Man* tmp = NULL;
	char** p = NULL;
	
	tmp = (Man* )malloc(sizeof(Man) * Mnum);

	if ( NULL == tmp )
		return -1;
	
	memset(tmp, 0, sizeof(Man) * Mnum);

	for ( i = 0; i < Mnum; i++ )
	{
		tmp[i].name = (char* )malloc(sizeof(char) * 64);
		
		p = (char** )malloc(sizeof(char* ) * Cnum);
		
		for ( j = 0; j < Cnum; j++ )
		{
			p[j] = (char* )malloc(sizeof(char) * 64);
		}
		tmp[i].child = p;
	}
	*pM = tmp;
	
	return 0;
}

void freeMan(Man** pM, int Mnum, int Cnum)
{
	int i, j;
	if ( NULL == pM )
		return;

	for ( i = 0; i < Mnum; i++ )
	{
		if ( NULL != (*pM)[i].name )
		{
			free((*pM)[i].name);
		}

		if ( NULL != pM[i]->child )
		{
			for ( j = 0; j < Cnum; j++ )
				free((*pM)[i].child[j]);
		}
		free((*pM)[i].child);
	}
	free(*pM);
	*pM = NULL;

	return ;
}

void QkSort(Man* str, int low, int high)
{
	int pos;

	if ( NULL == str )
	{
		printf("sortMan err:%d", -1);
		return;
	}
	
	if ( low < high )
	{
		pos = FindPos(str, low, high);
		QkSort(str, low, pos-1);
		QkSort(str, pos+1, high);
	}

	return;
}

int FindPos(Man* str, int low, int high)
{
	char* val = str[low].name;
	while (low < high)
	{
		while ( low < high && strcmp(str[high].name, val) >= 0 )
			high--;
		str[low].name = str[high].name;

		while ( low < high && strcmp(str[low].name, val) <= 0 )
			low++;
		str[high].name = str[low].name;
	}
	str[low].name = val;

	return low;
}

void PrintMan(Man* manArr, int Mnum, int Cnum)
{
	int i, j;

	for ( i = 0; i < Mnum; i++ )
	{
		printf("Man's name:%s\n", manArr[i].name);

		for ( j = 0; j < Cnum; j++ )
			printf("Man's children:%s  ", manArr[i].child[j]);
		printf("\n");
	}

	return ;
}
