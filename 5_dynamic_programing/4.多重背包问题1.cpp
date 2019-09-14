/*

题目描述：
有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤100
0<vi,wi,si≤100
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10

*/


/*
解法1：朴素解法
time : O(N*V*S)
space : O(N*V)
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int  N = 110;
int n, m;
int f[N][N];
int v[N], w[N], s[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d%d%d", &v[i], &w[i], &s[i]);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k <= s[i] && k * v[i] <= j; k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}

/*
解法2：一维数组解法
time : O(N*V*S)
space : O(V)
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int  N = 110;
int n, m;
int f[N];
int v[N], w[N], s[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d%d%d", &v[i], &w[i], &s[i]);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 0; j--)
        {
            for(int k = 0; k <= s[i] && k * v[i] <= j; k++)
            {
                f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
            }
        }
    }
    printf("%d\n", f[m]);
    return 0;
}


/*
解法3：二进制优化
time : O(N*V*logS)
space : O(V)
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int  N = 110*7;
int n, m;
int f[N];
int v[N], w[N];
int main()
{
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int k = 1;
        while(k < c)
        {
            cnt ++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            c -= k;
            k *= 2;
        }
        if(c > 0)cnt++, v[cnt] = a * c, w[cnt] = b * c;
    }
    n = cnt;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 0; j--)
        {
            if(j >= v[i])f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}

/*
解法4：二进制优化
time : O(N*V*logS)
space : O(V)
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int  N = 110*7;
int n, m;
int f[N];
int v[N], w[N];
int main()
{
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int k = 1;
        while(k < c)
        {
            cnt ++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            c -= k;
            k *= 2;
        }
        if(c > 0)cnt++, v[cnt] = a * c, w[cnt] = b * c;
    }
    n = cnt;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 0; j--)
        {
            if(j >= v[i])f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}
