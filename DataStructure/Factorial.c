# include <stdio.h>

int main(void)
{
	int val;
	int i, mult = 1;

	printf("Please input a number:\n");
	printf("val = ");
	scanf("%d", &val);

	for (i = 1; i <= val; ++i)
		mult = mult * i;
	printf("mult =  %d\n", mult);

	return 0;
}
