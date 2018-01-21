# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define DIM(a) (sizeof(a)/sizeof(*a))	//数组的长度除以数组第一个元素的长度

//求关键字在表中的位置
//一个入口，多个出口
int searchKeyTable(const char**, const int, const char*, int*);	//指针数组、字符串个数、关键字、位置
//char* table[] 做函数参数退化为 char**

int main(int argc, char* argv[], char** env)//env系统配置环境变量信息；argv是参数，argc是参数个数
{
	int pos = 0;
	int a[10];
	int i = 0;

	//指针数组，做函数参数退化为指针：char**
	//应用1：做菜单
	char* c_keyword[] = 
	{
		"while",
		"case",
		"static",
		"do"
	};

	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);

	printf("do:%d\n", pos);

	//作用2：命令行参数
	printf("****************Begin argv*****************\n");
	
	for ( i = 0; i < argc; i++ )
		printf("%s\n", argv[i]);

	printf("****************End argv*****************\n\n");
	
	printf("****************Begin env*****************\n");
	//最后一个数组为“/0”，通过/0 判断二维数组什么时候结束
	for ( i = 0; NULL != env[i]; i++ )
		printf("%s\n", env[i]);


	printf("****************End envv*****************\n");

	return 0;
}

int searchKeyTable(const char* table[], const int size, const char* key, int* pos)
{
	int rv = 0;
	int i = 0;
	int inum = 0;
	
	//证明table退化为指针了
	inum = sizeof(table) / sizeof(*table);

	if ( NULL == table || NULL == key || NULL == pos )
	{
		rv = -1;
		printf("func searchKeyTable:%d", rv);
		return rv;
	}

	for ( i = 0; i < size; i++ )
	{
		if ( !strcmp(key, table[i]) )
		{
			*pos = i;
			return rv;
		}
	}
	if ( i == size )
		*pos = -1;

	return rv;
}
