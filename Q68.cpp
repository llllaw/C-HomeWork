#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++){
		string input;
		cin >> input;
		if (input == "append"){
			string add;
			cin >> add;
			str += add;
		}
		else if (input == "replace"){
			string a, b;
			cin >> a >> b;
			int pos = str.find(a);
			while (pos != -1){
				str.replace(pos, a.size(), b);
				pos=str.find(a);
			}
		}
		else if (input == "reverse"){
			reverse(str.begin(), str.end());
		}
		else if (input == "changecase"){
			string option;
			cin >> option;
			if (option == "up"){
				transform(str.begin(), str.end(), str.begin(), ::toupper);
			}
			else{
				transform(str.begin(), str.end(), str.begin(), ::tolower);
			}
		}
		else if (input == "length"){
			cout << str.size()<<endl;
		}
		else if (input == "print"){
			cout << str << endl;
		}
	}
}
//append£¬replace£¬reverse£¬changecase£¬length£¬print¡£