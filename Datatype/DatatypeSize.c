# include <stdio.h>

int main()
{
	int a = 10;
	int b[10] ;
	printf("int a:%d \n", sizeof(a));
	printf("b:%p, b+1:%p, &b:%p, &b+1:%p \n", b, b+1, &b, &b+1);
	printf("int a:%d \n", sizeof(int *));
	printf("int b:%d \n", sizeof(b));
	printf("int b:%d \n", sizeof(b[0]));
	printf("int b:%d \n", sizeof(*b));
	printf("hello.....\n");
	getchar();
	return 0;
} 
