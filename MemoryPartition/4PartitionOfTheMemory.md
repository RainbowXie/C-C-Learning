# 内存四区专题讲座
## 数据类型本质分析
### 数据类型概念
* “类型”是对数据的抽象 
* 类型相同的数据有相同的表示形式、存储格式以及相关的操作 
* 程序中使用的所有数据都必定属于某一种数据类型 
![数据类型](https://raw.githubusercontent.com/RainbowXie/C-C-Learning/master/Pic/Pic2.png)

### 数据类型的本质思考

思考数据类型和内存有关系吗？
C/C++为什么会引入数据类型？

### 数据类型的本质 

* 数据类型可理解为创建变量的模具（模子）；是固定内存大小的别名。
* 数据类型的作用：编译器预算对象（变量）分配的内存空间大小
* 程序举例，如何求数据类型的大小sizeof(int *)
* 请问：数据类型可以有别名吗？数据类型可以自定义吗？

### 数据类型大小 
```C
int main()
{
    int a = 10;
    int b[10] ;
    
    printf("b:%d, b+1:%d, &b:%d, &b+1 \n", b, b+1, &b, &b+1);
    //b:0x7ffd31023db0, b+1:0x7ffd31023db4, &b:0x7ffd31023db0, &b+1:0x7ffd31023dd8 
    //b，&b所代表的数据类型不一样
    //b代表数组首元素的地址
    //&b代表整个数组的地址
    printf("int a:%d \n", sizeof(a));       //4
    printf("int a:%d \n", sizeof(int *));   //8
    printf("int b:%d \n", sizeof(b));       //40
    printf("int b:%d \n", sizeof(b[0]));    //4
    printf("int b:%d \n", sizeof(*b));      //4

    getchar();
    return 0;
} 
//sizeof是操作符，不是函数；sizeof测量的实体大小为编译期间就已确定
```


### 数据类型别名
* 数据类型可以理解为固定大小内存块的别名，请问数据类型可以起别名吗？

```C

typedef struct Teacher
{
    char name[4];
    int age;
}Teacher;

typedef int u32

int main()
{
	Teacher t1;
	printf("Teacher:%d \n", sizeof(Teacher));
	printf("u32:%d \n", sizeof(u32));
	printf("u8:%d \n", sizeof(u8));
	
	getchar();
	return 0;
}
```
### 数据类型的封装
1. void的字面意思是“无类型”，void *则为“无类型指针”，void *可以指向任何类型的数据。

2.   
    * 用法1：数据类型的封装
    
            int InitHardEnv(void **handle);

     典型的如内存操作函数memcpy和memset的函数原型分别为
    ```
    void * memcpy( void *dest, const void *src, size_t len );
    void * memset ( void * buffer, int c, size_t num ); 
    ```
    
    * 用法2：void修饰函数返回值和参数，仅表示无。
        * 如果函数没有返回值，那么应该将其声明为void型
        * 如果函数没有参数，应该声明其参数为void

        ```
    void function(void)
    {
            return 1;
    }
    ```
    
3. void指针的意义
    C语言规定只有相同类型的指针才可以相互赋值
    * void*指针作为左值用于“接收”任意类型的指针
    * void*指针作为右值赋值给其它指针时需要强制类型转换
    ```
    void *p1 = NULL;
    char *p2 =NULL; 
    p2 = (char *)malloc(sizoeof(char)*20); //malloc返回的类型是void*
    p1 = &p2;    //p1是void*类型，可以把任何类型赋给p1
    ```
    
4. 不存在void类型的变量
      C语言没有定义void究竟是多大内存的别名

        void a  //不知道如何分配内存
        
5. 扩展阅读《void类型详解.doc》

### 数据类型总结与扩展

1. 数据类型本质是固定内存大小的别名；是个模具，c语言规定：通过数据类型定义变量。
2. 数据类型大小计算（sizeof）
3. 可以给已存在的数据类型起别名typedef
4. 数据类型封装概念（void 万能类型）

### 思考
#### 思考1：
C一维数组、二维数组有数据类型吗？int array[10]。 
若有，数组类型又如何表达？又如定义？
若没有，也请说明原因。

抛砖：数组类型，压死初学者的三座大山
1. 数组类型
2. 数组指针
3. 数组类型和数组指针的关系

#### 思考2：
C语言中，函数是可以看做一种数据类型吗？
若是，请说明原因

并进一步思考：函数这种数据类型，能再重定义吗？
若不是，也请说明原因。


## 变量本质分析
### 变量概念
概念：
:   既能读又能写的内存对象，称为变量；若一旦初始化后不能修改的对象则称为常量。

变量定义形式：
|类型|  标识符, 标识符, … , 标识符 ; |
|:---:|:---:|

例如：
```
    int   x ;
	int   wordCut ,  Radius ,  Height  ;  
	double   FlightTime ,  Mileage ,  Speed  ; 
```


### 变量本质 
1. 程序通过变量来申请和命名内存空间 

        int a = 0
2. 通过变量名访问内存空间
（一段连续）内存空间的别名（是一个门牌号） 

3. 修改变量有几种方法？
    1. 直接
    2. 间接。内存有地址编号，拿到地址编号也可以修改内存；于是横空出世了！（编程案例）  
    
4. 内存空间可以再取给别名吗？

5. 数据类型和变量的关系
    通过数据类型定义变量

### 总结及思考题
1. 对内存，可读可写；

2. 2通过变量往内存读写数据；

3. 不是向变量读写数据，而是向变量所代表的内存空间中写数据。问：变量跑哪去了？

4. 思考1：变量三要素(名称、大小、作用域)，变量的生命周期？ 
5. 思考2：C++编译器是如何管理函数1，函数2变量之间的关系的？

====》引出两个重要话题：

* 内存四区模型
* 函数调用模型

**重要实验：**
```
int  main333()
{
	//
	//2种方法，通过变量直接操作内存
	//通过内存编号操作内存

	int i = 0;

	printf("&i:%d\n", &i);

	*((int *)(1245024)) = 10;
	printf("i:%d", i);
	printf("hello....\n");
	getchar();
	return 0;
}
```
## 程序的内存四区模型
### 内存四区的建立流程
![内存四区](https://raw.githubusercontent.com/RainbowXie/C-C-Learning/master/Pic/Pic1.png)

* 流程说明
1. 操作系统把物理硬盘代码load到内存
2. 操作系统把c代码分成四个区
3. 操作系统找到main函数入口执行


### 各区元素分析
|分区|功能|
|:---:|:---|
|栈区(stack)|由编译器自动分配释放，存放函数的参数值，局部变量的值等|
|堆区(heap)|一般由程序员分配释放（动态内存申请与释放），若程序员不释放，程序结束时可能由操作系统回收|
|全局区（静态区）(static)|全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域，未初始化的全局变量和未初始化的静态变量在相邻的另一块区域，该区域在程序结束后由操作系统释放|
|常量区|字符串常量和其他常量的存储位置，程序结束后由操作系统释放|
|程序代码区|存放函数体的二进制代码|

### 实验：

#### 实验1：
```C
char* getStr1()
{
    char* p1 = "abcdefg2";
    return p1;
}
 
char* getStr2()
{
    char* p2 = "abcdefg2";
    return p2;
}

int main()
{
        char* p1 = NULL;
        char* p2 = NULL;
        
        p1 = getStr1();
        p2 = getStr2();

        printf("p1:%s, p2:%s\n", p1, p2);
        printf("p1:%p, p2:%p\n", p1, p2);

        return 0;
}
```
执行到18行时：
![静态存储区内存四区图](https://raw.githubusercontent.com/RainbowXie/C-C-Learning/master/Pic/MemoryPartition_1.png)

当18行运行完毕，栈中<font color = "red">p1</font>就会释放掉，只剩下p1指向全局区。

![静态存储区内存四区图2](https://raw.githubusercontent.com/RainbowXie/C-C-Learning/master/Pic/MemoryPartition_2.png)

19行执行完毕时：
![静态存储区内存四区图3](https://raw.githubusercontent.com/RainbowXie/C-C-Learning/master/Pic/MermoryPartition_3.png)
由于p1和p2的字符串相同，c编译器会对代码做词法分析、语法分析、句法分析，然后对代码做优化，p1和p2指向统一块内存区。

执行结果：
```
p1:abcdefg2, p2:abcdefg2
p1:0x0062c, p2:0x40062c

```
#### 实验2：
```C
char* getMem(int num)
{
    char* p1 = NULL;
    p1 = (char*)malloc(sizeof(char) * num);

    if (NULL == p1) 
            return NULL;

    return p1; 
}

char* getMem2()
{
    char buf[64];       //临时变量，栈区存放
    strcpy(buf, "123456789");
    printf("buf:%s\n", buf);
    return buf;         //把内存块首地址返回给tmp
}

int main()
{
    char* tmp = NULL;
    tmp = getMem(10);

    if ( NULL == tmp)
            return 0;
    strcpy ( tmp, "111222");        //向tmp所指向的内存空间中复制数据
    tmp = getMem2();
    printf("tmp:%s", tmp);
}
```

* 存放位置
    * 堆：char * s1 = "Hellow Word"；
    是在编译时就确定的；
    * 栈：char s1[] = "Hellow Word"；
    是在运行时赋值的；用数组比用指针速度要快一些，因为指针在底层汇编中需要用edx寄存器中转一下，而数组在栈上直接读取。

* 指针指向谁，就把谁的地址赋给指针
* 指针变量和他所指向的内存空间变量是两个不同的概念

* 理解指针的关键是内存

## 函数调用模型

### 基本原理：
![基本原理1](https://raw.githubusercontent.com/RainbowXie/C-C-Learning/master/Pic/fundamental.png)
![基本原理2](https://raw.githubusercontent.com/RainbowXie/C-C-Learning/master/Pic/fundamental2.png)

### 内存四区模型和函数调用模型变量传递分析

1. 一个主程序有n函数组成，c++编译器会建立有几个堆区？有几个栈区？

略
2. 函数嵌套调用时，实参地址传给形参后，C++编译器如何管理变量的生命周期？

[分析]：函数A，调用函数B，通过参数传递的变量（内存空间能用吗？）

[答]：

* main函数中可以在栈\堆\全局区分配内存，可以被fa、fb使用。
* fb申请的内存，可以被main使用吗？
    * fb中在栈上分配的内存，不能被fa和main函数使用
    * fb中malloc（堆）的内存，可以被main和fa函数使用
    * fb中全局区分配“abcdefg”，内存可以被fa和main函数使用

### 提示：学好C语言的关键 
建立正确程序运行图是学好c的关键！！！

### 如何建立正确的程序运行内存布局图

1. 内存四区模型&函数调用模型

2. 函数内元素 
    1. 深入理解数据类型和变量“内存”属性
    2. 一级指针内存布局图( int  *, char  * )
    3. 二级指针内存布局图( int **, char **)

3. 函数间
    1. 主调函数分配内存，还是被调用函数分配内存
    2. 主调函数如何使用被调用函数分配的内存（技术关键点：指针做函数参数）
======》学习指针的技术路线图

## 内存四区强化训练
1. 全局区训练
    * char *p1= “abcdefg”; 
2. 堆栈区生命周期训练
    * char p1[]= “abcdefg”;
    * 返回基本类型
    * 返回非基本类型
3. 堆栈属性训练
    * 测试heap生长方向
    * 测试stack生长方向
        * Heap、stack生长方向和内存存放方向是两个不同概念
    * 野指针
            * Malloc得到指针释放问题测试
            * free(p)
            * free(p+1)，深入理解 
        
* 野指针产生的原因：
指针变量和它所指向的内存空间变量是两个不同的概念
释放了指针所指的内存空间，但是指针本身没有重置成NULL，造成释放的时候，通过
    
            if (p != NULL)
重复释放。
* 避免方法：
    1. 定义指针的时候初始化成null
    2. 释放指针所指向的内存空间后，把指针重置成NULL。


### 实验
#### 实验1：
```C
int main()
{
        int a;
        int b;
        char buf[128];  //编译期间已经确定buf所代表的内存空间的标号就已经定义下来了。
        printf("&a:%p, b:%p\n", &a, &b);

        return 0;
}
```
* a先入栈，b后如栈。若a的地址比b的地址大，说明向下生长；若a的地址比b的地址小，说明向上生长。
* 不管栈开口向上向下，buf的内存地址buf+1，永远是向上的。

## 作业强化
### 训练1
划出内存四区 
```C
void main()
{
	char buf[100];
	//byte b1 = new byte[100];
	int a = 10; //分配4个字节的内存 栈区也叫临时区
	int *p;//分配4个字节的内存
	p = &a; //cpu执行的代码，放在代码区
	*p = 20; //20放在全局区，p放在栈

	char *p2 = NULL; //分配4个字节的内存 栈区也叫临时区
	p2 = (char *)malloc(100); //内存泄露概念
	if (p2 != NULL)
	{
		free(p2);
	}
	
	system("pause");
}
```

### 训练2
全局区代码测试
```C
char * getstring1()
{
	char *p1 = "abcde";
	return p1;
}

char * getstring2()
{
	char *p2 = "abcde";
	return p2;
}

void main()
{
	int i= 0;

	//指针指向谁就把谁的地址赋给指针变量。
	char *p1 = getstring1();
	char *p2 = getstring2();
	char *******    p3 = NULL; //p3 是个变量

	//指针变量和它所执行的内存空间变量是两个不同的概念
	strcmp(p1, p2);

	system("pause");
}
```
### 训练3  
划出内存四区
```C
void main()
{
	char buf[100];
	//byte b1 = new byte[100];
	int a = 10; 
	int *p;
	p = &a; 

	*p = 20; //
	char *p2 = NULL; 
	p2 = (char *)malloc(100); //内存泄露概念
	if (p2 != NULL)
	{
		free(p2);
		//p2 = NULL;  若不写,实验效果,分析原因
	}
	if (p2 != NULL)
		free(p2);

	system("pause");
}
```
### 训练4

```C
double x = 20;
int main()
{
    static double y = 50;
    int a = 10;
    int b = 20;
    int *p = &a;
    *p = b;
    int* num = (int*)malloc(sizeof(int)*5);
    int i;
    
    for ( i = 0; i < 5; i++ );
        num[i] += 1;
        
    char* c1 = "haha";
    char* c2 = "haha";
    char* c3 = "hello";
    
    free(num);
    num = NULL;
    
    return 0; 
}

```