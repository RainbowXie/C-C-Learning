#include <stdio.h>

int main(void)
{
	double* p;
	double x = 66.6;

	p = &x;	//x占8个字节，1个字节1个地址;用第一个字节的地址表示整个变量的地址。

	double arr[3] = {1.1, 2.2, 3.3};
	double* q;

	q = &arr[0];
	printf("%p\n", q);	//q指向arr[0]的第一个字节;arr[0]占8个字节。
	q = &arr[1];
	printf("%p\n", q);	//q指向arr[1]的第一个字节
//无论变量占几个字节，指针只占4/8个字节（依据你的计算机是32还是64位）。


	return 0;
}

