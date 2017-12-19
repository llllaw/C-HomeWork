#include<iostream>
#include<string>
using namespace std;
class Student{
public:
	string id;
	string name;
	int age;
	double weight;
	double math;
	double english;
	double c_plus;
	double all;
public :
	friend istream& operator>>(istream& is,Student& stu){
		is >> stu.id >> stu.name >> stu.age >> stu.weight >> stu.math >> stu.english >> stu.c_plus;
		stu.all = stu.math * 4 + stu.english * 4 + stu.c_plus * 3;
		return is;
	}
	int operator <(Student& stu){
		if (all < stu.all) return -1;
		else if (all == stu.all) return 0;
		else return 1;
	}
};
template <class T>
int compare(T a,T b){
	if (a < b) return -1;
	else if (a>b) return 1;
	else return 0;
}
int main(){
	Student stu1,stu2;
	cin >> stu1>>stu2;
	cout << compare<string>(stu1.name, stu2.name)
		<< " " << compare<int>(stu1.age, stu2.age)
		<< " " << compare<int>(stu1.weight, stu2.weight)
		<< " "<< compare<double>(stu1.all, stu2.all);
	return 0;
}


