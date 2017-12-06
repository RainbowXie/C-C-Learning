#include <stdio.h>

int main (void)
{
	int a = 3;
	int b = 8;
	int* p = &a;
	int **q;
	q = &p;

	**q = 10;
	*q = &b;
	**q = 5;
	p = &b;
	*p = 9;

	printf("a = %d\tb = %d\n", a, b);
	return 0;
}
