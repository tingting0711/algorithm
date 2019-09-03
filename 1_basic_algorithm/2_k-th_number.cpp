/*

给定一个长度为n的整数数列，以及一个整数k，请用快速选择算法求出数列的第k小的数是多少。

输入格式
第一行包含两个整数 n 和 k。

第二行包含 n 个整数（所有整数均在1~109范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第k小数。

数据范围
1≤n≤100000,
1≤k≤n
输入样例：
5 3
2 4 1 5 3
输出样例：
3

*/

//先排序后输出有序数组的第k个数
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5;
int n, k, q[N];
void quickSort(int q[], int l, int r)
{
    if(l >= r)return;
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j)swap(q[i], q[j]);
    }
    quickSort(q, l, j);
    quickSort(q, j + 1, r);
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)scanf("%d", &q[i]);
    quickSort(q, 0, n -1);
    printf("%d\n", q[k - 1]);
}

//将数组分成2部分，依=每次抛弃一半数据
/*
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5;
int n, k, q[N];
int quickSort(int q[], int l, int r, int k)
{
    if(l >= r)return q[l];
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j)swap(q[i], q[j]);
    }
    if(k <= j - l + 1)quickSort(q, l, j, k);
    else quickSort(q, j + 1, r, k - (j - l + 1));
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)scanf("%d", &q[i]);
    cout<<quickSort(q, 0, n -1, k)<<endl;
}
*/