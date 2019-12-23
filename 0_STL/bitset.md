# Bitset使用说明

reference: https://blog.csdn.net/qll125596718/article/details/6901935

> 头文件 && 命名空间

```c
#include<bitset>
using std::bitset;
```

> 定义与初始化

```
bitset<n> b;                   // b有n位， 每位都为0

bitset<n> b(u);                // b是unsigned long 型的u的一个副本

bitset<n> b(s);                // b是string对象s中含有的位串的副本

bitset<n> b(s, pos, n);	       //b是s中从位置pos开始的n个位的副本
```

> 操作

1. b.any()                               //b中是否存在位置为1的二进制位？
2. b.none()                            //b中是否不存在位置为1的二进制位？
3. b.count()                           //b中置为1的二进制位的个数
4. b.size()                               //b中二进制位的个数
5. b[pos]                                //b
6. b.test(pos)                        //b
7. b.set()                                //b中所有位置为1
8. b.set(pos)                          //b
9. b.reset()                             //b
10. b.reset(pos)                      //b中所有位置为0
11. b.flip()                                //b中所有位置取反
12. b.flip(pos)                         //b
13. b.to_ulong()                      //
