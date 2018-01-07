# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int getRestbuf(const char*, int, int *, char*);
int findcount(const char*, int*);

int main()
{
	char buf1[] = "abcd11111abcd2222abcdqqqqq";
	int buflen = strlen(buf1);
	int count = 0;
	char buf2[128] = {0};

	getRestbuf(buf1, buflen, &count, buf2);
	
	printf("\"abcd\"Occurrence time:%d\nAfter reverse:%s\n",count, buf2);

	return 0;
}

int getRestbuf(const char* buf1, int buflen, int *count, char* buf2)
{
	if ( NULL == buf1 || NULL == buf2)
		return -1;

	char* pBuf1 = buf1;
	char fbuf1[] = "abcd";

	findcount(buf1, count);

	
	while ( 1 )
	{	
		pBuf1 = strstr(pBuf1, fbuf1);	//pBuf1指向下一个abcd
		while ( buf1 != pBuf1 )		//将buf1指向的字符放入buf2中
		{
			if ( '\0' == *buf1 )	//判断是否全部放完
				break;
		
			strncat(buf2, buf1, 1);	
			buf1 += 1;
		}
		if ( '\0' == *buf1 )
			break;

		strcat(buf2, "dcba");		//倒转abcd，放入buf2中
		pBuf1 += strlen("abcd");	//pBuf1、buf1向前跳4个字符
		buf1 += strlen("abcd");
	}
	return 0;
}


//找出"abcd"出现几次
int findcount(const char* buf, int* count)
{
	if ( NULL == buf ) 
		return -1;

	char* pBuf = buf;

	while ( NULL != pBuf )
	{
		pBuf = strstr(pBuf, "abcd");
		if ( NULL != pBuf )
		{
			pBuf += strlen("abcd");
			*count += 1;
		}
	}

	return 0;
}
