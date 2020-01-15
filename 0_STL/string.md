# String使用说明

> 参考资料

- https://www.renfei.org/blog/introduction-to-cpp-string.html

> 头文件 && 命名空间

```c
#include<string>
```

> 定义与初始化

```
string str1;
```



> 运算符重载

1. 连接字符串： \+ , += 

``` c++
//需保证两个操作数至少有一个是string类型
"app" + "lication" //不合法
```

> 查找

```c++
string str;
cin >> str;

str.find("ab");//返回字符串 ab 在 str 的位置
str.find("ab", 2);//在 str[2]~str[n-1] 范围内查找并返回字符串 ab 在 str 的位置
str.rfind("ab", 2);//在 str[0]~str[2] 范围内查找并返回字符串 ab 在 str 的位置

//first 系列函数
str.find_first_of("apple");//返回 apple 中任何一个字符首次在 str 中出现的位置
str.find_first_of("apple", 2);//返回 apple 中任何一个字符首次在 str[2]~str[n-1] 范围中出现的位置
str.find_first_not_of("apple");//返回除 apple 以外的任何一个字符在 str 中首次出现的位置
str.find_first_not_of("apple", 2);//返回除 apple 以外的任何一个字符在 str[2]~str[n-1] 范围中首次出现的位置

//last 系列函数
str.find_last_of("apple");//返回 apple 中任何一个字符最后一次在 str 中出现的位置
str.find_last_of("apple", 2);//返回 apple 中任何一个字符最后一次在 str[0]~str[2] 范围中出现的位置
str.find_last_not_of("apple");//返回除 apple 以外的任何一个字符在 str 中最后一次出现的位置
str.find_last_not_of("apple", 2);//返回除 apple 以外的任何一个字符在 str[0]~str[2] 范围中最后一次出现的位置

//以上函数如果没有找到，均返回string::npos
cout << string::npos;
```



> 字串

```c++
str.substr(3); //返回 [3] 及以后的子串
str.substr(2, 4); //返回 str[2]~str[2+(4-1)] 子串(即从[2]开始4个字符组成的字符串)
```



> 替换

```c++
str.replace(2, 4, "sz");//返回把 [2]~[2+(4-1)] 的内容替换为 "sz" 后的新字符串
str.replace(2, 4, "abcd", 3);//返回把 [2]~[2+(4-1)] 的内容替换为 "abcd" 的前3个字符后的新字符串
```



> 插入

```c++
str.insert(2, "sz");//从 [2] 位置开始添加字符串 "sz"，并返回形成的新字符串
str.insert(2, "abcd", 3);//从 [2] 位置开始添加字符串 "abcd" 的前 3 个字符，并返回形成的新字符串
str.insert(2, "abcd", 1, 3);//从 [2] 位置开始添加字符串 "abcd" 的前 [2]~[2+(3-1)] 个字符，并返回形成的新字符串
```



> 追加

```c++
str += "aaa";
str.push_back('a');//在 str 末尾添加字符'a'
str.append("abc");//在 str 末尾添加字符串"abc"
```



> 删除

```c++
str.erase(3);//删除 [3] 及以后的字符，并返回新字符串
str.erase(3, 5);//删除从 [3] 开始的 5 个字符，并返回新字符串
```



> 交换

```c++
str1.swap(str2);//把 str1 与 str2 交换
```



>其他

```c++
str.size();//返回字符串长度
str.length();//返回字符串长度
str.empty();//检查 str 是否为空，为空返回 1，否则返回 0
str[n];//存取 str 第 n + 1 个字符
str.at(n);//存取 str 第 n + 1 个字符（如果溢出会抛出异常
```

