#include<iostream>
using namespace std;
                     
double nutrition[7][4] = {
	{ 16.2 , 3.7, 0 , 0 },
	{ 1.8 , 17.5 , 0 , 7.2 },
	{ 0.2,  0.4,  3.6,  0 },
	{ 12.3,  5.7,  7.3, 3 },
	{ 6.9,  9 , 0 , 9.3 },
	{ 2.1 , 0.8, 4.3,  0}
};
double standard[4] = { 13.3 , 13.5 , 3.3 , 10.3 };
double result[4] = { 0, 0, 0, 0 };
int main(){
	int i, j, k;
	cin >> i >> j >> k;
	if (i >= 8 || j >= 8 || k >= 8) { cout << "-1";  return 0; }
	for (int m = 0; m < 4; m++){
		result[m] = nutrition[i-1][m] + nutrition[j-1][m] + nutrition[k-1][m];
	///	cout << result[m] << endl;
	}
	if (result[0] < standard[0]){
		cout << "unhealthy";
		return 0;
	}
	if (result[1] < standard[1]){
		cout << "unhealthy";
		return 0;
	}
	if (result[2] < standard[2]){
		cout << "unhealthy";
		return 0;
	}
	if (result[3] > standard[3]){
		cout << "unhealthy";
		return 0;
	}
	cout << "healthy";
	return 0;
}