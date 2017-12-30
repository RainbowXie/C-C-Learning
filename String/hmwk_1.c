# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int trimeSpace(char*, char*);


int main()
{	
	int ret = 0;
	
	char put[] = "   abcdefgdddd    ";
	char get[32] = {0};

	ret = trimeSpace(put, get);
	if ( ret )
	{
		printf("ret:%d\n", ret);
		return 0;
	}
	printf("%s\n", get);
	
	return 0;
}

int trimeSpace(char* inbuf, char* outbuf)
{
	char* from = inbuf;
	char* to = outbuf;
	if ( NULL == inbuf || NULL == outbuf )
	{
		printf("trimeSpace err:NULL input\n");
		return -1;
	}
	while ( *from++ != '\0')
	{
		if ( *from != 32 )
			*to++ = *from;
	}
	*to = '\0';

	return 0;
}
