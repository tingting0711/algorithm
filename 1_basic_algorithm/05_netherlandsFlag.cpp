#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, k;
int q[N];
void netherlansFlag(int q[], int l, int r, int k ){
	int less = l - 1, more = r + 1, cur = l;
	while(cur < more){
		if(q[cur] < k){
			less ++;
			int t = q[cur];
			q[cur] = q[less];
			q[less] = t;
			cur ++;
		}else if(q[cur] > k){
			more --;
			int t = q[cur];
			q[cur] = q[more];
			q[more] = t;
		}else cur ++;
	}
	cout<<less + 1<<" "<<more - 1<<endl;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)scanf("%d", &q[i]);
    netherlansFlag(q, 0, n-1, k);
	for(int i = 0; i < n; i++)printf("%d ", q[i]);
	return 0;
}