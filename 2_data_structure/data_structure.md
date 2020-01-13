# 链表
## 单链表

- 领接表
  - 图
  - 树

```
#静态链表
#include<iostream>
using namespace std;
const int N = 100010;

int head, e[N], ne[N], idx;

void init()
{
	head = -1;
	idx = 0;
}
void add_to_head(int x)
{
	e[idx] = x, ne[idx] = head, head = idx ++;
}

//将x插入下标是k的点后面
void add(int x, int k)
{
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}
//将下标是k的点的后面点删掉
void remove(int k)
{
	ne[k] = ne[ne[k]];
}
int main()
{
	
	return 0;
}
```



## 双链表

- 优化某些题

```
#下标为0的点为head,下标为1的点为tail
#include<iostream>
using namespace std;
const int N = 100010;

int e[N], l[N], r[N], idx;
void init()
{
	//0表示左端点，1表示右端点
	r[0] = 1, l[1] = 0,idx = 2;
}

//在第k点的右边插入一个点
void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx;
	r[k] = idx ++;
}

//删除第k个点
void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
```




#栈

- 先进后出

```
#include<iostream>
using namespace std;
const int N = 100010;
int stk[N], tt; //栈顶下标，从1开始

//加入一个数
stk[++ tt] = x;

//弹出
tt --;

//判断是否为空
if(tt > 0) not empty

//栈顶元素
stk[tt];
```



#队列

- 先进先出

```
#队尾插入，队头输出
int q[N], hh, tt = -1;//从0开始
//插入
q[++ tt] = x;
//弹出
hh ++;
//判断是否为空
if(hh <= tt) not empty
//队头
q[hh];
//队尾
q[tt];
```





#单调栈

- O(N)

常见应用：给定一个序列，求序列中每个数左边最接近该数的值

```
#include<iostream>
using namespace std;
const int N = 100010;

int n;
int stk[N], tt;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		while(tt && stk[tt] >= x) tt--;
		if(tt)cout<<stk[tt]<<' ';
		else cout<<-1<<'  ';
		stk[++tt] = x;
	}
	return 0;
}
```



#单调队列

常见应用：求滑动窗口的最值

```
#include<iostream>
using namespace std;
const int N = 100010;

int n,k;
int a[N], q[N];
int main()
{
	cin>>n>>k;
	for(int i = 0; i < n; i++)cin>>a[i];
	int hh = 0, tt = -1;
	for(int i = 0; i < n; i++)
	{
		if(hh <= tt && i - k + 1 > q[hh])hh++;
		while(hh <= tt && a[q[tt]] >= a[i])tt --;
		q[++tt] = i;
		if(i >= k -1)cout<<a[q[hh]]<<" ";
	}
	for(int i = 0; i < n; i++)
	{
		if(hh <= tt && i - k + 1 > q[hh])hh++;
		while(hh <= tt && a[q[tt]] <= a[i])tt --;
		q[++tt] = i;
		if(i >= k -1)cout<<a[q[hh]]<<" ";
	}
	return 0;
}
```



#KMP

- 暴力枚举
- 如何优化

```
#include<iostream>
using namespace std;
const int N = 10010, M = 100010;
int n, m;
int p[N], s[M];
int ne[N];

int main()
{
	cin>> n >> p + 1>> m >> s + 1;
	
	//求next过程
	for(int i = 2, j = 0; i <= n; i++)
	{
		while(j && p[i] != p[j + 1])j = ne[j];
		if(p[i] == p[j + 1])j++;
		ne[i] = j;
	}
	
	//kmp匹配过程
	for(int i = 1, j = 0; i <= m; i++)
	{
		while(j && s[i] != p[j + 1]) j = ne[j];
		if(s[j] == p[j + 1])j++;
		if(j == n)
		{
			//匹配成功
			cout<<i - n<<" ";
			j = ne[j]; //
		}
	}
	return 0;
}
```



# Trie

- 数组模拟指针
- 高效的存储和查找字符串
- 集合的数据结构
- 字母种类较少，一般26或者54

> 835字符串统计

```
#include<iostream>
using namespace std;
const int N = 100010;
int son[N][26], cnt[N], idx; //下表为0的节点即是根节点，又是空节点
char str[N];
void insert(char str[])
{
	int p = 0;
	for(int i =0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if(!son[p][u])son[p][u] = ++ idx;
		p = son[p][u];
	}
	cnt[p] ++;
}

int query(char str[])
{ 
	int p = 0;
	for(int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if(!son[p][u])return 0;
		p = son[p][u];
	}
	return cnt[p];
}
int main()
{
	int n;
	cin>>n;
	while(n --)
	{
		char op[2];
		cin>>op>>str;
		if(op[0] == 'I')insert(str);
		else cout<<query(str)<<endl;
	}
	return 0;
}
```



#并查集

- 将两集合合并
- 询问量元素是否在同一个集合中
- 时间复杂度近乎O(1)

基本原理：每个集合用一棵树来表示，树根的编号就是整个集合的编号。每个节点存储它的父节点，p[x]表示x的父节点。

