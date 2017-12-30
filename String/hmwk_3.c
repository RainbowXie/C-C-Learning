# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int getKeyByValue(char*, char*, char*, int*);
int getKeyValue(char* , int*, char*);

int main()
{

	char KeyValueBuf[128];
	char KeyBuf[32];
	char ValueBuf[96];
	int ValueBufLen = 0;
	printf("Please input:");

	//gets
	gets(KeyValueBuf);

	getKeyByValue(KeyValueBuf, KeyBuf, ValueBuf, &ValueBufLen);
	printf("Key:%s\nValue:%s\n", KeyBuf, ValueBuf);


	return 0;
}

//
int getKeyValue(char* kvb/*in*/, int* len/*in*/, char* kav/*out*/)
{
	while ('\0' != *kvb)
	{
		if ( 32 != *kvb )
		{
			*kav++ = *kvb;
		}
		
		kvb++;
	}
	*kav = '\0';
	
	return 0;
}

//KeyBuf,ValueBuf
int getKeyByValue(char* kvb/*in*/, char* kb/*out*/, char* vb/*out*/, int* vbl/*in*/)
{
	char KeyAndValue[128];
	char* tmpKAV = KeyAndValue;

	getKeyValue(kvb, vbl, KeyAndValue);
	printf("%s\n", KeyAndValue);
	do
	{
		*kb++ = *tmpKAV++;

	}while ( '=' != *tmpKAV );
	*kb = '\0';
	tmpKAV++;
	do
	{
		*vb++ = *tmpKAV++;
	}while ( '\0' != *tmpKAV );
	*vb = '\0';
	
	if ( NULL != tmpKAV )
	{
		free(tmpKAV);
		tmpKAV = NULL;
	}
	return 0;
}


