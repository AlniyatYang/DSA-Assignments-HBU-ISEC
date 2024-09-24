# 单链表练习 20240924

## 功能

1. 初始化
2. 指定位置插入新元素
3. 按照索引返回元素
4. 按照元素数值返回元素
5. 按照索引产出对应的元素
6. 按照元素数值删除对应的元素

## 代码说明

采用C++编写

单链表相关联的操作集为自己独立编写，main主函数调试界面使用AI辅助完成

### C++特性记录

C语言声明结构体：

```c
typedef struct Node{

}Node;
```

在C++特性中可以直接简写为：

```c++
struct Node{

};
```

### 创建、释放节点

C

```c
#include <stdlib.h>
Node* H = (Node*)malloc(sizeof(Node));
free(H);
```

C++

```c++
Node* H = new Node;
delete H;
```

