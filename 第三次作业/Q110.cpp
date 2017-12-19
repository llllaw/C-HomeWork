#include<iostream>
using namespace std;
//x:2,y:3,z:4£¨»»ÐÐ·û£©
//x:6, y : 8, z : 10£¨ÎÞ»»ÐÐ·û£©'
class point{            
public :  
	point(){

	}
	point(int cx,int cy,int cz){
		x = cx;
     	y = cy;
		z = cz;
	}
	int x, y, z;                
	friend ostream& operator <<(ostream& ostream, point& point){
		ostream << "x:" << point.x << ",y:" << point.y << ",z:" << point.z;
		return ostream;
	}
	friend istream& operator >>(istream& istream,point& point){
		istream >> point.x >> point.y >> point.z;
		return istream;
	}
	point operator +( point poin){
		point p;
		p.x =x+ poin.x;
		p.y =y+ poin.y;
		p.z =z+ poin.z;
		return p;
	}
	void operator ++(){
		x++;
		y++;
		z++;
	}
};                       
              
int main(){        
	point p1,p2;
	cin >> p1 >> p2;
	p1++;
	p2 = p1 + p2;
	cout << p1<<endl<<p2;
	return 0;
}                 