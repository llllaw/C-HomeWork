#include<iostream>
#include<string>
#include<stack>
using namespace std;
int length;
int i = 0;
string temp;
stack<string> s;
bool calculateB();
bool calculateC();
bool isBig(char a){
	if ('A' <= a&&a < 'Z'){
		return true;
	}
	return false;
}
bool calculateA(){
	int count=0;
	i++;
	if (temp[i] == '/'){
		return calculateB();
	}
	else if (temp[i] == '!'){
		
		if (temp[i+1] == '-'){
			
			if (temp[i+2] == '-')
			return calculateC();
		}
	}
	string put = "";
	while (i < length){
		if (temp[i] == '>'){
			if (count == 0){
				return false;
			}
			else{
				s.push(put);
				return true;
			}
		}
		if (isBig(temp[i])){
			count++;
			put += temp[i];
			if (count > 9){
				return false;
			}
		}
		else{
			return false;
		}
		i++;
	}
}       
bool calculateB(){
	int count = 0;
	i++;
	string put = "";
	while (i < length){
		if (temp[i] == '>'){
			if (count == 0){
				return false;
			}
			else{
				string temp1 = s.top();
				s.pop();
				if (temp1 == put)
					return true;
				else
					return false;
			}
		}
		if (isBig(temp[i])){
			count++;
			put += temp[i];
			if (count > 9){
				return false;
			}
		}
		else{
			return false;
		}
		i++;
	}
	return false;
}      
bool calculateC(){
	i++;
	while (i < length){
		/*
		if (temp[i] == '<'){
			bool judge=calculateA();
			if (judge == false){
				return false;
			}
		}
		*/
		if (temp[i] == '-'){
			
			if (temp[i+1] == '-'){
				
				if (temp[i+2] == '>'){
					i += 2;
					return true;
				}
			}
		}
		i++;
	}
	return false;
}      
int main(){
	bool result;
	getline(cin, temp);
	length = temp.size();
	for (i = 0; i < length; i++){
		switch (temp[i]){
		case '<':
			result = calculateA();
			if (!result){
				cout << "False";
				return 0;
			}
			break;
		case '>':
			cout << "False";
			return 0;
			break;
		}
	}
	if (!s.empty()){
		cout << "False";
		return 0;
	}
	if (result){
		cout << "True";
	}
	else{
		cout << "False";
	}
	return 0;
}