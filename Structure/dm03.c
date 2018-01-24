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
Teacher* createTeacher(int num);
void FreeTeacher(Teacher* p);

int main()
{
	Teacher Array[3];	//在栈上分配内存
	
	int i = 0;
	int num = 3;
	Teacher* pArray = NULL;

	pArray = createTeacher(num);	//在堆上分配内存

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
Teacher* createTeacher(int num)
{
	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher) * num);

	if ( NULL == tmp )
		return NULL;

	return tmp;
}

void FreeTeacher(Teacher* p)
{
	if ( NULL != p )
		free(p);

	return;
}
