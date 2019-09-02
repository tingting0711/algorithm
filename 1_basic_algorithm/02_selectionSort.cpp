#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void selectionSort(int q[], int l, int r){
	if(l>=r)return;
	for(int i = l; i <= r; i++){
		int minIndex = i;
		for(int j = i + 1; j <= r; j ++)
			if(q[j] < q[minIndex]){
				minIndex = j;
			}
		if(minIndex!=i){
			int t = q[minIndex];
			q[minIndex] = q[i];
			q[i] = t;
		}
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	selectionSort(q, 0, n-1);
	for(int i = 0; i < n; i ++)
		printf("%d ", q[i]);
	return 0;
}