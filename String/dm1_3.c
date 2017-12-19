# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main()
{
	int i = 0;
	char buf[100] = "abcde";
	char* p = NULL;

	for (i = 0; i < strlen(buf); i++)
		printf("%c", buf[i]);
	printf("\n");

	return 0;
}
