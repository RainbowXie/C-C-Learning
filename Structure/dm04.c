# include <stdio.h>
# include <stdlib.h>
# include <string.h>


typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

void printTeacher(Teacher * array, int num);
void sortTeacher(Teacher* array, int num);
int createTeacher(Teacher** pT, int num);
void FreeTeacher(Teacher* p);

int main()
{
	int i = 0;
	int num = 3;
	int ret = 0;
	Teacher* pArray = NULL;

	ret = createTeacher(&pArray, num);	//在堆上分配内存
	if ( ret )
	{
		printf("func creatTeacher err:%d", ret);
		return ret;
	}

	for ( i = 0; i < num; i++ )
	{
		printf("Please input teacher's age:");
		scanf("%d", &(pArray[i].age));
	}

	//打印老师年龄
	printTeacher(pArray, num);

	//排序
	sortTeacher(pArray, num);
	printTeacher(pArray, num);
	
	FreeTeacher(pArray);

	return 0;
}

void printTeacher(Teacher * array, int num)
{
	int i = 0;
	for ( i = 0; i < num; i++ )
		printf("age:%d\n", array[i].age);
}

//排序
void sortTeacher(Teacher* array, int num)
{
	int i, j;
	Teacher tmp;
	for ( i = 0; i < num; i++ )
	{
		for ( j = i + 1; j < num; j++ )
		{
			if ( array[i].age > array[j].age )
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

//在堆上分配内存
int createTeacher(Teacher** pT, int num)
{
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);

	if ( NULL == tmp )
		return -1;
	*pT = tmp;	//二级指针形参去间接修改实参的值
	return 0;
}

void FreeTeacher(Teacher** p)
{
	if ( NULL != *p )
	{
		free(*p);
		*p = NULL;
	}
		

	return;
}
