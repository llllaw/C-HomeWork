#include<iostream>
#include<string>
using namespace std;
int n;
string c, d;
string a[1000];
int dfs(int pos,int dis){
	if (pos > n||a[pos]=="NULL"){
		return -1;
	}
	if (a[pos] == d){
		return dis;
	}
	int a=dfs(2 * pos, dis + 1);
	int b = dfs(2 * pos + 1, dis + 1);
	if (a != -1){
		return a;
	}
	if (b != -1){
		return b;
	}
	return -1;

}
int main(){
	cin >> n;
	int pos;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> c >> d;
	for (int i = 1; i <= n; i++){
		if (a[i] == c){
			pos = i;
			break;
		}
		else if (a[i] == d){
			pos = i;
			string  temp1=c;
			c = d;
			d = temp1;
			break;
		}
	}
	cout << dfs(pos,0);
}