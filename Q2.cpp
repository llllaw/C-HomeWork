#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long long  a, b;
	bool flag = false;
	cin >> a >> b;
	if (b < 0){
		flag = true;
		b = -b;
	}
	long long result = 1;
	for (int i = 0; i < b; i++){
		result *= a;
	}
	if (flag){
		double result1 = 1.0 / result;
		cout << result1;
	}
	else{
		cout << result;
	}
}