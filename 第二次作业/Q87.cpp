#include<iostream>
using namespace std;
int height;
int max=100000000;
int data[100][100];
int all[100][100];//到这个点之前的最短

void dfs(int x,int n, int now){
	if (n == height+1){
		if (now < max){
			max = now;
		}
		return;
	}
	if (now < all[n][x]){
		all[n][x] = now;
		dfs(x, n + 1, now + data[n][x]);
		dfs(x + 1, n + 1, now + data[n][x]);
	}
}
int main(){
	cin >> height;
	memset(all,1000000,100 * 100 * sizeof(int));
	for (int i = 1; i <=height; i++){
		for (int j = 1; j <= i; j++){
			cin >> data[i][j];
		}
	}
	dfs(1,1,0);
	cout << max;
}