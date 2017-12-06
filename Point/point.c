#include <stdio.h>

//指针数组练习
int main(void)
{
	//int a[10];
	char* arry[] = {"hello", "world", "itcast"};//字符串存放在只读数据区，只能读不能写
	char arr[3][20] = {"hello", "world", "itcast"};//字符串存放在栈上，局部数组，可读可写
	//char *str = "hello";
	int i;
	
	printf("%d\n", sizeof(arry));//arry保存地址
	for (i = 0; i < 3; i++)
	{
		printf("%p\t%s\n", arry[i], arry[i]);//%p将arry[i]的地址打印出来;%s从arry[i]中取字符出来
	}
}
//指针数组易犯错误

int main(void)
{
	char arr[3];	//要存放字符串，但是是一维数组，没有初始化，野指针

	int i;
	
	for (i = 0; i < 3; i++)
	{
		scanf("%s\n", arry[i]);	//存放字符串使用二维数组
	}
	for (i = 0; i < 3; i++)
	{
		printf("%s\n", arry[i]);
	}
}

