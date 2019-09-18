# STL
- vector : 变长数组，倍增思想
- pair
- string : 字符串
- queue : push(), front(), pop()
- priority_queue : 
- stack : 栈 push(), top(), pop()
- deque : 双端队列
- set, map, multiset, multimap : 基于平衡二叉树(红黑树)，动态维护有序序列
- unordered_set, unordered_map, unordered_multiset, unordered_multimap : 基于哈希表
- bitset : 压位

- http://www.cplusplus.com/

## vector

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
  #定义
	vector<int> a;
	vector<int> a[10];
	vector<int> a(10);
	vector<int> a(10, -3);
	#函数
	a.size();  O(1)
	a.empty();
	a.clear();
	a.front();
	a.back();
	a.push_back();
	a.pop_back();
	#遍历
  for(int i = 0; i < a.size(); i++)cout<<a[i]<<" ";
  for(vector<int>::iterator i = a.begin(); i != a.end(); i++)cout<<*i<<" ";
  for(auto i = a.begin(); i != a.end(); i++)cout<<*i<<" ";
  for(auto x : a)cout<<x<<" ";
  #支持比较运算，按字典排序
}
```

系统为某一程序分配空间所需时间与空间大小无关，与申请次数有关。

## pair

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	pair<int, string>p;
	p.first;
	p.second;
	#支持比较运算，以first为第一关键字，second为第二关键字(字典序)
	
	#初始化
	p = make_pair(10, "wtt");
	p = {10, "wtt"};
	
	#支持三属性
	pair<int, pair<int, int>>p; 
}
```

事物有两种属性，可按照某属性排序。

## string

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	string a = "wtt";
	a+="qqq";
	
	#常见函数
	a.size(), a.size();
	a.empty();
	a.clear();
	a.substr(1, 2);a.substr(起始下表, 长度);
	a.c_str();
}
```

## queue

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	queue<int>q;
	#基本函数， 无clear 
	q.size()
	q.push();
	q.front();
	q.back()
	q.pop()
	q = queue<int>();
}
```



## priority_queue

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	priority_queue<int> heap;
	
	#常见函数
	heap.clear();
	heap.push();
	heap.top();
	heap.pop();
	
	#小根堆
	priority_queue<int, vector<int>, greater<int>> heap;
	
}
```

实质为堆， 默认为大根堆

## stack

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	stack<int> stk;
	
	#常见函数
	stk.size();  O(1)
	stk.empty();
	stk.push();
	stk.top();
	stk.pop();
}
```



## deque

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	deque<int> dq;
	#常见函数
	dq.clear();
	dq.size();  O(1)
	dq.empty();
	dq.push();
	dq.top();
	dq.pop();
	dq.front() / dq.back();
	dq.push_back() / dq.pop_back();
	dq.push_front() / dq.pop_front();
	
	#迭代器
	begin() / end()
}
```

效率太低



## set, multiset

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
	#set不重复，multiset可重复
	size();
	empty();
	clear();
	begin()/end(); ++, -- O(logN)
	
	insert();    O(n);
	find();查找某个数，不存在则返回end()迭代器
	count(); 每个数的个数
	erase();1.输入是一个数x，则删除多x O(k + logN); 2.输入是迭代器，删除这个迭代器
	lower_bound();返回大于等于x的最小数的迭代器，不存在返回end()
	upper_bound();返回大于x大的最小数的迭代器，不存在返回end()
	
}
```



## map， multimap

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	size();
	empty();
	clear();
	begin()/end(); ++, -- O(logN)
	
	insert();   插入的数是pair
	erase();    输入是一个数/迭代器
	find();
    map<string, int> a;
    a["wtt"] = 1;
    cout<<a["wtt"]<<" "; O(logN)
  lower_bound();
	upper_bound();
}
```

支持排序类操作，但增删改查时间是O(logN)



## unordered_set，unordered_map，unordered_multiset，unordered_multimap

和上面类似，增删改查时间复杂度O(1)

不支持lower_bound()和upper_bound()，迭代器加加减减

https://blog.csdn.net/u012530451/article/details/53228098

## bitset

省内存，省8倍空间

```
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;

int main()
{
	bitset<10000> s;
	~s, &, |, ^, >>, <<
	==， ！=
	[]
	cont()返回有多少个1
	any()判断是否至少有1个1
	none()判断是否全为0
	
	set()设置全为1
	set(k,v)将第k位设置为v
	reset()
	flip()取反
	flip(k)取反第k位
}
```



# string

blog : https://blog.csdn.net/cxh342968816/article/details/6627768

substr()

find()

atoi(string.c_str())