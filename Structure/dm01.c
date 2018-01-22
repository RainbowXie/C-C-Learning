# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//定义一个结构体类型

//定义了一个数据类型，固定大小内存块的别名，还没有分配内存
//类型重定义

typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher2;

//定义结构体方法
//第一种：
struct Student
{

}s1, s2;
//第二种：
struct 
{

}s3, s4;
//////////////////////////
//初始化结构体变量方法
//第二种
struct Dog
{
	char name[32];
	int age;
	char addr[128];
}d1 = {"dog1", 1, "ddd1"};

//第三种
struct
{
	char name[32];
	int age;
	char addr[128];
}d2 = {"dog2", 2, "ddd2"};


int main()
{
	struct Teacher t1; //告诉C编译器给我分配内存
	Teacher2 t2;
	//第一种
	struct Teacher t3 = {"name3", 33, 003};

	strcpy(t1.name, "name1");
	printf("t1.name:%s\n", t1.name);


	return 0;
}
