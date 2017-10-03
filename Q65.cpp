#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
inline int read(){
	int   sig_ = 1, res_ = 0;
	char  ch_ = getchar();
	while (ch_<'0' || ch_>'9'){ if (ch_ == '-') sig_ = -1; ch_ = getchar(); }
	while (ch_ >= '0'&&ch_ <= '9'){ res_ = res_ * 10 + ch_ - '0'; ch_ = getchar(); }
	return sig_*res_;
}
long long getnum(long long num){
	long long result = 0;
	bool count = false;
	long long count1 = 0;
	long long standard = 0x4000000000000;
	long long first = 4;
	while (true){
		if ((num&standard)!=0){
			count = true;
		}
		if (count){
			if (num&standard){
				result += first;
			}
			count1++;
			if (count1 == 3){
				return result;
			}
			first /= 2;
		}
		standard = (standard >> 1);
	}
}
int main(){
	
	long long n;
	long long result = 0;
	scanf_s("%I64d", &n);
	long long input;
	for (long long i = 0; i < n; i++){
		scanf_s("%I64d", &input);
		result += getnum(input);
	}
	cout << result;
	
	
}

