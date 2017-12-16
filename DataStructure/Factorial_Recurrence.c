# include <stdio.h>

long f(long n)
{
	if (1 == n)
		return 1;
	else
		return f(n - 1) * n;
}

int main(void)
{
	printf("%d\n", f(6));	
	return 0;
}
