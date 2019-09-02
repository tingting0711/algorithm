#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void insertSort(int q[], int l, int r){
	if(l>=r)return;
	for(int i = l; i < r; i++)
		for(int j = i; j >=0 && q[j] > q[j+1]; j --){
			int t = q[j];
			q[j] = q[j+1];
			q[j+1] = t;
		}
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	insertSort(q, 0, n-1);
	for(int i = 0; i < n; i ++)
		printf("%d ", q[i]);
	return 0;
}