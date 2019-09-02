#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
using std::vector;
const int N = 1e6 + 10;
int n;
int q[N];
long long smallSum(int q[], int l, int r){
	if(l>=r)return 0;
	int mid = (l + r)>>1;
	long long res = 0;
	res += smallSum(q, l, mid) + smallSum(q, mid + 1, r);
	int i = l, j = mid + 1, k = 0, tmp[r - l + 1];
	while(i <= mid && j <= r){
		if(q[i] < q[j]){
			res += q[i]*(r - j + 1);
			tmp[k++] = q[i++];
		}else{
			tmp[k++] = q[j++];
		}
	}
	while(i <= mid)tmp[k++] = q[i++];
	while(j <= r)tmp[k++] = q[j++];

	for(i = l, k = 0; i <= r; i++, k++)q[i] = tmp[k];
	return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &q[i]);
    cout<<smallSum(q, 0, n-1);
	return 0;
}