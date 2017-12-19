#include<iostream>
#include<string>
using namespace std;
int m;
class role{
protected:
	int hp;
	int atk;
	string name;
public:
	virtual void affect() = 0;
	virtual bool hurt(int attack){
		hp -= attack;
		if (hp <= 0) return true;
		else return false;
	}
	string getName(){
		return name;
	}
	int getHP(){
		return hp;
	}
	int getAtk(){
		return atk;
	}
};
class warrior: public role{
public:
	
	warrior(){
		hp = 12;
		atk = 2;
		name = "Warrior";
	}
	void affect(){
		hp++;
	}

};
class magician: public role{
private:
	bool use = true;
public:
	magician(){
		hp = 2;
		atk = 6;
		name = "Magician";
	}
	void affect(){
	}
	bool hurt(int attack){
		if (use==false) hp -= attack;
		use = false;
		if (hp <= 0) return true;
		else return false;
	}
};
class leader: public role{
public:
	leader(){
		hp = 6;
		atk = 6;
		name = "Leader";
	}
	void affect(){
		atk++;
	}
};
class roleFac{
public:
	static role* generateRole(int id){
		switch (id){
		case 1:
			return new warrior();
		case 2:
			return new magician();
		case 3:
			return new leader();
		}
		return nullptr;
	}
};

class side{
private:
     role* hero [100];
	 int current=1;
public :
	bool hurt(int attack){
		bool result = hero[current]->hurt(attack);
		if (result == true) current++;
		else hero[current]->affect();
		if (current > m) return true;
		return false;
	}
	void print(){
		for (int i = current; i <= m; i++){
			if (i != current) cout << endl;
			cout << hero[i]->getName() << " " << hero[i]->getAtk()<<" "<< hero[i]->getHP();
		}
	}
	int getAtk(){
		return hero[current]->getAtk();
	}
	friend istream& operator>> (istream& is, side& side){
		for (int i = 1; i <= m; i++){
			int temp;
			cin >> temp;
			side.hero[i] = roleFac::generateRole(temp);
		}
		return is;
	}
};
int main(){
	cin >> m;
	side side1;
	side side2;
	cin >> side1 >> side2;
	while (true){
		int atk1 = side1.getAtk();
		int atk2 = side2.getAtk();
		bool result1 = side1.hurt(atk2); 
		bool result2 = side2.hurt(atk1);
		
		if (result1 || result2){
			if (result1&&result2) cout << "All Dead";
			side1.print();
			side2.print();
			break;
		}
	}
	return 0;
}