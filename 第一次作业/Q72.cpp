#include<iostream>
#include<string>
using namespace std;
//I£¨1£©¡¢X£¨10£©¡¢C£¨100£©¡¢M£¨1000£©¡¢V£¨5£©¡¢L£¨50£©¡¢D£¨500£©
int getnum(char a){
	switch (a){
	case 'I':
		return 1;
	case 'X':
		return 10;
	case 'C':
		return 100;
	case 'M':
		return 1000;
	case 'V':
		return 5;
	case 'L':
		return 50;
	case 'D':
		return 500;
	}
	return 0;
}
int main(){
	int result = 0;
	string input;
	cin >> input;
	int i = 0;
	while (i < input.size()){
		if (getnum(input[i]) < getnum(input[i + 1])){
			result -= getnum(input[i]);
			result += getnum(input[i + 1]);
			i += 2;
		}
		else{
			result += getnum(input[i]);
			i += 1;
		}
	}
	cout << result;
}