# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void copy_str1(char* from, char* to)
{
	for (; '\0' != *from; from++, to++ )
		*to = *from;
	*to = '\0';
	return ;
}

void copy_str2(char* from, char* to)
{
	for (; '\0' != *from; )
		*to++ = *from++;
	*to = '\0';
}

void copy_str3(char* from, char* to)
{
	while (  (*to = *from) != '\0' )
	{
		from++;
		to++;
	}
}

void copy_str4(char* from, char* to)
{
	while ('\0' != (*to++ = *from++) );

}

void copy_str5(char* from, char* to)
{
	while ( (*to++ = *from++) );

}

int  copy_str6_good(char* from, char* to)
{
	if (NULL == from || NULL == to)
		return -1;
	while ( (*to++ = *from++) );
	return 0;
}

int main()
{
	/*
	   char* from = "abcdefg";
	   char buf[100];
	//copy_str1(from, buf);
	//printf("buf:%s\n", buf);
	copy_str4(from, buf);
	printf("buf:%s\n", buf);


	return 0;
	*/
	int ret = 0;
	char buf[168];
	char buf2[168];
	char *p = NULL;
	p  = buf;
	printf("\n请输入一个字符串:");
	scanf("%s", p);
	printf("%s", p);
	getchar();
	getchar();

	ret = copy_str6_good(buf, buf2);
	if ( 0 != ret )
	{
		printf("func_copy_str06_good() er:%d", ret);
	}

	printf("%s\n", buf2);
}
