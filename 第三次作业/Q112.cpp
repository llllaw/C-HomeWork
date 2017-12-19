#include<iostream>
using namespace std;
//�������ǿ���ͨ����������������ȥ���ø���ķ�����
//c++˼�������������ҲҪͨ��ָ��ĽǶȽ��У�����ָ��ĵ��ã�һЩ��ַ��ʵ�ʴ����������ݽṹ�Ĳ���
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
//����ָ������Ĵ�С���ǹ̶��ģ�ֻ��������ǰ�������ȷ���˽����ķ��������������γɶ�̬,���������Զ��洢��������ķ�ʽ
//����c++�еĶ���ָ���Ǻ�java�е����ñ����������ƵĶ���
//void* �����������͵�ָ��
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