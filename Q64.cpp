#include<iostream>
#include<stack>
#include<string>
using namespace std;
int trans(char a){
	if (a <= '9'){
		return a - '0';
	}
	else{
		return a - 'A' + 10;
	}
}

int main(){
	stack<char> s1, s2;
	bool m1 = false, m2 = false;
	int num1=0, num2=0;
	int result;
	string op, input1, input2;
	cin >> op >> input1 >> input2;
	for (int i = 0; i < input1.size(); i++){
		if (i == 0 && input1[1] == '-'){
			m1 = true;
		}
		else{
			s1.push(input1[i]);
		}
	}
	int i = 1;
	while (!s1.empty()){
		num1 += trans(s1.top())*i;
		s1.pop();
		i *= 13;
	}
	for (int i = 0; i < input2.size(); i++){
		if (i == 0 && input2[1] == '-'){
			m2 = true;
		}
		else{
			s2.push(input2[i]);
		}
	}
	i = 1;
	while (!s2.empty()){
		num2 += trans(s2.top())*i;
		s2.pop();
		i *= 13;
	}
	if (m1){
		num1 = -num1;
	}
	if (m2){
		num2 = -num2;
	}
	if (op == "add"){
		result = num1 + num2;
	}
	else if (op == "sub"){
		result = num1 - num2;
	}
	else if (op=="mul"){
		result =num1 * num2;
	}
	if (result < 0){
		result = -result;
		cout << "-";
	}
	while (result > 0){
		int remain = result % 13;
		char c = remain >= 10 ? (remain - 10 + 'A') : (remain + '0');
		s1.push(c);
		result /= 13;
	}
	while (!s1.empty()){
		cout << s1.top();
		s1.pop();
	}
}