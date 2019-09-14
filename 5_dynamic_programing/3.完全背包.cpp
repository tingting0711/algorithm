/*

题目描述：

有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。

第 i 种物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 种物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
10

*/

/*
朴素解法
time : O(N*V*k)
space : O(N*V)
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, m;
int f[N][N];
int v[N], w[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d%d", &v[i], &w[i]);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            for(int k = 1; k * v[i] <= j; k++)
            f[i][j] = max(f[i][j], f[i][j - k * v[i]] + k * w[i]);
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}


/*
状态优化版
time : O(N*V)
space : O(N*V)
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, m;
int f[N][N];
int v[N], w[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d%d", &v[i], &w[i]);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i])f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}

/*
一位数组优化版
time : O(N*V)
space : O(V)
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, m;
int f[N];
int v[N], w[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d%d", &v[i], &w[i]);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(j >= v[i])f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}



