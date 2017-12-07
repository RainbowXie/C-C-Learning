//实现JAVA array方法
#include <stdio.h>
#include <stdbool.h>	//布尔类型
#include <stdlib.h>	//exit函数
#include <malloc.h>
#include <math.h>

//定义了一个数据类型
struct Arr
{
	int *pBase;	//存储数组第一个元素的地址
	int len;	//数组所能容纳的最大元素的个数
	int cnt;	//当前数组有效元素的个数
	int increment; 	//自动增长因子
};

void init_arr(struct Arr *, int);
bool append_arr(struct Arr *, int);	//追加
bool insert_arr(struct Arr *, int pos, int val);	//位置，插入元素；pos的值为第几个元素，插入到pos值之前。
bool delete_arr(struct Arr * pArr, int pos, int *pVal);	//用pVal返回删除的值
int get();
bool is_empty(struct Arr *);
bool is_full(struct Arr *);
void sort_arr(struct Arr*);
void show_arr(struct Arr *);
void inversion_arr(struct Arr* pArr);
find_val_arr()	//查找
deleteAll()	//删除数组内所有值为x的元素


int main(void)
{
	int i = 1, n = 1;
	int val;
	struct Arr arr;	//定义变量，分配内存。
	//当只定义，没有初始化时，结构体内元素存放的都是垃圾数字。

	init_arr(&arr, 10);	//结构体可以相互复制
	while(1)
	{
		if (append_arr(&arr, i))
		{
			i = i + pow(10, n);
			n++;
		}
		else
			break;
		if (n > 6)
			break;
	}
	insert_arr(&arr, 1, 99);
	//printf("%d\n", arr.len);
	
	show_arr(&arr);

	if ( delete_arr(&arr, 1, &val))
	{
		printf("删除成功！\n您删除的元素是：%d\n", val);
		show_arr(&arr);
	}
	else
		printf("删除失败！\n");
	
	inversion_arr(&arr);
	show_arr(&arr);

	sort_arr(&arr);
	show_arr(&arr);

	return 0;
}

void init_arr(struct Arr* pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int ) *length);

	if (NULL == pArr->pBase)	//分配地址时分配失败，会把NULL赋给pBase。判定是否分配内存成功。
	{
		printf("malloc fail!\n");
		exit(-1);	//终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}

	return;
}

void show_arr(struct Arr *pArr)
{
	int i;

	if ( is_empty(pArr)/*数组为空*/)	//pArr存放结构体变量的地址
		//提示用户数组为空
		printf("array is empty!\n");
	else
	{
		//输出数组有效内容
		for (i = 0; i < pArr->cnt; ++i)
			printf("%d  ", pArr->pBase[i]);	//pBase中存放的成员

		printf("\n");
	}
}

bool is_empty(struct Arr *pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}

bool append_arr(struct Arr *pArr, int val)	//val：要追加的成员
{
	//数组满时返回false
	if (is_full(pArr))
		return false;
	//不满时追加
	else
	{
		pArr->pBase[pArr->cnt] = val;

		++pArr->cnt;
		return true;
	}	
}

bool is_full(struct Arr *pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

bool insert_arr(struct Arr *pArr, int pos, int val)
{
	int i;
	//判断是否满、pos插入位置是否正确
	if (is_full(pArr))
		return false;
	if (pos < 1 || pos > pArr->cnt+1)
		return false;

	for (i = pArr->cnt-1; i >= pos-1; i--)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}

	pArr->pBase[pos-1] = val;
	++pArr->cnt;

	return true;
}

bool delete_arr(struct Arr * pArr, int pos, int *pVal)
{
	int i;
	if (is_empty(pArr))
		return false;
	if (pos < 1 || pos > pArr->cnt)
		return false;
	
	*pVal = pArr->pBase[pos-1];
	
	for (i = pos; i < pArr->cnt; i++)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}

	pArr->cnt--;

	return true;
	
}

void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt - 1;
	int t;

	while(i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr* pArr)
{
	int i, j, t;
	for (i = 0; i < pArr->cnt; ++i)	
	{
		for (j = i+1; j < pArr->cnt; j++)
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}	
	}
}
