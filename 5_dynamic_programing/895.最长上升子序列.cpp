/*

题目描述：

给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数N。

第二行包含N个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤1000，
−10^9≤数列中的数≤10^9
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4

*/


/*
解法1：
time : O(N^2)
space : O(N)
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N], f[N];

int main()
{
		cin>>n;
		for(int i = 1; i <= n; i++)cin>>a[i];
		
		for(int i = 1; i <= n; i++)
		{
				f[i] = 1;
				for(int j = 1; j < i; j++)
						if(a[j] < a[i])f[i] = max(f[i], f[j] + 1);
		}
		
		int res = 0;
		for(int i = 1; i <= n; i++)res = max(res, f[i]);
		cout<<res<<endl;
		return 0;
}


/*
解法2：
time : 
space : 
*/



/*
解法3：
time : 
space : 
*/
