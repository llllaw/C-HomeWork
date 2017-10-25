#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int a[102];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int num;
	cin >> num;
	for (int i = 0; i < num; i++){
		string temp;
		//¶¨ÒåÃüÁîadd£¬sub£¬mul£¬ pow£¬sqa£¬printÁùÖÖÃüÁî¡£
		cin >> temp;
		
		if (temp == "add"){
			int input;
			cin >> input;
			for (int i = 0; i < n; i++){
				a[i] += input;
			}
			//continue;
		}else if (temp == "sub"){
			int input;
			cin >> input;
			for (int i = 0; i < n; i++){
				a[i] -= input;
			}
			//continue;
		}else if (temp == "mul"){
			int input;
			cin >> input;
			for (int i = 0; i < n; i++){
				a[i] *= input;
			}
			//continue;
		}else if (temp == "pow"){
			int input;
			cin >> input;
			for (int i = 0; i < n; i++){
				a[i] = pow(a[i], input);
			}
			//continue;
		}else if (temp == "sqa"){
			int result = 0;
			for (int i = 0; i < n; i++){
				result += a[i] * a[i];
			}
			cout << result << endl;
			//continue;
		}else if (temp == "print"){
			for (int i = 0; i < n; i++){
				if (i == 0){
					cout << a[i];
				}
				else{
					cout << " " << a[i];
				}
			}
			cout << endl;
			//continue;
		}
	}
}