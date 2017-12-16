# include <stdio.h>

int AF(int *firstT, int Num, int*ComDiff)
{
	printf("%d ",*firstT);
	if (Num == 1)
	{
		return *firstT;
	}
	*firstT = *firstT + *ComDiff;
	return AF(firstT, Num-1, ComDiff);
}

int main (void)
{
	int firstT, Num, Comdiff;
	
	printf("Please imput the first term:");
	scanf("%d", &firstT);
	printf("Please imput the loop time:");
	scanf("%d", &Num);
	printf("Please imput the common difference:");
	scanf("%d", &Comdiff);
	AF(&firstT, Num, &Comdiff);
	printf("\n");


	return 0;
}
