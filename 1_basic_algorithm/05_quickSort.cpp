#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void quickSort(int q[], int l, int r){
	if(l>=r)return;
	int i = l - 1;
	int j = r + 1;
	int x = q[l];
	while(i < j){
		do i++; while(q[i] < x);
		do j--; while(q[j] > x);
		if(i < j){
			int t = q[i];
			q[i] = q[j];
			q[j] = t;
		}
	}
	quickSort(q, l, j);
	quickSort(q, j+1, r);
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	quickSort(q, 0, n-1);
	for(int i = 0; i < n; i ++)
		printf("%d ", q[i]);
	return 0;
}