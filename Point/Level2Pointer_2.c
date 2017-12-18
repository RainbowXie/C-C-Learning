# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <malloc.h>
int getMem(char** myp1, int* mylen1, char** myp2, int* mylen2)
{
	int ret = 0;
	char *tmp1, *tmp2;
	tmp1 = (char *)malloc(100);
	tmp2 = (char *)malloc(200);

	strcpy(tmp1, "1232341");
	strcpy(tmp2, "sfdggew");
	*mylen1 = strlen(tmp1);
	*mylen2 = strlen(tmp2);

	*myp1 = tmp1;   //2级指针的间接赋值
	*myp2 = tmp2;   //2级指针的间接赋值
	//myp1中放的是main函数中p1的地址，tmp1中存放的是一块内存空间的首地址；此时相当于
	//p1 = tmp1
	//通过*将该内存空间的首地址放入p1中。
	return ret;
}

int main()
{
	int ret = 0;
	char* p1 = NULL;
	int len1 = 0;
	char* p2 = NULL;
	int len2 = 0;

	ret = getMem(&p1, &len1, &p2, &len2);
	if ( 0 != ret )
	{
		printf("func getMem() err:%d\n", ret);
		return ret;
	}
	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	if ( NULL != p1 )
	{
		free(p1);
		p1 = NULL;
	}
	if ( NULL != p2 )
	{
		free(p2);
		p2 = NULL;
	}

	return ret;
}
