# include <stdio.h>

int getMem(char* p2)
{
	*p2 = 200;    //p2是p1的地址

	return 0;
}
int main()
{
	char* p1 = NULL;
	char** p2 = NULL;

	p1 = 0x11;
	p2 = 0x22;

	p1 = 0x111;

	p2 = &p1;
	*p2 = 100;  //间接赋值  p2是p1的地址
	printf("p1:%d\n", p1);

	getMem(&p1);
	printf("p1:%d\n", p1);


	return 0; 
}
