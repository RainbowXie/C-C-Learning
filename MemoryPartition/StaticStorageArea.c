# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char* getStr1()
{
	char* p = "abcdefg2";
	return p;
}

char* getStr2()
{
	char* p2 = "abcdefg2";
	return p2;
}



int main()
{
	char* p1 = NULL;
	char* p2 = NULL;

	p1 = getStr1();
	p2 = getStr2();

	printf("p1:%s, p2:%s\n", p1, p2);
	printf("p1:%p, p2:%p\n", p1, p2);
	
	return 0;
}
