# include <stdio.h>
# include <stdlib.h>
# include <string.h>


typedef struct Teacher
{
	char name[64];
	char *aliasname;    //只分配了8个字节的指针空间，所指向的内存空间要手动分配
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
	ret = createTeacher(&pArray, num);	
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
	int i = 0;
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);

	if ( NULL == tmp )
		return -1;
	//分配完之后初始化	
	memset(tmp, 0, sizeof(Teacher) * num);
	
	//给结构体中的一级指针分配内存
	for (i = 0; i < num; i++ )
	    tmp[i].aliasname = (char*)malloc(sizeof(char) * 64);
	    
	*pT = tmp;
	return 0;
}

void FreeTeacher(Teacher** p, int num)
{	
	int i;
	if ( NULL == p )
		return;
	//释放结构体中分配的一级指针内存
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
