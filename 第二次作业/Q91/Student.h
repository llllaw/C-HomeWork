

#ifndef STUDENT_H
#define STUDENT_H


#include<map>
#include<string>
#include<set>
using namespace std;

class Student{
private:
	long long ID;
	map<string,int>  score;
	double average;
public:
	Student();
	Student(int m_ID);
	~Student();
	void calAverage();
	void addSub(string sub);
	void addAllSub(set<string> a);
	void updateGrade(string sub,int grade);
	long long getID();
	double getAverage();
	void setID(long long m_ID);
	
};

#endif