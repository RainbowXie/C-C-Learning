# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int bufSplit(const char*, char*, char***, int);	//输入字符串、分隔符、输出指针数组、行数
int getRow(const char*, char*, int*);
int AllocMem(char***, int);

int main()
{
	char buf[] = "abcdef,acccd,eeee,aaaa,e3eeeee,ssss,";
	int Count = 0;
	char s[] = ",";
	char** PA = NULL;
	int ret = 0;
	int i;
	
	getRow(buf, s, &Count);
	AllocMem(&PA, Count);

	ret = bufSplit(buf, s, &PA, Count);

	if ( ret )
		printf("func bufSplit_err:%d\n", ret);

	for ( i = 0; i < Count; i++ )
		printf("%s\n", PA[i]);
	return 0;
}

//将字符串分离，分别存入数组中
int bufSplit(const char* String, char* s, char*** PointerArr, int Count)
{	
	if ( NULL == PointerArr || NULL == String)
		return -1;

	int i;
	char *pString = String;
	char** tmpPA = *PointerArr;


	for ( i = 0; i < Count; i++ )
	{
		while ( *s != *pString )
		{
			strncat(tmpPA[i], pString, 1);
			pString += strlen(s);
		}
		pString += strlen(s);
	}

	return 0;
}

//获取行数
int getRow(const char* String, char* s, int* Row)
{
	int Cnt = 0;
	char* pS = String;

	if ( NULL == String )
		return -1;

	while( NULL != pS )
	{
		pS = strstr(pS, s);
		if ( NULL != pS )
		{
			pS = pS + strlen(s);	//strstr的对象必须是字符串而不能是字符
			Cnt++;
		}
	}
	*Row = Cnt;

	return 0;
}

//分配内存
int AllocMem(char*** PointerArr, int num)
{
	
	int i = 0;

	char** tmpP = (char**)malloc(num * sizeof(char*));

	for ( i = 0; i < num; i++ )
	{
		tmpP[i] = (char*)malloc(10 * sizeof(char));
	}

	*PointerArr = tmpP;

	return 0;
}
