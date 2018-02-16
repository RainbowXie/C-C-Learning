# include <stdio.h>
# include <stdlib.h>
# include <string.h>


typedef struct Teacher
{
	int ID;
	char **StuName;	//StuName中装n个元素，用二级指针的三种内存模型中选一种保存
}Teacher;

int printTeacher(Teacher * pArray, int num);
void sortTeacher(Teacher* array, int num);
int createTeacher(Teacher** pT, int num);
void FreeTeacher(Teacher** p, int num);

int main()
{
	int i = 0, j = 0;
	int num = 3;
	int ret = 0;
	Teacher* pArray = NULL;
    
	/************************************/
	//创建结构体
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
		printf("Please input teacher's ID:");
		scanf("%d", &(pArray[i].ID));
		for ( j = 0; j < 3; j++ )
		{	
			printf("Please input teacher's %d StudentName:", j+1);
			scanf("%s", pArray[i].StuName[j]);
		}
	}
	/************************************/

	/************************************/
	//打印老师年龄
	printTeacher(pArray, num);
	/************************************/

	/************************************/
	//释放结构体
	FreeTeacher(&pArray, num);
	/************************************/
	return 0;
}

int createTeacher(Teacher** pT, int num)
{
	int j = 0, i = 0;
	Teacher* tmp = NULL;
	char** p = NULL;

	//分配结构体内存
	//ID 4字节
	//StuName 8字节
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);
	if ( NULL == tmp )
		return -1;

	//分配完之后初始化	
	memset(tmp, 0, sizeof(Teacher) * num);

	for ( j = 0; j < num; j++ )
	{
		//手动分配二级指针的第三种内存模型
		p = (char**)malloc(sizeof(char*) * 3);	//p中存放1个指针数组的首地址，数组中有3个指针

		for (i = 0; i < 3; i++ )
		{
			p[i] = (char*)malloc(sizeof(char) * 64);	//指针数组中的每个指针指向一个64字节的空间
		}
		tmp[j].StuName = p;	//把p中的数组首地址放入tmp[j].StuName中
	}
	*pT = tmp;

	return 0;
}

void FreeTeacher(Teacher** p, int num)
{	
	int i, j;
	if ( NULL == p )
		return;

	for ( i = 0; i < num; i++ )
	{
		//释放指针数组指向的3个空间
		if (NULL != (*p)[i].StuName)
		{
			for ( j = 0; j < 3; j++ )
				free((*p)[i].StuName[j]);

			(*p)[i].StuName = NULL;
		}
	}
	//释放结构体空间
	if ( NULL != *p )
		free(*p);
	*p = NULL;

	return;	
}

int printTeacher(Teacher* pArray, int num)
{
	int i, j;
	for ( i = 0; i < num; i++ )
	{
		printf("Teacher's ID:%d\n", pArray[i].ID);
		for ( j = 0; j < 3; j++ )
		{
			printf("Teacher %d's student %d:%s\n", pArray[i].ID, j+1, pArray[i].StuName[j]);
		}
	}

	return 0;
}
