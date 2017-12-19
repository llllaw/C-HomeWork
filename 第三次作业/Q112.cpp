#include<iostream>
using namespace std;
//派生类是可以通过作用域解析运算符去调用父类的方法的
//c++思考面向对象问题也要通过指针的角度进行，函数指针的调用，一些地址的实际处理方法，数据结构的布置
class Operation{
private:
	double numberA;
	double numberB;
	
public:
	double getA(){
	 	return numberA;
	}
	double getB(){
		return numberB;
	}
	void setA(double a){
		numberA = a;
	}
	void setB(double b){
		numberB = b;
	}
	virtual double getResult() = 0;
};          
                              
class OperationAdd: public Operation{
public:
	
	double getResult(){
		return getA() + getB();
	}
};                   
class OperationSub : public Operation{
public:
	double getResult(){
		return getA() - getB();
	}

};             
class OperationMul : public Operation {
public:
	double getResult(){
		
		return getA() * getB();
	}
};          
class OperationDiv : public Operation{
public:
	double getResult(){
		if (getB() == 0) return -1;
		return getA() / getB();
	}
};   
class operationFactory{
public :
	static Operation* createOperation(char op){
		Operation* ope=nullptr;
		switch (op){
		case '+':
			ope = new OperationAdd();
			break;
		case '-':
			 ope = new OperationSub();
			 break;
		case '*':           
			ope= new OperationMul();               
			break;                   
		case '/':          
			ope= new OperationDiv();          
			break;                      
		}                          
		return ope;             
	}                               
};                          
//所有指针变量的大小都是固定的，只不过按照前面的类型确定了解析的方法，这样可以形成多态,编译器会自动存储记忆解析的方式
//所有c++中的对象指针是和java中的引用变量更加相似的东西
//void* 代表任意类型的指针
int main(){
	char op;          
	double a, b;
	cin >> op >> a >> b;
	Operation* ope = operationFactory::createOperation(op);       
	ope->setA(a);
	ope->setB(b);
	double result= ope->getResult();      
	cout << result;                         
	return 0;
}                