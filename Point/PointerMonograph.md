# 指针知识体系搭建
## 前言
先从整体上把握指针的知识体系。然后突破1级指针、二级指针、多级指针。

## 铁律1：指针是一种数据类型  	

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

            p++ = (unsigned char)p + sizeof(a);

结论：
:   指针的步长，根据所指内存空间类型来定。
	
注意：
:   建立指针指向谁，就把把谁的地址赋值给指针。图和代码和二为一。	
:   不断的给指针变量赋值，就是不断的改变指针变量（和所指向内存空间没有任何关系）。

### 实验
* 向NULL地址处copy数据
```C
void main()
{
    char* p1 = NULL;        //0x00000操作系统保护内存，不能往里面拷
    strcpy(p1,"abcdef");    //往指针p1所指向的内存空间拷数据
    
}
```
* 不断的改变指针的指向
```C
int main()
{
    char buf[128];  //栈上分配内存
    int i;
    char* p = NULL;
    char* p2 = NULL;
    strcpy(buf, "123456789");
    
    p = &buf[0];    //不断地修改p的值，相当于不断地改变指针的指向
    p = &buf[1];
    p = &buf[2];
    p = &buf[3];
    p = &buf[4];
    p = &buf[5];
    p = &buf[6];

    p2 = (char*)malloc(100);
    
    
    for ( i = 0; i < 10; i++)
        p1 = p2[i];
    return 0;
}
```
* 字面量
上例中的

        i = 0
放在哪？不知道。        

## 铁律2：间接赋值（*p）是指针存在的最大意义 
1. 两码事：指针变量和它指向的内存块变量
2. 条件反射：指针指向某个变量，就是把某个变量地址否给指针

### 间接赋值成立条件：3个条件 
1. 定义2个变量（通常一个实参，一个形参）
2. 建立关系，实参取地址赋给形参指针 
3.  *p形参去间接修改实参的值 

### 间接赋值的应用场景
三个条件的组合，分别产生三种很重要的语法现象
* 123都写在一个函数里面
* 12写在一个函数里面，3写在另一个函数里面
* 1写在一个函数里面，23写在另一个函数里面

### 间接赋值推论
在函数调用的时候
* 用1级指针形参，去间接修改了0级指针（实参）的值。
* 用2级指针形参，去间接修改了1级指针（实参）的值。
* 用3级指针形参，去间接修改了2级指针（实参）的值。
* 用n级指针形参，去间接修改了n-1级指针（实参）的值。


### 实验
#### 实验1：1级指针
```C
int getFileLen(int* p)
{
    *p = 40;    //p的值是a的地址，通过p接收a的地址间接修改a的值
    
    return 0;
}
int main()
{
    int a = 10;
    int* p = NULL;
    
    //修改a的值
    a = 20;     //直接修改
    p = &a;
    
    *p = 30;    //p的值是a的地址，*就像一把钥匙，通过地址找到一块内存空间，就间接地修改了a的值
    printf("a:%d\n", a);
    getFileLen(&a);
    printf("a:%d\n", a);
    return 0; 
}
```
#### 实验2：2级指针间接修改一级指针的值

```C
int getMem(char** p2)
{
    *p2 = 200;    //p2是p1的地址
    
    return 0;
}
int getMem2(char* p2)
{
    *p2 = 400;    //p2是p1的地址
    
    return 0;
}
int main()
{
    char* p1 = NULL;
    char** p2 = NULL;
    
    p1 = 0x11;
    p2 = 0x22;
    
    //直接修改p1的值
    p1 = 0x111;
    
    间接修改p1的值
    p2 = &p1;
    *p2 = 100;  //间接赋值  p2是p1的地址
    printf("p1:%d", p1);
    
    getMem(&p1);
    printf("p1:%d", p1);
    getMem2(&p1);
    printf("p1:%d", p1);
    
    return 0; 
}
```
这里getMem2()用的是1级指针，看上去执行也可以通过，但关键是用二级指针可以访问一级指针指向的值，如：
```C
void getMem(char** p2)
{
    **p2 = 100;
}
int main()
{   
    int p = 1;
    int* p1 = &p;
    getMem(&p1);
    printf("p:%c", p);
    
    return 0;
}

```

