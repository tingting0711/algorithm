# Queue使用说明

> 头文件 && 命名空间

```c
#include<stdlib.h> 或 <cstdlib.h>
#include<queue>
```

> 定义与初始化

```
queue<type> q;               // q保存类型为type的对象，q为空
```

```
eg:
queue<int> q;               
queue<double> q;               
```

> 基本操作

1. 入队：q.push(x), 将x元素接到队列的末端；

   ``` 
   int x = 1; 
   queue<int> q;
   q.push_back(x);
   ```

2. 出队：q.pop(), 弹出队列的第一个元素，并不会返回元素的值；

3. 队首：q.front()，访问队首元素；

4. 队尾：q.back()，访问队尾元素；

5. 个数：q.size()，访问队中的元素个数；

   

## 优先队列

> 定义

```
priority_queue<Type, Container, Functional>

Type为数据类型， Container为保存数据的容器，Functional为元素比较方式。

如果不写后两个参数，那么容器默认用的是vector，比较方式默认用less，也就是优先队列是大根堆
```

> 基本操作

1. q.size();//返回q里元素个数
2. q.empty();//返回q是否为空，空则返回1，否则返回0
3. q.push(k);//在q的末尾插入k
4. q.pop();//删掉q的第一个元素
5. q.top();//返回q的第一个元素

> 举例
1. 大根堆

   ```
   priority_queue<int> p; // priority_queue<int, vector<int>, less<int> > p;
   p.push(1);
   p.push(2);
   p.push(3);
   p.push(4);
   for(int i=0;i<5;i++)
   {
     cout<<p.top()<<" ";
     p.pop();
   }
   ## 4 3 2 1
   ```

2. 小根堆

   ```
   priority_queue<int, vector<int>, greater<int> > p;
   p.push(1);
   p.push(2);
   p.push(3);
   p.push(4);
   for(int i=0;i<5;i++)
   {
     cout<<p.top()<<" ";
     p.pop();
   }
   ## 1 2 3 4
   ```


> 参考资料

1. https://blog.csdn.net/chao_xun/article/details/8037438
2. https://blog.csdn.net/xiaoquantouer/article/details/52015928 
3. https://blog.csdn.net/c20182030/article/details/70757660