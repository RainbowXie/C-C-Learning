# include <stdio.h>
//一维数组的退化，不知道有几个元素，要手动传进来
void printfArray1(int *array, int num)
{
	int i = 0;
	for (i=0; i<num ; i++)
	{
		printf("%d ", array[i]);
	}
}

//二维数组的退化：并不知道有几行，只知道a+1跳5×4个字节，要手动传进来。
void printfArray2(int (*a)[5], int num)
{
	int i, j;
    for ( i = 0; i < num; i++ )
	{
		for ( j = 0; j < 5; j++ )
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	return ;
}

//多维数组按一维数组答应，证明多维数组是线性存储
void printfArr3(int* array, int size)
{	
	int i;

	for ( i = 0; i < size; i++ )
	{
		printf("%d", array[i]);
	}

	return ;
}
int main()
{
	int a[3][5];
	int c[3][4][5];
	int i , j = 0;
	int tmp = 0;
	for ( i = 0; i < 3; i++ )
	{
		for ( j = 0; j < 5; j++ )
		{
			a[i][j] = tmp ++;
		}
	}
	
	printfArray2(a, 3);
	printfArr3((int *)a, 15);	//强制转换指针a的类型

	return 0;
}
