# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int printArr(char myArray[10][30], int);
int findpos(char myArray[10][30], int, int);
int QuickSort(char myArray[10][30], int, int);

int main()
{
	int num = 8;
	char mybuf[30];
	char myArray[10][30] = {"aaaaa", "33333", "bbbbbbb", "AAAAAA", "1", "00001233", "FFFFF", "afafafaf"};
	
	//myArray：编译器只会关心，有10行，每行30列：即myArray+1往后跳30个字节，这就是多维数组名的本质。
	int len1 = sizeof(myArray);
	int len2 = sizeof(myArray[0]);
	int size = len1 = len2;

	printArr(myArray, num);
	QuickSort(myArray, 0, 7);
	printf("afterSort:\n");
	printArr(myArray, num);
    
	return 0;
}

//错误：
//问题的本质是：第二种内存模型的myArray+1和第一种内存模型的myArray+1不一样;
//指针的步长不一样，即指针所指向的内存空间的数据类型不一样
int printArr_err(char** myArray, int num)
{
	if ( NULL == myArray || 0 == num )
	        return -1;

	int i = 0;

	for ( ; i < num; i++ )
	{
		printf("%s\n", myArray[i]);	
	}

	return 0;
}

//这样传进来编译器会对形参做优化，至于怎么优化，不知道
int printArr(char myArray[10][30], int num)
{
	if ( NULL == myArray || 0 == num )
	        return -1;

	int i = 0;

	for ( ; i < num; i++ )
	{
		printf("%s\n", myArray[i]);	
	}

	return 0;
}

//交换的是内存块
//快排
int QuickSort(char myArray[10][30], int low, int high)
{
	int pos;	
	if ( low < high )
	{
		pos = findpos(myArray, low, high);
		QuickSort(myArray, low, pos-1);
		QuickSort(myArray, pos+1, high);
	}

	return 0;
}

int findpos(char myArray[10][30], int low, int high)
{	
	char val[30]; 
       	strcpy(val, myArray[low]); 
	
	while ( low < high )
	{
		while ( low < high && strcmp(myArray[high], val) >= 0 )
			high--;
		strcpy(myArray[low], myArray[high]);
		while ( low < high && strcmp(myArray[low], val) <= 0 )
			low++;
		strcpy(myArray[high], myArray[low]);
	}
	strcpy(myArray[low], val);

	return low;
}
