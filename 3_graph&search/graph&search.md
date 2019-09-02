# 图论与搜索
## DFS

- 栈
- O(h)
- 不具有最短路

> 全排列问题
>
> ```
> #include<iostream>
> using namespace std;
> const int N = 9;
> int n;
> int path[N];
> bool st[N];
> void dfs(int u){
>     if(u == n){
>         for(int i = 0; i < n; i++)cout<<path[i]<<" ";
>         puts("");
>         return;
>     }
>     for(int i = 1; i <= n; i++){
>         if(!st[i]){
>             st[i] = true;
>             path[u] = i;
>             dfs(u + 1);
>             st[i] = false;
>         }
>     }
> }
> int main(){
>     cin>>n;
>     dfs(0);
>     return 0;
> }
> ```

> N皇后问题
>
> ```
> 
> ```

## BFS

- 队列

- O(2<sup>h</sup>)

- 具有最短路

> 走迷宫
>
> ```
> #include<iostream>
> #include<cstring>
> #include<algorithm>
> using namespace std;
> 
> typedef pair<int, int> PII;
> const int N = 105;
> 
> int n, m;
> int g[N][N];
> int d[N][N];
> PII q[N * N];
> 
> int bfs()
> {
>     int hh = 0, tt = 0;
>     q[0] = {0, 0};
>     memset(d, -1, sizeof d);
>     d[0][0] = 0;
>     
>     int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
>     while(hh <= tt)
>     {
>         auto t = q[hh++];
>         for(int i = 0; i< 4; i++)
>         {
>             int x = t.first + dx[i], y = t.second + dy[i];
>             if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
>             {
>                 d[x][y] = d[t.first][t.second] + 1;
>                 q[++ tt] = {x, y};
>             }
>         }
>     }
>     return d[n - 1][m - 1];
> }
> 
> int main()
> {
>     cin>>n>>m;
>     for(int i = 0; i < n; i++)
>     {
>         for(int j = 0; j < m; j++)
>         {
>             cin>>g[i][j];
>         }
>     }
>     cout<<bfs()<<endl;
>     return 0;
> }
> 
> ```
>
> 

## 树与图的存储

- 树是一种特殊的图(无环连通图)

- 无向图是一种特殊的有向图，故图与树的存储只需考虑有向图即可

- 有向图

  - 邻接矩阵 (适用于密度较高的图)
  - 邻接表
> ```
> #include<iostream>
> #include<cstring>
> #include<algorithm>
> using namespace std;
> 
> const int N = 100010, M = N * 2;
> int h[N], e[M], ne[M], idx;
> bool st[N];
> ```
>
> ```
> void add(int a, int b)
> {
> 	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
> }
> int main()
> {
> 	memset(h, -1, sizeof h);
> }
> ```

## 树与图的遍历 - DFS

- 一般每个点只遍历一遍

> ```
> void dfs(int u)
> {
> 	st[u] = true;
> 	for(int i = h[u]; i != -1; i = ne[i])
> 	{
> 		int j = e[i];
> 		if(!st[j])dfs(j);
> 	}
> }
> ```

- 数的重心

>```
>#include<iostream>
>#include<cstring>
>#include<algorithm>
>using namespace std;
>
>const int N = 100010, M = N * 2;
>int h[N], e[M], ne[M], idx;
>bool st[N];
>int ans = N;
>
>void add(int a, int b)
>{
>	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
>}
>
>//返回以u为根的子树中 点的数量
>int dfs(int u)
>{
>	st[u] = true;
>	int sum = 1;
>	for(int i = h[u]; i != -1; i = ne[i])
>	{
>		int j = e[i];
>		if(!st[j])
>		{
>			int s = dfs(j);
>			res = max(res, s);
>			sum += s;
>		}
>	}
>	res = max(res, n - sum); 
>	
>	ans = min(ans, res);
>	return sum;
>}
>
>int main()
>{
>	cin>>n;
>	memset(h, -1, sizeof h);
>	
>	for(int i = 0; i < n - 1; i++)
>	{
>		int a, b;
>		cin>>a>>b;
>		add(a, b), add(b, a);
>	}
>	dfs(1);
>	cout<<ans<<endl;
>
>```

## 树与图的遍历 - BFS

> 847. 图中点的层次
>
> ```
>   #include<iostream>
> #include<cstring>
> #include<algorithm>
> using namespace std;
> 
> const int N = 100010, M = 2 * N;
> int n, m;
> int idx, e[M], ne[M], h[N];
> int q[N], d[N];
> bool st[N]; //拿出来扩展才用到，从队列中拿出
> 
> void add(int a, int b)
> {
>     e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
> }
> int bfs()
> {
>     int hh = 0, tt = 0;
>     memset(d, -1, sizeof d);
>     q[0] = 1;
>     d[1] = 0;
>     while(hh <= tt)
>     {
>         int t = q[hh ++];
>         for(int i = h[t]; i != -1; i = ne[i])
>         {
>             int j = e[i];
>             if(d[j] == -1) //判断是否第一次遇到
>             {
>                 q[++ tt] = j;
>                 d[j] = d[t] + 1;
>             }
>         }
>     }
>     return d[n];
> }
> int main()
> {
>     cin>>n>>m;
>     memset(h, -1, sizeof h);
>     for(int i = 0; i < m; i++)
>     {
>         int a,b;
>         cin>>a>>b;
>         add(a, b);
>     }
>     cout<<bfs()<<endl;
>     return 0;
> }
> ```
>



## 最短路

- 单源最短路

  - 所有边权重都是正数
    - 朴素Dijkstra算法            O(n<sup>2</sup>)                  适合稠密图
    - 堆优化版Dijkstra算法    O (mlogn)          适合稀疏图
  - 存在负权边
    - Bellman-Ford                 O(nm)
    - SPFA                                O(m) ~ O(nm)

