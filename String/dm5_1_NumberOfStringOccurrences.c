# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int afunc(char*);
int afunc_2(char*, char*, int*);
int main()
{
	int nCount = 0;
	int ret = 0;
	char* pS = "abcd234r3reabcdneji04u3abcdergoabcd";
	char pC[] = "abcd";

	ret = afunc_2(pS, pC, &nCount);
	if ( 1 == ret )
		printf("nCount:%d\n", nCount);
	else
		printf("afunc_2 err:%d\n", ret);
	return 0;
}

int afunc(char* p)
{
	int nCount = 0;
	char* tmpS = p;
	
	do
	{
		tmpS = strstr(tmpS, "abcd");
		if (NULL != tmpS)
		{
			nCount++;
			tmpS = tmpS + strlen("abcd");
		}
	}while ('\0' != *tmpS);
	
	return nCount;
}


int afunc_1(char* p)
{
	int nCount = 0;
	char* tmpS = p;
	
	do
	{
		tmpS = strstr(tmpS, "abcd");
		if (NULL != tmpS)
		{
			nCount++;
			tmpS = tmpS + strlen("abcd");
		}
		else
			break;
	}while ('\0' != *tmpS);
	

	return nCount;
}

int afunc_2(char* p, char* pC, int* nCount)
{
	char* tmpS = p;
	if (NULL == p || NULL == pC || NULL == nCount )
		return -1;
	while ( ( tmpS = strstr(tmpS, pC) ) )
	{
			(*nCount)++;
			tmpS = tmpS + strlen(pC);
	}
	if ( NULL != tmpS )
		return -2;
	return 1;
}