#### 实验4：
```C
int getMem(char** myp1, int* mylen1, char** myp2, int* mylen2)
{
    int ret = 0;
    char *tmp1, *tmp2;
    tmp1 = (char *)malloc(100);
    tmp2 = (char *)malloc(200);
    
    strcpy(tmp1, "1232341");
    strcpy(tmp2, "sfdggew");
    *mylen1 = strlen(tmp1);     //条件3
    *mylen2 = strlen(tmp2);
    
    *myp1 = tmp1;   //2级指针的间接赋值
    *myp2 = tmp2;   //2级指针的间接赋值
//myp1中放的是main函数中p1的地址，tmp1中存放的是一块内存空间的首地址；此时相当于
//p1 = tmp1
//通过*将该内存空间的首地址放入p1中。
    return ret;
}

int main()
{
    int ret = 0;
    char* p1 = NULL;    //条件1
    int len1 = 0;
    char* p2 = NULL;
    int len2 = 0;
    
    ret = getMem(&p1, &len1, &p2, &len2);   //条件2
    if ( 0 != ret )
    {
        printf("func getMem() err:%d\n", ret);
        return ret;
    }
    printf("p1:%s\n", p1);
    printf("p2:%s\n", p2);
    
    if ( NULL != p1 )
    {
        free(p1);
        p1 = NULL;
    }
    if ( NULL != p2 )
    {
        free(p2);
        p2 = NULL;
    }
    
    return ret;
}
```
#### 实验5：间接赋值的应用场景
```C
void main()
{
    //1 2 3这3个条件写在一个函数
    char from[128];
    char to[128] = {0};
    char* p1 = from;
    char* p2 = to;
    strcpy(from, "1234345tgdsf");
    while('\0' != *p1)
    {
        *p1 = *p2;
    }
    //1 2写在一块，3单独写在另一个函数里面 ==》函数调用
    //见上一个实验
    
    //1单独写，2 3写在一块 ==》C++会用
}

```



* 引申：函数调用时,用n指针（形参）改变n-1指针（实参）的值。
    * 改变0级指针（int iNum = 1）的值有2种方式
    * 改变1级指针（eg： char *p = 0x1111 ）的值，有2种方式
    * 改变2级指针的（eg： char **pp1 = 0x1111 ）的值，有2种方式
    * 函数调用时，形参传给实参，用实参取地址，传给形参，在被调用函数里面用*p，来改变实参，把运算结果传出来。
    * 指针作为函数参数的精髓。

## 铁律3：理解指针必须和内存四区概念相结合 
1. 主调函数 被调函数 
* 主调函数可把堆区、栈区、全局数据内存地址传给被调用函数
* 被调用函数只能返回堆区、全局数据
2. 内存分配方式
* 指针做函数参数，是有输入和输出特性的。

### 实验
#### 实验1：二级指针做输出
```C
//两种返回接口方法
int getMem(char** myp1)
{
    char *tmp1;
    tmp1 = (char *)malloc(100);
    strcpy(tmp1, "1232341");
    *myp1 = tmp1;
    
    return 0;
}
char* getMem2(int num)
{
    char* tmp1;
    tmp1 = (char *)malloc(num);
    strcpy(tmp1, "13343");
    
    return tmp1;
}

int main()
{
    int ret = 0;
    char* p1 = NULL;    
    
    ret = getMem(&p1);
    printf("p1:%s\n", p1);
    if ( NULL != p1 )
    {
        free(p1);
        p1 = NULL;
    }
    
    p1 = getMem2(100);      //分配100个字节
    printf("p1:%s\n", p1);
    if ( NULL != p1 )
    {
        free(p1);
        p1 = NULL;
    }
    
    return ret;
}
```
在被调用函数中分配内存，把分配的内存接口返回给主调函数。
在调用完成后要释放内存。


## 铁律4：应用指针必须和函数调用相结合（指针做函数参数） 
![定律](https://raw.githubusercontent.com/RainbowXie/C-C-Learning/master/Pic/PointerDiscipline_1.png)
## 铁律5：一级指针典型用法（指针做函数参数）
* 一级指针做输入
```
int showbuf(char *p)
int showArray(int *array, int iNum)
```
* 一级指针做输出
```
int geLen(char *pFileName, int *pfileLen);
```
理解
主调函数还是被调用函数分配内存
被调用函数是在heap/stack上分配内存

* 数组

        int a[10];
* 字符串
见字符串专题讲座

## 铁律6：二级指针典型用法（指针做函数参数）
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

## 铁律7： 三级指针输出典型用法
三级指针做输出
int getFileAllLine(char ***content, int *pLine); 
int getFileAllLine_Free(char ***content, int *pLine);
理解
主调函数还是被调用函数分配内存
被调用函数是在heap/stack上分配内存

## 铁律8：杂项，指针用法几点扩充
1）野指针 2种free形式
int getData(char **data, int *dataLen); 
int getData_Free(void *data);
int getData_Free2(void **data);
2）2次调用
主调函数第一次调用被调用函数求长度；根据长度，分配内存，调用被调用函数。
3）返回值char */int/char **
4）C程序书写结构
商业软件，每一个出错的地方都要有日志，日志级别

## 铁律9：一般应用禁用malloc/new




