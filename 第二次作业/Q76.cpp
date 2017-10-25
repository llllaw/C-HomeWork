#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	string temp1;
	string temp2;
	vector<int> l1;
	vector<int> l2;
	getline(cin,temp1);
	getline(cin,temp2);
	int length1=0;
	int length2=0;
	for (int i = temp1.size()-5; i>=0; i--){
		if (temp1[i] == '>'){
		}
		else{
			l1.push_back(temp1[i] - '0');
			length1++;
		}
	}

	for (int i = temp2.size() - 5; i >= 0; i--){
		if (temp2[i] == '>'){

		}
		else{
			l2.push_back(temp2[i] - '0');
			length2++;
		}
	}
	int next = 0;
	int i = 0;
	for ( i = 0; i < length1; i++){
		if (i < length2){
			l1[i] = l1[i] + l2[i]+next;
			next = 0;
			while (l1[i] >= 10){
				l1[i] -= 10;
				next++;
			}
		}
		else{
			break;
		}
	}

	while (i <length1){
		
		l1[i] += next;
		next = 0;
		while (l1[i] >= 10){
			l1[i] -= 10;
			next++;
		}
		i++;
	}
	while (i < length2){
		l1.push_back(next + l2[i]);
		next = 0;
		i++;
		length1++;
		while (l1[i-1] >= 10){
			l1[i-1] -= 10;
			next++;
		}
	}
	if (i == length1&&next != 0){
		l1.push_back(next);
		length1++;
	}
	bool put=false;
	for (int i = length1 - 1; i >= 0; i--){
		if (l1[i] != 0)
			put = true;
		if (put)
		cout << l1[i]<<">";
	}
	cout << "null";
}

//本题经历的坑，最前面可以进位，最前面的0要去掉，一些逻辑的判断