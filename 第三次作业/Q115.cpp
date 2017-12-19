#include<iostream>
#include<algorithm>
using namespace std;

template <class T>
class spacial{
private:
	T array[1000];
	int size;
	T target;
public:
	spacial(){

	}
	void sort(){
		std::sort(array +1, array+size+1);
	}
	int find(int begin, int end){
		if (begin > end) return -1;
		int pos = (begin + end) / 2;
		if (array[pos] == target) return 1;
		else if (array[pos] > target) return find(begin, pos-1) + 1;
		else if (array[pos] < target) return find(pos+1, end) + 1;
		return -1;
	}
	int getSize(){
		return size;
	}
	friend istream& operator>>(istream& is,spacial& sp){
		is >> sp.size;
		for (int i = 1; i <= sp.size; i++){
			is >> sp.array[i];
		}
		is >> sp.target;
		return is;
	}
};
int main(){
	spacial<int> sp1;
	spacial<double> sp2;
	spacial<char> sp3;

	cin >> sp1;

	sp1.sort();
	int result = sp1.find(1, sp1.getSize());
	cout << result<<endl;
	cin >> sp2;
	sp2.sort();
	cout << sp2.find(1, sp2.getSize())<<endl;
	cin >> sp3 ;
	sp3.sort();
	cout << sp3.find(1, sp3.getSize())<<endl;
	return 0;
}          