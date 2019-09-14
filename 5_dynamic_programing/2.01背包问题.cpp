/*

有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

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
8

*/

/*
	二维数组
	space:O(N^2)
	time:O(N^2)

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
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &w[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i])f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}

/*
	二维滚动数组	
	space:O(N)
	time:O(N^2)
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int n, m;
int f[2][N];
int v[N], w[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &w[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            f[i & 1][j] = f[i - 1 & 1][j];
            if(j >= v[i])f[i & 1][j] = max(f[i & 1][j], f[i - 1 & 1][j - v[i]] + w[i]);
        }
    }
    int res = 0;
    // for(int i = 0; i <= m; i++)cout<<f[n][i]<<" ", res = max(res, f[n][i]);
    printf("%d\n", f[n & 1][m]);
    return 0;
}


/*
	一维数组	
	space:O(N)
	time:O(N^2)
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
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &w[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}


/*
状态数组的初始化极为重要，若状态数组初始化全为0，则f[m]为答案：f[m]表示体积 j<= m的情况下的最优解
                      若状态数组初始化为负无穷，则需要枚举所有最后一层的所有状态：f[m]表示体积 j== m的情况下的最优解
*/


