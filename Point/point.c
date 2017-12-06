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
