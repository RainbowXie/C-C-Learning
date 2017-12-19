# include <string.h>
# include <stdio.h>
# include <stdlib.h>
int main()
{
	char buf2[] = {'a', 'b','c','d','\0'};
	char buf3[] = "abcde";    
	char buf4[] = {"abcde"};
	char buf5[100] = "abcde";  

	printf(" strlen(buf3) :%ld \n", strlen(buf3));
	printf(" sizeof(buf3) :%ld \n", sizeof(buf3));
	printf(" sizeof(buf4) :%ld \n", sizeof(buf4));
	printf(" strlen(buf4) :%ld \n", strlen(buf4));

	system("pause");
	return 0;
}
