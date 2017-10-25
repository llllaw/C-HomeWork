#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
map<string, vector<int>*> m1;
map<string, vector<int>*> m2; 
//m1.count
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string name;
		string number;
		string subject;
		int score;
		cin >> name >> number >> subject >> score;
		if (m1.count(name) > 0){
			m1[name]->push_back(score);
		}
		else{
			m1[name]=new vector<int>;
			m1[name]->push_back(score);
		}
		if (m2.count(subject) > 0){
			m2[subject]->push_back(score);
		}
		else{
			m2[subject] = new vector<int>;
			m2[subject]->push_back(score);
		}
	}
	int num;
	cin >> num;
	for (int i=0; i < num; i++){
		string input;
		string subject;
		string name;
		cin >> input;
		if (input == "course"){
			cin >> subject;
			size_t len = m2[subject]->size();
			double result = 0;
			for (size_t i = 0; i < len; i++) {
				int d = (*m2[subject])[i];
				result += d;
			}
			result = (double)result / (double)len;
			cout << subject << " ";
			printf("%.2f\n", result);
		}
		else{
			cin >> subject;
			size_t len = m1[subject]->size();
			double result = 0;
			for (size_t i = 0; i < len; i++) {
				int d = (*m1[subject])[i];
				result += d;
			}
			result = (double)result / (double)len;
			cout << subject << " ";
			printf("%.2f\n", result);
		}
	}
}