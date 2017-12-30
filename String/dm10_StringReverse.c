# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int inverse(char* str);
int main()
{
	char buf[] = "abcdefg";

	inverse(buf);
	printf("%s\n", buf);

	return 0;
}

int inverse(char* str)
{	

	int length = 0;
	char* p1;
	char* p2;
	char c;
	
	if ( NULL == str1)
		return -1;

	length = strlen(str);
	p1 = str;
	p2 = str + length - 1;

	while ( p1 < p2 )
	{
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		p1++;
		p2--;	
	}

	return 0;
}
