# Deque使用说明

> 特性

- 双端队列
- 头尾插入元素十分迅速， 中间插入较慢（移动其他元素）
- https://www.cnblogs.com/linuxAndMcu/p/10260124.html

> 头文件 && 命名空间

```c
#include<deque>
using std::deque;
```

> 定义与初始化

```
deque<type> v1;               // v1保存类型为type的对象，v1为空

deque<type> v2(size);         // v2保存类型为type，容量为size的对象

deque<type> v3(size,value);   // v3保存类型为type，容量为size，初始值为value的对象

deque<type> v4(mydeque);     // v4是myvector的一个副本

deque<type> v5(first,last);   // 用迭代器first和last之间的元素创建v5
```

```
eg:
deque<int> v1;               
deque<int> v2(10);
deque<int> v3(10, 0);
deque<int> v4(v3);
deque<int> v5(arr+1, arr+5);  //int arr[5] = {1,2,3,4,5,6,7,8,9};
```

> 增加

0. void push_front(const T& x):向量头部增加一个元素X

1. void push_back(const T& x) : 向量尾部增加一个元素X

2. iterator insert(iterator it,const T& x) : 向量中迭代器指向元素前增加一个元素x


3. iterator insert(iterator it,int n,const T& x) : 向量中迭代器指向元素前增加n个相同的元素x

> 删除

1. iterator erase(iterator it) : 删除向量中迭代器指向元素
2. iterator erase(iterator first,iterator last) : 删除向量中[first,last)中元素
3. void pop_back() : 删除向量中最后一个元素
4. void pop_front() : 删除向量中第一个元素
5. void clear() : 清空向量中所有元素

> 遍历

1. v.begin()
2. v.end()
3. v[i] : 返回v中位置为i的元素
4. v.at[i] : 返回位置为 i 的元素，有越界检查
5. v. front() : 返回向量中第一个元素的引用
6. v.back() : 返回向量中最后一个元素的引用

> 其他

1. v.empty() : 若为空只返回true，否则返回false
2. v.size() : 返回对象中元素的总个数
3. =, ==, !=, <, >, <=, >=  : 保持原有含义
4. reverse(v.begin(), v.end()) : 翻转对象
5. v1.swap(v2) : 交换两向量，v1与v2类型须一致