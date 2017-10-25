#include<iostream>
#include<string>
using namespace std;
string input[10000];
int j = 1;
void inOrder(int n){
	if (input[n] == "null" || n >= j){
		return;
	}
	else{
		inOrder(2 * n);
		cout << input[n] << " ";
		inOrder(2 * n + 1);
	}
}

int main(){
	string temp="";
	getline(cin, temp);
	temp += " ";
	string temp1="";
	for (int i = 0; i < temp.size(); i++){
		if (temp[i] == ' '){
			if (temp1 != ""){
			input[j] = temp1;
			temp1 = "";
			j++;
		    }
		}
		else{
			temp1 += temp[i];
		}
	}
	//被测试用例坑了，有空两个格的
	inOrder(1);
	return 0;
}
