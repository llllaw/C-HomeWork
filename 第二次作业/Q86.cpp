#include<iostream>
using namespace std;
int a[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int data[100][100];
int main(){
	int m, n;
	int count=0;
	int number=0;
	cin >> m >> n;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			data[0][j] = -1;
			data[i][0] = -1;
			cin >> data[i][j];
		}
	}
	for (int i = 0; i <= m; i++){
		data[i][0] = -1;
		data[i][n+1] = -1;
	}
	for (int i = 0; i <= n; i++){
		data[0][i] = -1;
		data[m+1][i] = -1;
	}
	cin >> number;
	int x = 1, y = 1;
	int ori = 0;
	while (count != number){
		count++;
		if (count != number){
			data[y][x] = -1;
			
		}
		if ((data[y+a[ori][0]][x+a[ori][1]]==-1)){
			ori = ori + 1;
			if (ori >= 4){
				ori -= 4;
			}
		}
		y += a[ori][0];
		x += a[ori][1];
	}
	
	cout << data[y][x];
	return 0;
}