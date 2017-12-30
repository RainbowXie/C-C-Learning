# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>

int getCount(char*, int*);
int trimSpace(char*, char*);

int main()
{
	char* p = "   abcdefg    ";
	char p1[20] = {0};

	int num = 0;
	getCount(p, &num);
	trimSpace(p, p1);

	printf("%s\n", p1);
	printf("ncount:%d\n", num);

	return 0;
}
//	求非空格的字符串长度

int getCount(char* str, int* pCount)
{
	char* p = str;
	int i = 0, j = 0;
	j = strlen(p) - 1;

	if ( NULL == str || NULL == pCount )
		return -1;

	while ( isspace(p[i]) && '\0' != p[i] )
	{
		i++;
	}
	while ( isspace(p[j]) && '\0' != p[j] )
	{
		j--;
	}
	*pCount = j - i + 1;

	return 0;
}

int trimSpace(char* str, char* newstr)
{
	char* p = str;
	int i = 0, j = 0;
	int nCount = 0;
	j = strlen(p) - 1;

	if ( NULL == str || NULL == newstr )
		return -1;
	//isspace：判断是否为空格，在ctype.h中
	while ( isspace(p[i]) && '\0' != p[i] )
	{
		i++;
	}
	while ( isspace(p[j]) && '\0' != p[j] )
	{
		j--;
	}

	nCount = j - i + 1;

	//从str中从第i位拷贝nCount个字符到newstr中
	strncpy(newstr, str+i, nCount);
	newstr[nCount] = '\0';

	return 0;
}
