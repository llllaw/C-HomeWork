#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	int maxlength=1;
	string temp;
	cin >> n >> temp;
	for (int i = 0; i < n; i++){
		int length = 1;
		int r = 1;
		while (i - r >= 0 && i + r < n){
			if (temp[i - r] == temp[i + r]){
				length+=2;
				r++;
			}
			else{
				break;
			}
		}
		if (length > maxlength){
			maxlength = length;
		}
		length = 0;
		r = 0;
		while (i - r >= 0 && i + r +1 < n){
			if (temp[i - r] == temp[i + r+ 1]){
				length += 2;
				r++;
			}
			else{
				break;
			}
		}
		if (length > maxlength){
			maxlength = length;
		}
	}
	cout << maxlength;
}
