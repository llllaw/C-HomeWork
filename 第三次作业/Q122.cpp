#include<iostream>
using namespace std;
int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int days2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool judge(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
	return false;
}
class date{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public :
	void add(){
		second++;
		if (second == 60){
			second = 0;
			minute++;
			if (minute == 60){
				minute = 0;
				hour++;
				if (hour == 24){
					hour = 0;
					day++;
					if (judge(year)){
						if (day == days2[month - 1] + 1){
							day = 1;
							month++;
						}
					}
					else{
						if (day == days[month - 1] + 1){
							day = 1;
							month++;
						}
					}
					if (month == 13){
						month = 1;
						year++;
					}
				}
			}
		}
	}
	friend istream& operator >>(istream& is,date& d){
		is >> d.year >> d.month >> d.day >> d.hour >> d.minute >> d.second;
		return is;
	}
	friend ostream& operator <<(ostream& os, date& d){
		os << d.year << " " << d.month << " " << d.day << " " << d.hour << " " << d.minute << " " << d.second;
		return os;
	}
};
int main(){
	date d;
	cin >> d;
	d.add();
	cout << d;
	return 0;
}