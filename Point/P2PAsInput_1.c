# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int PrintA(char**, int);
int Array(char**, int);

int main()
{
	int num = 0;

	//数组 数组中的每个元素是指针，指针数组
	char* myArray[] = {"aaaaaa", "cccc", "111111", "FFFFFFF"};
	num = sizeof(myArray)/sizeof(myArray[0]);
	
	PrintA(myArray, num);
	
	Array(myArray, num);
	PrintA(myArray, num);
	
}

//打印
int PrintA(char** myArray, int num)
{
	int i;

	for ( i = 0; i < num; i++ )
	{
		printf("%s\n", myArray[i]);
		printf("%s\n", *(myArray+i));
	}

	
	return 0;
}

//排序，改变的只是指针的指向
int Array(char** myArray, int num)
{
	int i, j;
	char* tmp = NULL;

	for ( i = 0; i < num; i++ )
	{
		for ( j = i; j < num; j++ )
		{
			if ( strcmp(myArray[i], myArray[j]) > 0)
			{
				tmp = myArray[i];	//交换的是数组元素，交换的是指针的值
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	
	}


	return 0;
}
