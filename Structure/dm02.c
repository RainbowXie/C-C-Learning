# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//声明一个结构体类型
typedef struct _MyTeacher
{
	char	name[32];
	int	age;
	char	addr[128];
}Teacher;

void printfMyteach01(struct _MyTeacher t)
{
	printf("\nt.name:%s", t.name);
}

void printfMyteach02(struct _MyTeacher *t)
{
	printf("\nt->age:%d", t->age);
}

void copyTeacher(Teacher to, Teacher from);
void copyTeacher2(Teacher *to, Teacher *from);

//结构体赋值和实参形参赋值行为研究
int main()
{
	Teacher t1 = {"aaaa", 33, "bbbb"};
	Teacher t2, t3;
	t2 = t1;    //研究 = 操作下编译器的行为
	
	printf("t2.name:%s\n", t2.name);
	printf("t2->age:%d\n", t2.age);
    
    	//执行完这个函数后并没有把t1拷贝到t3 
    	copyTeacher(t3, t1);
    
   	printf("t3.name:%s\n", t3.name);
	printf("t3->age:%d\n", t3.age);

	copyTeacher2(&t3, &t1);
    
	printf("\nt3.name:%s", t3.name);
	printf("\nt3->age:%d", t3.age);
	
	getchar();
	return 0;
}

//结构体元素做函数参数的拷贝参数
void copyTeacher(Teacher to, Teacher from)
{
    to = from;
}

//结构体指针做函数参数的拷贝参数
void copyTeacher2(Teacher *to, Teacher *from)
{
    *to = *from;
}

