# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int inverse(char* str);
void inverse_2(char*);
void inverse_2_1(char*);
void inverse_2_2(char*, char*);

char g_buf[100];
int main()
{
	char buf[] = "abcdefg";
	char mybuf[100] = {0};

	inverse(buf);
	printf("%s\n", buf);

	inverse_2(buf);
	printf("\n");
	memset(g_buf, 0, sizeof(g_buf));

	inverse_2_1(buf);
	printf("%s\n", g_buf);

	inverse_2_2(buf, mybuf);
	printf("%s\n", mybuf);
	return 0;
}

int inverse(char* str)
{	

	int length = 0;
	char* p1;
	char* p2;
	char c;

	if ( NULL == str)
		return -1;

	length = strlen(str);
	p1 = str;
	p2 = str + length - 1;

	while ( p1 < p2 )
	{
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		p1++;
		p2--;	
	}

	return 0;
}

void inverse_2(char *p)
{
	//递归结束的异常条件
	if ( NULL == p )
		return ;
	//递归结束的条件
	if ( '\0' == *p )
		return ;
	//让下一个字符的地址入栈
	inverse_2(p+1);

	printf("%c", *p);

	return ;
}

void inverse_2_1(char *p)
{
	if ( NULL == p )
		return ;
	if ( '\0' == *p )
		return ;

	inverse_2_1(p+1);

	strncat(g_buf, p, 1);

}

void inverse_2_2(char *p, char* mybuf)
{
	if ( NULL == p )
		return ;
	if ( '\0' == *p )
		return ;

	inverse_2_2(p+1, mybuf);

	//连接字符串，1次连接1个字符
	strncat(mybuf, p, 1);

}
