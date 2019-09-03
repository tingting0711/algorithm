/*
给定你一个长度为n的整数数列。

请你使用归并排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

输入格式
输入共两行，第一行包含整数 n。

第二行包含 n 个整数（所有整数均在1~109范围内），表示整个数列。

输出格式
输出共一行，包含 n 个整数，表示排好序的数列。

数据范围
1≤n≤100000
输入样例：
5
3 1 2 4 5
输出样例：
1 2 3 4 5
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100005;

int n, q[N];
void mergeSort(int q[], int l, int r)
{
    if(l >= r)return;
    int mid = (l + r)>>1;
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    int tmp[N], i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j])tmp[k ++] = q[i ++];
        else tmp[k ++] = q[j ++];
    }
    while(i <= mid)tmp[k++] = q[i ++];
    while(j <= r)tmp[k++] = q[j++];
    for(int i = 0, j = l; i < k; i++, j++)q[j] = tmp[i];
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)scanf("%d", &q[i]);
    mergeSort(q, 0 , n - 1);
    for(int i = 0; i < n; i ++)printf("%d ", q[i]);
    return 0;
}