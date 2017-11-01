#include<iostream>
#include<map>
#include<string>
#include<set>
#include"Student.h"
using namespace std;
Student stu[1000];
set<string> sub;
int studentNum=0;
int allSub=0;
bool cmp(Student a, Student b){
	if (a.getAverage() > b.getAverage()){
		return true;
	}
	else if (a.getAverage() == b.getAverage()){
		return a.getID() > b.getID();
	}
	else{
		return false;
	}
}
int main(){
	int count;
	cin >> count;
	
	for (int i = 0; i<count; i++){
		string name;
		long long ID;
		string subject;
		int score;
		cin >> name >> ID >> subject >> score;
		//先找学科
		set<string>::iterator it;
		it = sub.find(subject);
		if (it==sub.end()){ //没找到就添加
			sub.insert(subject);
			allSub++;
			for (int j = 0; j < studentNum; j++){
				stu[j].addSub(subject);
			}
		}
		
		//再找学生
		bool find = false;
		int j = 0;
		for (j = 0; j < studentNum; j++){
			if (stu[j].getID() == ID){
				find = true;
				stu[j].updateGrade(subject, score);
			}
		}
		if (!find){
			stu[studentNum].setID(ID);
			stu[studentNum].addAllSub(sub);
			stu[studentNum].updateGrade(subject, score);
			studentNum++;
		}
	}

	double allAverage=0;
	for (int i = 0; i < studentNum; i++){
		stu[i].calAverage();
		allAverage += stu[i].getAverage();
	}
	allAverage /= studentNum;
	for (int i = 0; i < studentNum; i++){
		for (int j = 0; j < studentNum-1-i; j++){
			if (!cmp(stu[j], stu[j + 1])){
				Student student;
				student = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = student;
			}
		}
	}
	for (int i = 0; i < studentNum; i++){
		if (stu[i].getAverage() < allAverage){
			cout << stu[i].getID()<<endl;
		}
	}
	return 0;
	
}
