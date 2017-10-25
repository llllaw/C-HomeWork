#include<iostream>
#include<string>
using namespace std;
string a[1000];
int b[1000];
int c[1000];
string judge = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
bool biger(int x,int y){
	if (b[x] > b[y]){
		return true;
	}
	else if (b[x] < b[y]){
		return false;
	}
	else{
		int i = 0;
		while (i < b[x]){
			//cout << "find" << a[x][i] << " " << judge.find(a[x][i])<<endl;
			if (judge.find(a[x][i])>judge.find(a[y][i])){
				return true;
			}
			if (judge.find(a[x][i])<judge.find(a[y][i])){
				return false;
			}
			i++;
		}
	}
	return false;
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i].size();
		c[i] = i;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i-1; j++){
			if (biger(c[j], c[j+1])){
				int temp2 = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp2;
			}
		}
	}

	for (int i = 0; i < n; i++){
		cout << a[c[i]] << endl;
	}
}