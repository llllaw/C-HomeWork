#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int a, b;
	cin >> a>> b;
	long long result = 0;
	for (int i = a; i <= b; i++){
		if (i < 2){
			continue;
		}
		int temp = sqrt(i);
		bool judge = true;
		for (int j = 2; j <= temp; j++){
			if (i%j == 0){
				judge = false;
				break;
			}
		}
		if (judge){
			result += i;
		}
	}
	cout << result;

}