- 多源汇最短路

  - Floyd算法                               O(n<sup>3</sup>)

***********

> ### 朴素Dijkstra

1. dist[1] = 0, dist[i] = +~, st = {} 当前已确定最短距离的点

2. for (1 - n)

   t : 不在st中， 距离原点最近的点       O(n)

   更新st，把t加入st中                           O(1)

   用t去更新其他点的最小距离              O(n)

```
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 510;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))t = j;
        }
        st[t] = true;
        if(t == n)break;
        for(int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j])
        }
    }
    if(dist[n] == 0x3f3f3f3f)return -1;
    return dist[n];
}
int main()
{
    memset(g, 0x3f, sizeof g);
    cin>>n>>m;
    while(m --)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b] = min(g[a][b],c);
    }
    int t = dijkstra();
    cout<<t<<endl;
    return 0;
}
```

***********



> ### 堆优化版Dijkstra

 ```
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n,m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> >heap;
    heap.push({0, 1});
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        if(st[ver])continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f)return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m;
    memset(h, -1, sizeof h);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int t = dijkstra();
    cout<<t<<endl;
}
 ```

***********



> ### Bellman-Ford

for k : 1 -> n , 使用不超过k条边

​	for 所有边 a,b,w

​		dist[b] = min(dist[b], dist[a]+w)

```
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 510, M = 10010;

int n,m,k;
int dist[N], backup[N];
struct Edge
{
    int a, b, w;
}edge[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for(int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for(int j = 0; j < m; j++)
        {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w); 
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2)return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m>>k;
    for(int i = 0; i < m; i++ )
    {
        int a, b, w;
        cin>>a>>b>>w;
        edge[i] = {a, b, w};
    }
    
    int t = bellman_ford();
    if(t == -1)cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
```

***********



> ### SPFA 

类似堆优化版的bellman_ford


```
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

int n,m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int>q;
    q.push(1);
    st[1] = true;
    
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    
    if(dist[n] == 0x3f3f3f3f)return -1;
    return dist[n];
}
int main()
{
    cin>>n>>m;
    memset(h, -1, sizeof h);
    while(m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        add(a, b, c);
    }
    int t = spfa();
    if(t == -1)cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
```

***********



> ### Floyd算法

 for k : 1 -> n

​	 for i : 1 -> n

​		 for j : 1 -> n

​			d\[i][j] = min(d\[i][j] ,d\[i][k] + d\[k][j] )

```
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 210, INF = 1e9;
int n,m,Q;
int d[N][N];

void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    cin>>n>>m>>Q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)d[i][j] = 0;
            else d[i][j] = INF;
        }
        
    }
    while(m --)
    {
        int a,b,w;
        cin>>a>>b>>w;
        d[a][b] = min(d[a][b], w);
    }
    floyd();
    while(Q --)
    {
        int a,b;
        cin>>a>>b;
        if(d[a][b] > INF/2)cout<<"impossible"<<endl;
        else cout<<d[a][b]<<endl;
    }
    return 0;
}
```



## 最小生成树

- 无向图

- prim
  - 朴素版prim  稀疏图 O(n<sup>2</sup>)
  - 堆优化prim  稠密图 O(mlogn)
- kruskal
  - O(mlogn)

> 朴素版prim
>

dist[i] = +~

for i: 0 -> n

​	找到集合s外距离最近的点 t

​	用t更新其他点到**集合**的距离

​	将t加入集合s

```
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n,m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))t = j;
        }
        if(i && dist[t] == INF)return INF;
        if(i)res += dist[t]; //自环
        
        for(int j = 1; j <= n; j++)dist[j] = min(dist[j], g[t][j]);
        
        st[t] = true;
    }
    return res;
}

int main()
{
    cin>>n>>m;
    memset(g, 0x3f, sizeof g);
    while(m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int t = prim();
    if(t == INF)cout<<"impossible"<<endl;
    else cout<<t<<endl;
    
    return 0;
}
```




> kruskal
>

1. 将所有边按照权重从小到大排序   O(mlongm)

2. 枚举每条边： a -> b, c:                  O(m)

   if a, b 不连通，将边加入集合

```
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;

int n,m;
int p[N];

struct Edge
{
    int a,b,w;
    bool operator< (const Edge &W) const
    {
        return w < W.w;
    }
}edge[N];

int find(int x)
{
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        edge[i] = {a,b,w};
    }
    
    sort(edge, edge + m);
    for(int i = 1; i <= n; i++)p[i] = i;
    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++)
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if(a != b)
        {
            p[a] = b;
            res += w;
            cnt ++;
        }
    }
    if(cnt < n - 1)cout<<"impossible";
    else cout<<res<<endl;
    
    return 0;
}
```

## 二分图

- 当且仅当图中不存在奇数环
- 染色法
  - O(n + m)
- 匈牙利算法
  - O(nm), 实际运算时间远小于O(nm)
> 染色法

for i : 1 -> n

​	if(i 未染色)

​		dfs(i)

```
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010, M = 200020;
int n,m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!color[j])
        {
            if(!dfs(j, 3 - c))return false;
        }
        else if(color[j] == c)return false;
    }
    return true;
}

int main()
{
    cin>>n>>m;
    memset(h, -1, sizeof h);
    
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        add(a, b), add(b, a);
    }
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            if(!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
```



> 匈牙利算法




```
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x)
{
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>n1>>n2>>m;
    memset(h, -1, sizeof h);
    while(m --)
    {
        int a, b;
        cin>>a>>b;
        add(a,b);
    }
    int res = 0;
    for(int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st); //妹子是否被考虑过
        if(find(i)) res ++;
    }
    cout<<res<<endl;
    return 0;
}
```