﻿

# 链表  
链表的重要性：是数据结构的基础课。  
预备知识：typede为已有的数据类型或结构体重新去一个名字。
离散存储：（链表）

## 1. 定义：
+ n个节点离散分配；  
+ 彼此通过指针相连；  
+ 每个节点只有一个前驱节点，每个节点只有一个后续节点，前驱没有前驱节点，尾节点没有后续节点。  

##2. 专业术语：
* 首节点（node）：
    * 第一个有效节点
* 头结点：
    * **头节点数据类型和首节点类型一样**
    * **第一个有效节点之前的哪个节点**
    * **头节点不存放有效数据**
    * **加上一个头结点的目的主要是方便一些对链表的算法。**
* 头指针：
    * 指向头结点的指针变量
* 尾节点：
    * 最后一个有效节点
* 尾指针：
    * 指向尾节点的指针变量  

##3. 确定链表：  
* 如果希望通过一个函数来对链表进行处理，我们至少需要接收链表的哪些参数？
确定一个链表需要只需要一个参数，即头指针，通过头指针我们可以推算出链表的其他所有参数信息。

tags: 数据结构 链表