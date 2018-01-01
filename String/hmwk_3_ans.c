# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int getKeyByValue(char*, char*, char*, int*);
int trimSpace(char*, char*);

int main()
{
	int ret = 0;
	char buf[1024];
	int buflen = 0;

	char* keyandvalue = "key2 =     value2";
	char *key = "key2";

	ret = getKeyByValue(keyandvalue, key, buf, &buflen);
	
	if ( 0 != ret )
	{
		printf("func getKeyByValue() err:%d\n", ret);
		return ret;
	}

	printf("buf:%s\n", buf);


	return 0;
}

int getKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int *buflen)
{
	int ret = 0;
	char* p = NULL;

	if ( NULL == keyvaluebuf || NULL == keybuf || NULL == valuebuf )
		return -1;

	//1. 查找key是不是在母串中
	p = strstr(keyvaluebuf, keybuf);
	if ( NULL == p )
		return -1;

	//让辅助指针变量重新初始化
	p = p + strlen(keybuf);
	//2. 看有没有“=”号
	p = strstr(keyvaluebuf, "=");
	if ( NULL == p )
		return -1;
	//让辅助指针变量重新初始化
	p = p + strlen("=");

	//3. 在等号后面去除空格
	ret = trimSpace(p, valuebuf);

	if ( 0 != ret )
	{
		printf("func getKeyByValue() err:%d \n",ret);
		return -1;
	}
	
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
	while ( isspace(p[i]) && '\0' != p[i] )
	{   
		i++;
	}   
	while ( isspace(p[j]) && '\0' != p[j] )
	{   
		j--;
	}

	nCount = j - i + 1;

	strncpy(newstr, str+i, nCount);
	newstr[nCount] = '\0';
        return 0;
}
