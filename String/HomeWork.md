# 作业
### 1题：
有一个字符串开头或结尾含有n个空格，
    
    "   abcdefgdddd    "

欲去掉前后空格，返回一个新字符串。

* 要求1：请自己定义一个接口（函数），并实现功能；70分
* 要求2：编写测试用例。30分
	    
	    int trimSpace(char *inbuf, char *outbuf);  
<br />

### 2题：
有一个字符串

    "1a2b3d4z"，
    
要求写一个函数实现如下功能：
    
* 功能1：把偶数位字符挑选出来，组成一个字符串1。value；20分
* 功能2：把奇数位字符挑选出来，组成一个字符串2，value；20
* 功能3：把字符串1和字符串2，通过函数参数，传送给main，并打印。
* 功能4：主函数能测试通过。

        int getStr1Str2(char *souce, char *buf1, char *buf2); 

### 3题：
键值对（”key = value”）字符串，在开发中经常使用；

* 要求1：请自己定义一个接口，实现根据key获取value；40分
* 要求2：编写测试用例。30分
* 要求3：键值对中间可能有n多空格，请去除空格30分
* 注意：键值对字符串格式可能如下：
```C
“key1 = value1”
“key2 =       value2“         
“key3  = value3” 
“key4        = value4” 
“key5   =   “
“key6   =“
“key7   =   “

int getKeyByValude(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen);
int main()
{
    getKeyByValue(“key1 = valude1”, ” key1”, buf, &len);
}
```



