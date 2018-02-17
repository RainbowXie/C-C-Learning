# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int CreateMem(char***, int);
int StrCopy(char**, char** from1, char from2[4][16], int, int);
void Qsort(char**, int, int);
int findPos(char** p3, int low, int high);
void freeMem(char*** p, int num);

int main()
{
	int ret, i;
	int num;
	int size1, size2;
	char* p1[] = {"222222", "111111", "333333"};
	char p2[4][16] = {"bbbbb", "aaaaa", "zzzzz", "ccccc"};

	char** p3 = NULL;

	size1 = sizeof(p1) / sizeof(*p1);
	size2 = sizeof(p2) / sizeof(*p2);
	num = size1 + size2;
	
	ret = CreateMem(&p3, num);

	if (ret)
	{
		printf("Func CreateMem err:%d", ret);
		return -1;
	}

	

	StrCopy(p3, p1, p2, size1, size2);

	for ( i = 0; i < num; i++ )
		printf("%s\n", p3[i]);

	Qsort(p3, 0, num-1);

	for ( i = 0; i < num; i++ )
		printf("%s\n", p3[i]);

	freeMem(&p3, num);
	
	return 0;
}

int CreateMem(char*** p3, int num)
{
	if ( NULL == p3 )
	{
		printf("p3 = 0!!\n");
		return -1;
	}

	int i;
	char** tmpP3 = NULL;
	tmpP3 = (char** )malloc(sizeof(char*) * num);

	if( NULL == tmpP3 )
	{
		printf("tmpp3 = 0!!\n");
		return -1;
	}

	memset(tmpP3, 0, sizeof(char*) * num);

	for ( i = 0; i < num; i++ )
		tmpP3[i] = (char* )malloc(sizeof(char) * 16);
	
	*p3 = tmpP3;
		
	return 0;
}

int StrCopy(char** to, char** from1, char from2[4][16], int size1, int size2)
{
	int i;
	int size = size1 + size2;
	while( NULL == from1 || NULL == from2)
	{
		printf("func StrCopy err!");
		return -1;
	}
	for ( i = 0; i < size1; i++ )
		strcpy(to[i], from1[i]);
	for ( ; i < size; i++ )
		strcpy(to[i], from2[i - size1]);
	return 0;
}

void Qsort(char** p3, int low, int high)
{
	int pos;

	if ( low < high )
	{
		pos = findPos(p3, low, high);
		Qsort(p3, low, pos-1);
		Qsort(p3, pos+1, high);
	}

	return;
}

int findPos(char** p3, int low, int high)
{
	char val[16] = {0};
	strcpy(val, p3[high]);

	while ( low < high )
	{
		while ( low < high && strcmp(p3[low], val) <= 0 )
			low++;
		strcpy(p3[high], p3[low]);

		while ( low < high && strcmp(p3[high], val) >= 0 )
			high--;
		strcpy(p3[low], p3[high]);
	}

	strcpy(p3[low], val);

	return low;
}
void freeMem(char*** p, int num)
{
	int i;
	for ( i = 0; i < num; i++ )
	{	
		if ( NULL != (*p)[i] )
			free((*p)[i]);
	}
	if ( NULL != *p )
		free(*p);
	*p = NULL;
}