求树根：p[x] = x;

求编号：while(p[x] != x)x = p[x];

合并集合：px是x的集合编号，py是y的集合编号，则p[x] = py或者p[y] = px;

优化：路径压缩

> 836并查集

```
#include<iostream>
using namespace std;
const int N = 100010;
int n, m;
int p[N];
int find(int x)
{
	if(p[x] != x)p[x] = find(p[x]); //路径压缩
	return p[x];
}
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)p[i] = i;
	while(m --)
	{
		char op[2]; //如果读入字符，scanf会读入特殊字符(空格、回车)；读入字符串则不会。
		int a, b;
		cin>>op>>a>>b;
		if(op[0] == 'I')p[find(a)] = find(b);
		else
		{
			if(find(a) == find(b))puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
```



#堆

- priority_queue
- 完全二叉树
- 可以插入数                      heap[ ++size] = x; up(size);
- 可以求最小值                  heap[1];
- 可以删除最小值              heap[1] = heap[size- -], down(1);
- 可以删除任意数              heap[x] = heap[size- -], down(x), up(x);
- 可以修改任意数             heap[x] = x1, up(x), down(x);
- 堆的下标从1开始

存储: x的左二子是2x, 右儿子是2x+1

操作：up , down

```
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n,m;
int h[N], size;

void down(int u)
{
	int t = u;
	if(u*2 <= size && h[u*2] < h[t])t = u*2;
	if(u*2+1 <= size &&h[u*2 + 1] < h[t])t = u*2+1;
	if(u != t)
	{
		swap(h[u], h[t]);
		down(t); 
	}
}

void up(int u)
{
	while(u / 2 && h[u / 2] > h[u])
  {
  	swap(h[u / 2], h[u]);
  	u /= 2;
  }
}

int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)cin>>h[i];
	size = n;
	for(int i = n / 2; i; i--)down(1); //从高度为1的节点开始down, 时间复杂可以证明为O(N)
	while(m --)
	{
		cout<<h[1]<<" ";
		h[1] = h[size --];
		down(1);
	}
}
```



#哈希表
- 哈希表的存储结构
  - 开放寻址法
  - 拉链法
- 字符串哈希

将庞大的数据映射到较小的空间

## 哈希表的存储结构

> 开放寻址法

```
#include<cstring>
#include<iostream>
using namespace std;
const int N = 200003, null = 0x3f3f3f3f;
int n;
int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while(h[k]!= null && h[k]!=x)
    {
         k++;
        if(k == N)k = 0;
    }
    return k;
}
int main()
{
    scanf("%d", &n);
    memset(h, null, sizeof h);
    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if(*op == 'I')h[k] = x;
        else 
        {
            if (h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}
```

> 拉链法

```
#include<cstring>
#include<iostream>
using namespace std;
const int N = 100003;
int n;
int h[N], e[N], ne[N],idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i])
    {
        if(x == e[i])return true;
    }
    return false;
}
int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    while(n--)
    {
        char op[2];
        int x; 
        scanf("%s%d", op, &x);
        if(*op == 'I')insert(x);
        else 
        {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}
```

## 字符串哈希

- 主要用于判断两字符串是否相等
- 假定不存在冲突
- P = 131 或13331
- Q = 2<sup>64</sup>

```c++
#include<iostream>
using namespace std;
typedef unsigned long long ULL;

const int N = 100010, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    cin>>n>>m>>str;
    p[0] = 1;
    for(int i = 1; i <= n ; i ++)
    {
        p[i] = p[ i - 1] * P;
        h[i] = h[i - 1] * P + str[i - 1];
    }
    while(m --)
    {
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1, r1) == get(l2, r2))puts("Yes");
        else puts("No");
    }
    return 0;
    
}
```

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

```c++
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

```c++
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

```c++
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
	a.c_str();返回起始地址（用于pritf("%s", s.c_str())）
}
```

## queue

```c++
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
	q.size();
	q.empty();
	q.push();
	q.front();
	q.back();
	q.pop();
	q = queue<int>();//重新构造
}
```



## priority_queue

```c++
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

```c++
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

```c++
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

```c++
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
	#set不重复，multiset可重复, 
	size();
	empty();
	clear();
	begin()/end(); ++, -- （前驱、后继）O(logN)
	
	# O(logN);
	insert(); 
	find();查找某个数，不存在则返回end()迭代器
	count(); 每个数的个数
	erase();1.输入是一个数x，则删除所有x O(k + logN), k是x的个数
	        2.输入是迭代器，删除这个迭代器
	lower_bound();返回大于等于x的最小数的迭代器，不存在返回end()
	upper_bound();返回大于x大的最小数的迭代器，不存在返回end()
	
}
```



## map， multimap

```c++
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

```c++
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
	count()返回有多少个1
	any()判断是否至少有1个1
	none()判断是否全为0
	
	set()设置全为1
	set(k,v)将第k位设置为v
	reset()
	flip()取反
	flip(k)取反第k位
}
```
