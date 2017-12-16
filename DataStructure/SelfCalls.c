#include <stdio.h>

void f(int n)
{	
	if (n == 1)
		printf("hah\n");
	else
		f(n-1);

}

int main(void)
{
	f();

	return 0;
}
