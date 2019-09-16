/*

题目描述：

给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
输入格式
第一行包含整数n，表示数字三角形的层数。

接下来n行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。

输出格式
输出一个整数，表示最大的路径数字和。

数据范围
1≤n≤500,
−10000≤三角形中的整数≤10000
输入样例：
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
输出样例：
30

*/


/*
解法1：自上向下
time : O(N^2)
space : O(N^2)
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 510, INF = 1e9;
int a[N][N], f[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)scanf("%d", &a[i][j]);
    }
    
    for(int i = 0; i <= n; i ++)
    {
        for(int j = 0; j <= i + 1; j++)f[i][j] = - INF;
    }
    
    f[1][1] = a[1][1];
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
        }
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++)res = max(res, f[n][i]);
    cout<<res<<endl;
    return 0;
}



/*
解法2：自下而上
time : O(N^2)
space : O(N^2)
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 510, INF = 1e9;
int a[N][N], f[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)scanf("%d", &a[i][j]);
    }
    
    for(int i = 1; i <= n; i++)f[n][i] = a[n][i];
    
    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
        }
    }
    cout<<f[1][1]<<endl;
    return 0;
}

