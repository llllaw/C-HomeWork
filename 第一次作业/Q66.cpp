#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[102];
int b[7] = { 1, 2, 4, 8, 16, 32, 64 };
int main(){
	string input;
	cin >> input;
	int max = 0;
	int all = 0;
	for (int j = 0,i = 1; j < input.size(); i++){
		if (i==b[max]){
			a[i] = 0;
			max++;         //这波操作没问题
		}
		else{
			a[i] = input[j] - '0';
			//然后从0判断到b[max-1]位
			int temp = 1;
			for (int k = 0; k <=max; k++){
				if (i&temp){
					a[b[k]] ^= a[i];
				}
				temp = (temp << 1);
			}
			j++;
		}
		all = i;
	}
	for (int k = 1; k <= all; k++){
		printf("%d", a[k]);
	}
}