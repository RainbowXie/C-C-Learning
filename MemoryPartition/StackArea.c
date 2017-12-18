# include <stdio.h>
# include <malloc.h>
# include <string.h>

char* getMem(int num)
{
	char* p1 = NULL;
	p1 = (char*)malloc(sizeof(char) * num);

	if (NULL == p1)
		return NULL;

	return p1;
}
char* getMem2()
{
	char buf[64];       //临时变量，栈区存放
	strcpy(buf, "123456789");
	printf("buf:%s\n", buf);
	return buf;         //把内存块首地址返回给tmp
}

int main()
{
	char* tmp = NULL;
	tmp = getMem(10);

	if ( NULL == tmp)
		return 0;
	strcpy ( tmp, "111222");	//向tmp所指向的内存空间中复制数据
	printf("tmp:%s\n", tmp);
	
	tmp = getMem2();
	printf("tmp:%s\n", tmp);
	return 0;
}
