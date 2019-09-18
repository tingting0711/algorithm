/*

题目描述：

给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数N。

第二行包含N个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤100000，
−10^9≤数列中的数≤10^9
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4

*/


/*
解法1：
time : O(NlogN)
space : O(N)
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 1e5, INF = 2e9;

int f[N], a[N];

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    f[0] = -INF;
    int len = 0;
    for(int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(f[mid] < a[i])l = mid;
            else r = mid - 1;
        }
        if(!f[r + 1])f[r + 1] = a[i];
        else f[r + 1] = min(f[r + 1], a[i]);
        len = max(len, r + 1);
    }
    cout<<len<<endl;
    return 0;
}

