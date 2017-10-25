#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;  
	int pos;
	int x, y,sub;
	for (int i = 0; i <=n; i++){
		long long temp = (i*(i + 1) )/ 2;
		if (temp >= n){       
			pos = i ;      
			sub = temp - n;      
			break;
		}
	}
	x = pos;   
	y = 1;      
	for (int i = 0; i < sub; i++){    
		x--;          
		y++;          
	}
	if (pos % 2 == 0){
		cout << x<< "/" << y;
	}
	else{
		cout << y<< "/" << x;
	}

}