#include<iostream>
#include<map>
using namespace std;
map<int, long long> m;
long long fib(int n){
	if (n == 0 ){
		return 0;
	}
	if (n == 1){
		return 1;
	}
	map<int, long long>::iterator a = m.find(n);
	if (a == m.end()){
		long long temp2 = fib(n - 2);
		m[n - 2] = temp2;
		long long temp1 = fib(n - 1);
		m[n - 1] = temp1;
		return temp1 + temp2;
	}
	else{
		return m[n];
	}

}
int main(){
	int n;
	cin >> n;
	cout << fib(n);
}