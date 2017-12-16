#include <stdio.h>


int FindPos(int* a, int low, int high);
void QKSORT(int* a, int low, int high);

int main(void)
{
	int a[6] = {-10, 1, 0, 5, 4, 3};
	int i;

	QKSORT(a, 0, 5);	//第二个参数表示第一个元素的下标，第三个参数表示最后一个元素的下标。
	for (i = 0; i < 6; i++)
	{
		printf("%d\t", a[i]);
	}


	return 0;
}

void QKSORT(int* a, int low, int high)
{
	int pos;
	if ( low < high )
	{
		pos = FindPos(a, low, high);
		QKSORT(a, low, pos-1);
		QKSORT(a, pos+1, high);
	}
}

int FindPos(int* a, int low, int high)
{
	int val = a[low];

	while ( low < high )
	{
		while ( low < high && a[high] >= val )
			--high;
		a[low] = a[high];

		while ( low < high && a[low] <= val )
			++low;
		a[high] = a[low];
	}
	
	a[low] = val;

	return low;
}
