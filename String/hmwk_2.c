# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int getStr1Str2(char* sourse, char* buf1, char* buf2);
int err_test(char*, char*, char*, int, int);

int main() 
{
	int ret = 0;
	char* sourse = "1a2b3d4z8f7v0g2h5h4g0f";
	int len1, len2;
	char buf1[10];
	char buf2[10];

	len1 = sizeof(buf1);
	len2 = sizeof(buf2);

	ret = err_test(sourse, buf1, buf2, len1, len2);
	getStr1Str2(sourse, buf1, buf2);

	if ( !ret )
		printf("%s\n%s\n", buf1, buf2);
	else
		printf("%d\n", ret);

	return 0;
}

int getStr1Str2(char* sourse, char* buf1, char* buf2)
{
	char* tpBuf1 = buf1;
	char* tpBuf2 = buf2;
	char* tpSourse = sourse;
	int i = 0;

	while ( '\0' != *tpSourse )
	{
		if ( i % 2 )
			*tpBuf2++ = *tpSourse;
		else
			*tpBuf1++ = *tpSourse;
		i++;
		tpSourse++;
	}
	*tpBuf1 = *tpBuf2 = '\0';

	return 0;
}

int err_test(char* sourse, char* buf1, char* buf2, int len1, int len2)
{
		if ( NULL == sourse || NULL == buf1 || NULL == buf2 )
	{
		printf("getStr1Str2_err:");
		return -1;
	}
	else if ( len1 - 1 < ( strlen(sourse) / 2 ) || len2 - 1 < ( strlen(sourse) / 2 ) ) 
	{
		printf("getStr1Str2_err:");
		return -2;
	}
	return 0;
}
