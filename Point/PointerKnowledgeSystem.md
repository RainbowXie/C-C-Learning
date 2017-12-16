# 指针知识体系搭建
## 前言
先从整体上把握指针的知识体系。然后突破1级指针、二级指针、多级指针。
## 指针强化

### 铁律1：指针是一种数据类型  	

1. 指针也是一种变量，占有内存空间，用来保存内存地址。
测试指针变量占有内存空间大小

2.  *p操作内存  
* 在指针声明时， *号表示所声明的变量为指针

* 在指针使用时， *号表示操作指针所指向的内存空间中的值
	    * *p相当于通过地址（p变量的值）找到一块内存；然后操作内存
	    
	    * *p放在等号的左边赋值（给内存赋值）
	    
	    * *p放在等号的右边取值（从内存获取值）  

3. 指针变量和它指向的内存块是两个不同的概念
    * //含义1 给p赋值p=0x1111;  
    只会改变指针变量值，不会改变所指的内容；p = p +1; //p++

    * //含义2 给*p赋值*p='a';   
    不会改变指针变量的值，只会改变所指的内存块的值  

    * //含义3 =左边*p 表示给内存赋值，=右边*p 表示取值     
    **含义不同切记！**
    
    * //含义4 =左边char *p 
    
    * //含义5 保证所指的内存块能修改
    
4. 指针是一种数据类型，是指它指向的内存空间的数据类型  
    * 含义1：指针步长（p++），根据所致内存空间的数据类型来确定

            p++=(unsigned char )p+sizeof(a);

结论：
:   指针的步长，根据所指内存空间类型来定。
	
注意：
:   建立指针指向谁，就把把谁的地址赋值给指针。图和代码和二为一。	
:   不断的给指针变量赋值，就是不断的改变指针变量（和所指向内存空间没有任何关系）。

### 铁律2：间接赋值（*p）是指针存在的最大意义 
1. 两码事：指针变量和它指向的内存块变量
2. 条件反射：指针指向某个变量，就是把某个变量地址否给指针
3.  *p间接赋值成立条件：3个条件 
* 2个变量（通常一个实参，一个形参）
* 建立关系，实参取地址赋给形参指针 
*  *p形参去间接修改实参的值 
```C
int iNum = 0; //实参
int *p = NULL;
p = &iNum;
iNum = 1;
*p = 2 ; //通过*形参 == 间接地改变实参的值
*p成立的三个条件：
```
* 引申：函数调用时,用n指针（形参）改变n-1指针（实参）的值。
    * 改变0级指针（int iNum = 1）的值有2种方式
    * 改变1级指针（eg char *p = 0x1111 ）的值，有2种方式
    * 改变2级指针的（eg char **pp1 = 0x1111 ）的值，有2种方式
    * 函数调用时，形参传给实参，用实参取地址，传给形参，在被调用函数里面用*p，来改变实参，把运算结果传出来。
    * 指针作为函数参数的精髓。

### 铁律3：理解指针必须和内存四区概念相结合 
1）主调函数 被调函数 
a)主调函数可把堆区、栈区、全局数据内存地址传给被调用函数
b)被调用函数只能返回堆区、全局数据
2）内存分配方式
a)指针做函数参数，是有输入和输出特性的。

### 铁律4：应用指针必须和函数调用相结合（指针做函数参数） 
编号	指针函数参数
内存分配方式（级别+堆栈）	主调函数
实参	被调函数
形参	备注

01	1级指针
（做输入）	堆	分配	使用	一般应用禁用
		栈	分配	使用	常用
		Int showbuf(char *p);   
int showArray(int *array, int iNum)
02	1级指针
（做输出）	栈	使用	结果传出	常用
		int geLen(char *pFileName, int *pfileLen);
03	2级指针
（做输入）	堆	分配	使用	一般应用禁用
		栈	分配	使用	常用
		int main(int arc ,char *arg[]); 指针数组
int shouMatrix(int [3][4], int iLine);二维字符串数组
04	2级指针
（做输出）	堆	使用	分配	常用，但不建议用，转化成02
		int getData(char **data, int *dataLen);
Int getData_Free(void *data);
Int getData_Free(void **data); //避免野指针 
05	3级指针
（做输出）	堆	使用	分配	不常用
		int getFileAllLine(char ***content, int *pLine); 
int getFileAllLine_Free(char ***content, int *pLine);

指针做函数参数，问题的实质不是指针，而是看内存块，内存块是1维、2维。
1）如果基础类int变量，不需要用指针；
2）若内存块是1维、2维。

### 铁律5：一级指针典型用法（指针做函数参数）
一级指针做输入
int showbuf(char *p)
int showArray(int *array, int iNum)
一级指针做输出
int geLen(char *pFileName, int *pfileLen);
理解
主调函数还是被调用函数分配内存
被调用函数是在heap/stack上分配内存

### 铁律6：二级指针典型用法（指针做函数参数）
二级指针做输入
int main(int arc ,char *arg[]); 字符串数组
int shouMatrix(int [3][4], int iLine);
二级指针做输出
int Demo64_GetTeacher(Teacher **ppTeacher);
int Demo65_GetTeacher_Free(Teacher **ppTeacher);
int getData(char **data, int *dataLen);
Int getData_Free(void *data);
Int getData_Free2(void **data); //避免野指针
理解
主调函数还是被调用函数分配内存
被调用函数是在heap/stack上分配内存

### 铁律7： 三级指针输出典型用法
三级指针做输出
int getFileAllLine(char ***content, int *pLine); 
int getFileAllLine_Free(char ***content, int *pLine);
理解
主调函数还是被调用函数分配内存
被调用函数是在heap/stack上分配内存

### 铁律8：杂项，指针用法几点扩充
1）野指针 2种free形式
int getData(char **data, int *dataLen); 
int getData_Free(void *data);
int getData_Free2(void **data);
2）2次调用
主调函数第一次调用被调用函数求长度；根据长度，分配内存，调用被调用函数。
3）返回值char */int/char **
4）C程序书写结构
商业软件，每一个出错的地方都要有日志，日志级别

### 铁律9：一般应用禁用malloc/new




