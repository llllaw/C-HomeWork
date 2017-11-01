#include<iostream>
#include"Student.h"
#include<string>
using namespace std;

long long Student::getID(){
	return ID;
}
void Student::addSub(string sub){
	(score)[sub] = 0;
}

void Student::addAllSub(set<string> a){
	set<string>::iterator iter = a.begin();
	while (iter != a.end())
	{
		(score)[(*iter)] = 0;
		++iter;
	}
}

void Student::updateGrade(string sub, int grade){
	(score)[sub] = grade;
}

void Student::calAverage(){
	int count=0;
	int all = 0;
	map<string, int>::iterator it;
	it = score.begin();

	while (it != score.end())
	{
		count++;
		all += it->second;
		it++;
	}
	average = (double)all / (double)count;
}

Student::Student(int m_ID){
	ID = m_ID;
	
}

Student::~Student(){
	
}
Student::Student(){

}

double Student::getAverage(){
	return average;
}

void Student::setID(long long m_ID){
	ID = m_ID;
}


