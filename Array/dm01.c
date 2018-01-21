# include <stdio.h>

int main()
{
	int i;

//定义数组指针变量原始版：
	int (*pArray)[5];	//直接定义一个指向数组的数组指针变量
	
//定义数组指针变量的方法1：
	typedef int (ArrayType)[5];  //定义了一个数据类型，数组数据类型
	ArrayType* pArray2;	//定义一个指针变量，指向一个数组，数组指针类型

//定义数组指针变量的方法2：
    typedef int (*PArrayType)[5];
    PArrayType pArray3; //分配一个指针变量
    
	
	ArrayType myArray;	//int myArray[5]，用类型定义变量
	int myArray2[5];	//相当于1级指针
	int myArray3[5];

	pArray = &myArray;	//相当于2级指针
	pArray2 = &myArray2;	
	pArray3 = &myArray3;

    printf("%d,%d\n", sizeof(pArray), sizeof(*pArray));
	printf("%d,%d\n", sizeof(pArray2), sizeof(*pArray2));
	printf("%d,%d\n", sizeof(pArray3), sizeof(*pArray3));
	for ( i = 0; i < 5; i++ ) 
	{
		myArray[i] = i + 1;
		(*pArray2)[i] = i + 1;
		(*pArray3)[i] = i + 1;
    }

	for ( i = 0; i < 5; i++ )
	{
		printf("%d ", (*pArray)[i]);
		printf("%d ", (*pArray2)[i]);
		printf("%d ", (*pArray3)[i]);
	}

	return 0;

}   
