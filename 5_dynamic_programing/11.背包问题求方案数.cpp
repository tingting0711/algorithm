/*

题目描述：

有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

输出 最优选法的方案数。注意答案可能很大，请输出答案模 109+7 的结果。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示 方案数 模 109+7 的结果。

数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 6
输出样例：
2

*/


/*
解法1：
time : O(N*V) = 10^6
space : O(N)
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int f[N], g[N];
int INF = 1000000, mood = 1e9 + 9;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    g[0] = 1;
    for(int i = 1; i <= m; i++)f[i] = -INF;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        for(int j = m; j >= a; j--)
        {
            int s = 0;
            int tmp = max(f[j], f[j - a] + b);
            if(tmp == f[j])
            {
                s += g[j];
                s %= mood;
            }
            if(tmp == f[j - a] + b)
            {
                s += g[j - a];
                s %= mood;
            }
            f[j] = tmp;
            g[j] = s;
            
        }
    }
    int maxw = 0;
    for(int i = 0; i <= m; i++)maxw = max(maxw, f[i]);
    int res = 0;
    for(int i = 0; i<= m; i++)
    {
        if(f[i] == maxw)
        {
            res += g[i];
            if(res >= mood)res %= mood;
        }
    }
    cout<<res<<endl;
    return 0;
}