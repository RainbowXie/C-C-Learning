# include <stdio.h>

int hanoi(int n, char x, char y, char z)
{
	if (1 == n)//如果是1个盘子
		printf("move the number %d plate form %c to %c\n", n, x, z);//直接将x柱子上的盘子从x移到z

	else	
	{
		hanoi(n-1, x, z, y);//先将x柱子上的n-1个盘子借助z移到y
		printf("move the number %d plate form %c to %c\n", n, x, z);///直接将x柱子上的盘子从x移到z
		hanoi(n-1, y, x, z);//最后将y柱子上的n-1个盘子借助x移到z
	}

	return 0;
}

int main(void)
{
	//三个柱子
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	 
	printf("Please enter the number of plates to be moved:");
	scanf("%d", &n);

	hanoi(n, ch1, ch2, ch3);

	return 0;
}
