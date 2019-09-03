/*

给定一个长度为n的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i < j 且 a[i] > a[j]，则其为一个逆序对；否则不是。

输入格式
第一行包含整数n，表示数列的长度。

第二行包含 n 个整数，表示整个数列。

输出格式
输出一个整数，表示逆序对的个数。

数据范围
1≤n≤100000
输入样例：
6
2 3 4 5 6 1
输出样例：
5

*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5;
int n, q[N];
long long mergeSort(int q[], int l, int r)
{
    if(l >= r)return 0;
    int mid = (l + r)>>1, i = l, j = mid + 1, k = 0;
    long long left = mergeSort(q, l, mid);
    long long right = mergeSort(q, mid + 1, r);
    long long res = 0;
    int tmp[N];
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j])tmp[k++] = q[i++];
        else res += mid - i + 1,tmp[k++] = q[j++];
    }
    while(i <= mid)tmp[k++] = q[i++];
    while(j <= r)tmp[k++] = q[j++];
    for(i = 0, j = l; i < k; i++, j ++)q[j] = tmp[i];
    return left + res + right;
}
int main()
{
    cin>>n;
    for(int i = 0 ; i < n ; i ++)scanf("%d", &q[i]);
    cout<<mergeSort(q, 0, n - 1)<<endl;
    return 0;
}