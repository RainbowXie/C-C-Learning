#include <stdio.h>

type int ZHANGSAN;	//为int再取一个名字，ZHANGSAN等价于int

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}ST;

int main (void)
{
	int i = 10;	//等价于ZHANGSAN i = 10;
	ZHANGSAN j = 20;

	
	struct Student st;	//等价于ST st;
	struct Student *ps = &st;	//等价于ST* ps;
	ST st2;
	st2.sid = 200;
	printf("%d\n", st2.sid);
	return 0;
}
