#include <stdio.h>


typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}*PST, STU;	//PST等价于struct Student * ，PST是一个结构指针；ST代表struct Student.

int main (void)
{
	STU st;	//struct Student st1;

	PST ps = &st;	//sturct Student* ps = &st;

	ps->sid = 99;
	printf("%d\n", ps->sid);
	
	return 0;
}
