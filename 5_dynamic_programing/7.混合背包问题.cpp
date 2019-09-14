/*

题目描述：

有 N 种物品和一个容量是 V 的背包。

物品一共有三类：

第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si 次（多重背包）；
每种体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

si=−1 表示第 i 种物品只能用1次；
si=0 表示第 i 种物品可以用无限次；
si>0 表示第 i 种物品可以使用 si 次；
输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000
−1≤si≤1000
输入样例
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
输出样例：
8

*/


/*
解法1：
time : O(N*V*logS)
space : O(N*logS)
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10010;
int n, m;
int f[N];
int s[N], v[N], w[N];

int main()
{
    cin>>n>>m;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if(c == -1)
        {
            cnt ++;
            s[cnt] = -1;
            v[cnt] = a;
            w[cnt] = b;
        }
        else if(c == 0)
        {
            cnt ++;
            s[cnt] = 0;
            v[cnt] = a;
            w[cnt] = b;
        }
        else
        {
            int t = 1;
            while(t < c)
            {
                cnt ++;
                s[cnt] = -1;
                v[cnt] = a * t;
                w[cnt] = b * t;
                c -= t;
                t *= 2;
            }
            if(c)
            {
                cnt ++;
                s[cnt] = -1;
                v[cnt] = a * c;
                w[cnt] = b * c;
            }
        }
    }
    n = cnt;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == -1)
        {
            for(int j = m; j >= v[i]; j--)
            {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
        else
        {
            for(int j = 0; j <= m; j++)
            {
                if(j >= v[i])f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}