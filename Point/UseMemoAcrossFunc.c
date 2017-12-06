#include <stdio.h>

int f();
int main()
{
	int i = 10;

	i = f();

	printf("i = %d\n", i);

	return 0;
}

int f()
{
	int j = 20;

	return j;
}
