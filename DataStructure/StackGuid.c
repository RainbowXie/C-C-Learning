#include <stdio.h>
#include <malloc.h>

void f()
{
	int m;

	double* q = (double *)malloc(200);

}

int main (void)
{
	int i = 10;
	int *p = (int*)malloc(100);

	return 0;
}
//m、q、i、p分配在栈上，而malloc分配在堆上
//静态分配在栈，动态分配在堆
//栈上由操作系统分配，堆上由程序员手动分配
//栈和堆区别是分配方式不同：出栈、压栈，堆排序
