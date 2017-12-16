# include <stdio.h>

void f(int n)
{
	g(n);
}

void g(int m);
{
	f(m);
}

int main(void)
{
	int n;
	f(n);

	return 0;
}
