#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[5] = {4, 10, 2, 8, 6};	//没有通过malloc分配的都看作静态数组
	//可以通过下标使用数组;
	
//动态分配内存;
	int len = 0;
	printf("Please input array length:");
	scanf("%d", &len);
	int *pArr = (int *)malloc(sizeof(int) * len);	//分配 (int所占字节数×len数量) 个字节(sizeof(int) * len)，格式为int型(int *)；
	//假设len=5，即将20个字节的访问控制权限给我；我处理完后再将20个字节的控制权限还给系统，就叫释放。
	//malloc返回的是第一个字节的地址，强制类型转换（int *）告诉计算机以int类型来处理20个地址。
	//pArr 指向前四个字节
	
	//可以把pArr当作普通数组使用
	
	*pArr = 4;	//类似于a[0] = 4;
	pArr[1] = 10;	//类似于a[1] = 10;
	
	printf("%d %d\n", *pArr, pArr[1]);

	free(pArr);

	return 0;
}
//动态分配数组的好处：
//	1.可以按需分配
//	2.用完可以释放
