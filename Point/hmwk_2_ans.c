# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int splitString2(const char*, char, char**, int*);
int splitString3(const char*, char, char***, int*);
void FreeMem2(char**, int*);

int main()
{
	int ret = 0, i = 0;
	char* p1 = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";
	char cTem = ',';
	int nCount;
	char** p = NULL;
	char** p3 = NULL;

	
	//////////////////////////////////////////////////////
	//第一种：函数外分配内存
	p = (char**)malloc(sizeof(char*) * 10);		//char* array[10];
	if ( NULL == p )
		return -1;
	for ( i = 0; i < 10; i++ )
	{
		p[i] = (char*)malloc(sizeof(char) * 30);
	}
	
	//调用函数
	ret = splitString2(p1, cTem, p, &nCount);

	//打印结果
	for ( i = 0; i < nCount; i++ )
		printf("%s\n", p[i]);
	
	//释放内存
	for ( i = 0; i < 10; i++ )
	{
		if ( NULL != p[i] )
			free(p[i]);
	}
	if (NULL != p)
		free(p);
	
	//////////////////////////////////////////////////////
	//第二种：函数内分配内存
	ret = splitString3(p1, cTem, &p3, &nCount);

	if ( 0 != ret )
	{
		printf("func splitString2() err:%d\n", ret);
		return ret;
	}

	if( NULL == p3 )
	{
		printf("func splitString3() err:%d\n", ret);
		return ret;
	}
	
	//打印结果
	for ( i = 0; i < nCount; i++ )
		printf("%s\n", p3[i]);
	
	//释放内存
	for ( i = 0; i < nCount; i++ )
	{
		if ( NULL != p3[i] )
			free(p3[i]);
	}
	if (NULL != p3)
		free(p3);
	//////////////////////////////////////////////////////
	
	return 0;
}

int splitString2(const char* buf1, char c, char** myp, int* count)
{
	char* p = NULL, *pTmp = NULL;
	int tmpcount = 0;

	//p和ptmp初始化
	p = buf1;
	pTmp = buf1;

	do
	{
		//检索符合条件的位置，p后移，形成差值，挖字符串
		p = strchr(p, c);	//返回字符c第一次在p中出现的位置
		if ( NULL != p )
		{
			if ( p - pTmp > 0 )	//字符串的生长方向是从小到大
			{
				strncpy(myp[tmpcount], pTmp, p - pTmp);
				myp[tmpcount][p-pTmp] = '\0';	//把第一行数据变成c风格字符串
				tmpcount++;
				//重新让p和pTmp达到下一次检索的条件
				pTmp = p = p + 1;
			}
		}
		else
			break;
	}while( '\0' != *p );

	*count = tmpcount;

	return 0;
}

//被调用函数分配内存，按需分配，节约内存
int splitString3(const char* buf1, char c, char*** myp3, int* count)
{
	char* p = NULL, *pTmp = NULL;
	int tmpcount = 0;
	p = buf1;
	pTmp = buf1;
	char **myp = NULL;
	int ret = 0;

	///////////////////////////////////////////////
	//扫描两遍，第一遍求出count
	do
	{
		p = strchr(p, c);
		if ( NULL != p ) 
		{
			if ( p -pTmp > 0)
			{
				tmpcount++;
				pTmp = p = p + 1;
			}
		}
		else
			break;
	}while( '\0' != *p );

	*count = tmpcount;

	//根据多少行，精确地分配内存
	myp = (char**)malloc(tmpcount * sizeof(char*));
	
	//如果前n个分配内存成功，第n+1个分配失败，要把前n个分配的内存释放掉
	if ( NULL == myp )
	{
		ret = -1;
		printf("func splitSting3() err:%d (tmpcount * sizeof(char*))", ret);
		goto END;
	}


	//如果分配成功则把1维指针全部置0，当二维指针分配错误时，前n个指针不为0，就释放掉；后n+1个为0，就不释放。
	memset(myp, 0, tmpcount * sizeof(char*));	

	///////////////////////////////////////////////
	//第二遍扫描，分配行
	tmpcount = 0;
	pTmp = p = buf1;
	int len = 0;

	do
	{
		p = strchr(p, c);
		if ( NULL != p )
		{
			if ( p - pTmp > 0 )	
			{
				len = p - pTmp + 1;
				myp[tmpcount] = (char*)malloc(len * sizeof(char));
				if ( NULL == myp[tmpcount] )
				{				

					ret = -1;
					printf("func splitSting3() err:%d (malloc(len * sizeof(char)))", ret);
					goto END;
				}

				strncpy(myp[tmpcount], pTmp, p-pTmp);
				myp[tmpcount][p-pTmp] = '\0';
				tmpcount++;
				pTmp = p = p + 1;
			}
		}
		else
			break;

	}while( '\0' != *p );


	////////////////////////////////////////////////////////
	//统一出口
	//如果出错，把资源统一释放
	////////////////////////////////////////////////////////
END:
	if ( 0 != ret)	//失败的情况
	{
		FreeMem2(&myp, count);
	}
	else
		*myp3 = myp;

	return 0;
}

//多级指针避免野指针
void FreeMem2(char*** p, int* count)
{
	char** myp = *p;
	int i = 0;

	if ( NULL == p || NULL == *p)
		return;

	myp = *p;

	if ( NULL == myp )
		return ;
	for ( i = 0; i < *count; i++ )
	{
		if( NULL != myp[i] )
			free(myp[i]);
	}
	if ( NULL != myp )
	{
		free(myp);
	}
	myp = NULL;	//把二级指针实参指向NULL

}
