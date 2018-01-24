# include <stdio.h>
# include <stdlib.h>
# include <string.h>


typedef struct Teacher
{
	char name[64];
	char **StuName;	//StuName中装n个元素，用二级指针的三种内存模型中选一种保存
	int age;
	int id;
}Teacher;

void printTeacher(Teacher * array, int num);
void sortTeacher(Teacher* array, int num);
int createTeacher(Teacher** pT, int num);
void FreeTeacher(Teacher** p, int num);

int main()
{
	int i = 0;
	int num = 3;
	int ret = 0;
	Teacher* pArray = NULL;
    
	/************************************/
	ret = createTeacher(&pArray, num);	//在堆上分配结构体数组
	if ( ret )
	{
	    printf("func createTeacher err:%d", ret);
	    return ret;
	}
	/************************************/
	
	/************************************/
    	//键盘输入数据
	for ( i = 0; i < num; i++ )
	{
		printf("Please input teacher's age:");
		scanf("%d", &(pArray[i].age));
		
		printf("Please input teacher's name:");
		scanf("%s", pArray[i].name);
		
		printf("Please input teacher's aliasname:");
		scanf("%s", pArray[i].aliasname);		
	}
	/************************************/

	/************************************/
	//打印老师年龄
	//printTeacher(pArray, num);
	/************************************/

	/************************************/
	FreeTeacher(&pArray, num);
	/************************************/
	return 0;
}

int createTeacher(Teacher** pT, int num)
{
	int i = 0, j = 0;
	Teacher* tmp = NULL;
	char** p = NULL;

	tmp = (Teacher*)malloc(sizeof(Teacher) * num);

	if ( NULL == tmp )
		return -1;
	//分配完之后初始化	
	memset(tmp, 0, sizeof(Teacher) * num);

	//手动分配二级指针的第三种内存模型
	p = (char*)malloc(sizeof(char*) * 3);	//p中存放1个指针数组的首地址，数组中有3个指针
	for (i = 0; i < num; i++ )
	{
		p[i] = (char*)malloc(sizeof(char) * 64)//指针数组中的每个指针指向一个64字节的空间
	}

	*pT = tmp;
	return 0;
}

void FreeTeacher(Teacher** p, int num)
{	
	int i;
	if ( NULL == p )
		return;

	for ( i = 0; i < num; i++ )
	{
		if (NULL != (*p)[i].aliasname)
		{
			free((*p)[i].aliasname);
			(*p)[i].aliasname = NULL;
		}
	}
	if ( NULL != *p )
		free(*p);
	*p = NULL;

	return;	
}
