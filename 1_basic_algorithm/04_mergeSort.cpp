#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void mergeSort(int q[], int l, int r){
	if(l>=r)return;
	int mid = (l + r)>>1;
	mergeSort(q, l, mid);
	mergeSort(q, mid+1, r);
	int i = l, j = mid + 1, k = 0, tmp[r - l + 1];
	while(i <= mid && j <= r){
		tmp[k++] = q[i] < q[j] ? q[i++] : q[j++];
	}
	while(i <= mid)tmp[k++] = q[i++];
	while(j <= r)tmp[k++] = q[j++];
	for(i=l,j=0; i <= r; i++,j++)q[i] = tmp[j];
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	mergeSort(q, 0, n-1);
	for(int i = 0; i < n; i ++)
		printf("%d ", q[i]);
	return 0;
}