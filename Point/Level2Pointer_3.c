# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int getMem(char** myp1, int * mylen1, char** myp2, int *mylen2)
{
	char *tmp1 = NULL;
	char *tmp2 = NULL;
	tmp1 = (char*)malloc(100);
	tmp2 = (char*)malloc(100);

	if ( NULL == tmp1 )
		return -1;
	strcpy(tmp1, "abcdefg");
	*mylen1 = strlen(tmp1);
	*myp1 = tmp1;   //间接修改实参p1的值

	if ( NULL == tmp2 )
		return -2;
	strcpy(tmp2, "1122334");
	*mylen1 = strlen(tmp2);
	
	*myp2 = tmp2;

	return 0;
}

//释放内存空间
int getMem_Free(char** myp)
{
	if ( NULL == myp )
		return -5;
	free(*myp);    //释放完指针变量所指的内存空间
	*myp = NULL;   //把实参修改成NULL

	return 0;
}
int getMem_Free2(char** myp)
{
	char* tmp = NULL;
	if ( NULL == myp )
		return -6;
	tmp = *myp;
	free(tmp);
	*myp = NULL;

	return 0;
}

int main()
{
	char* p1 = NULL;
	int len1 = 0;

	char* p2 = NULL;
	int len2 = 0;

	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2);
	if (ret)
	{
		printf("err:%d", ret);
		return -1;
	}

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);
	
	getMem_Free(&p1);
	getMem_Free2(&p2);

	return 0;
}

