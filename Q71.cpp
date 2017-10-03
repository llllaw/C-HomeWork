#include<iostream>
#include<string>
using namespace std;
int main(){
	long long n;
	cin >> n;
	string input = to_string(n);
	for (int i = input.size() - 1; i >= 0; i--){
		cout << input[i];
	}
}