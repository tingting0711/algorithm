#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void bubbleSort(int q[], int l, int r){
	if(l>=r)return;
	for(int end = r - l + 1; end >= 0; end --)
		for(int i = 0; i < end; i ++)
			if(q[i] > q[i+1]){
				int t = q[i];
				q[i] = q[i+1];
				q[i+1] = t;
			}
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	bubbleSort(q, 0, n-1);
	for(int i = 0; i < n; i ++)
		printf("%d ", q[i]);
	return 0;
}