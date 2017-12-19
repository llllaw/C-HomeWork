#include<iostream>
using namespace std;
int d[4][2] = { { 0, 1 }, { 1, 0 }, { 1, 1 }, {1,-1}};
class board{
	int b[200][200];
	int current = 1;
	int size;
	int m;
	int currentSize = 0;
public :  
	int checkResult(int x, int y){
		currentSize++;
		b[x][y] = current;
		int result[4];
		for (int i = 0; i < 4; i++) result[i] = 1;
		for (int i = 0; i < 4; i++){
			for (int j = 1; true; j++){
				int x1 = x + j*d[i][0];
				int y1 = y + j*d[i][1];
				if (!outOfBound(x1, y1)&&b[x1][y1] == current) result[i]++;
				else break;
			}
			for (int j = 1; true; j++){
				int x1 = x - j*d[i][0];
				int y1 = y - j*d[i][1];
				if (!outOfBound(x1, y1) && b[x1][y1] == current) result[i]++;
				else break;
			}
			if (result[i] >= m){
				current = -current;
				return 1;
			}
		}
		if (currentSize == size*size) return -1;
		current = -current;
		return 0;
	}   
	bool outOfBound(int x,int y){
		if (x<0 || x>=size || y<0 || y>=size) return true;
		else return false;
	}
	friend istream& operator >>(istream& is,board& board){
		is >> board.size;
		is >> board.m;
		return is;
	}
	int getCurrent(){
		return current;
	}
};
int main(){
	board b;
	cin >> b;
	while (true){
		int x, y;
		cin >> x >> y;
		int result=b.checkResult(x, y);
		if (result == 1){
			if (b.getCurrent() == -1){
				cout << "O Success";
			}
			else{
				cout << "X Success";
			}
			return 0;
		}
		else if (result == -1){
			cout << " Dogfall";
			return 0;
		}
	}
}