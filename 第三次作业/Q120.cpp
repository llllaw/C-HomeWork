#include<iostream>
using namespace std;
class Bing{
protected:
	Bing* bin;
	int price;
public:
	virtual int getPrice(){
		return price+bin->getPrice();
	}
};
class base : public Bing{
public:
	base(){
		price = 0;
	}
	int getPrice(){
		return price;
	}
};
class bullMeat: public Bing{
public:
	bullMeat(Bing* b){
		price = 10;
		bin = b;
	}
};
class porkMeat : public Bing{
public:
	porkMeat(Bing* b){
		price = 8;
		bin = b;
	}
};
class chickenMeat : public Bing{
public:
	chickenMeat(Bing* b){
		price = 7;
		bin = b;
	}
};
class vegetable: public Bing{
public:
	vegetable(Bing* b){
		price = 4;
		bin = b;
	}
};
class potato : public Bing{
public:
	potato(Bing* b){
		price = 3;
		bin = b;
	}
};
class bingFactory{
public :
	static Bing* getbing(int id,Bing* bing){
		switch (id){
		case 1:
			return new bullMeat(bing);
		case 2:
			return new porkMeat(bing);
		case 3:
			return new chickenMeat(bing);
		}
		return nullptr;
	}
};
class vegeFac{
public :
	static Bing* getbing(int id, Bing* bing){
		switch (id){
		case 1:
			return new vegetable(bing);
		case 2:
			return new potato(bing);
		}
		return nullptr;
	}
};

int main(){
	int id1, number1, id2, number2;
	Bing* bing = new base();
	cin >> id1 >> number1 >> id2 >> number2;
	for (int i = 0; i < number1; i++){
		bing = bingFactory::getbing(id1, bing);
	}
	for (int i = 0; i < number2; i++){
		bing = vegeFac::getbing(id2, bing);
	}
	cout << bing->getPrice();
	return 0;
}