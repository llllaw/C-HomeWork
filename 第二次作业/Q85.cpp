#include<iostream>
#include<string>
using namespace std;
int num[101];
int num2[101];
int mov[101];
int main(){
	int number;
	int m;
	int count=0;
	cin >> number;
	for (int i = 0; i < number; i++){
		cin >> num[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		string operation;
		cin >> operation;
		if (operation == "print"){
			for (int i = 0; i < number; i++){
				cout << num[i] << " ";
			}
			cout << endl;
		}else if (operation == "move"){
			string ht;
			int a;
			cin >> ht;
			cin >> a;
			count = 0;
			for (int i = 0; i < number; i++){
				num2[i] = num[i];
				if (num[i] == a){
					mov[count] = i;
					count++;
				}
			}
			if (ht == "head"){
				int n = 0;
				for (int i = 0; i < count; i++){
					num[n] = num2[mov[i]];
					n++;
					num2[mov[i]] = -1;
				}
				for (int i = 0; i < number; i++){
					if (num2[i] != -1){
						num[n] = num2[i];
						n++;
					}
				}
			}

			if (ht == "tail"){
				int n = number-1;
				for (int i = count-1; i>=0; i--){
					num[n] = num2[mov[i]];
					n--;
					num2[mov[i]] = -1;
				}
				for (int i = number-1; i >=0 ; i--){
					if (num2[i] != -1){
						num[n] = num2[i];
						n--;
					}
				}
			}
		}else if (operation == "replace"){
			int a, b;
			cin >> a>> b; 
			for (int i = 0; i < number; i++){
				if (num[i] == a){
					num[i] = b;
				}
			}
		}else if (operation=="translate"){
			string ht;
			int a;
			cin >> ht;
			cin >> a;
			a = a%number;
			for (int i = 0; i < number; i++){
				num2[i] = num[i];
			}
			if (ht == "head"){
				for (int i = 0; i < number; i++){
					if (i + a >= number){
						num[i] = num2[i + a - number];
					}
					else{
						num[i] = num2[i+a];
					}
				}
			}
			else{
				for (int i = 0; i < number; i++){
					if (i - a < 0){
						num[i] = num2[i - a + number];
					}
					else{
						num[i] = num2[i - a];
					}
				}
			}
		}

	}
	return 0;
	
}


