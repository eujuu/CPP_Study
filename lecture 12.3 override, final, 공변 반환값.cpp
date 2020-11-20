#include <iostream>
#include <string>
using namespace std;
// override, final ������, ����covariant ��ȯ��


class A {
public: 
	/*virtual*/  void print(int x) { cout << "A" << endl; }
	 virtual A* getThis() { 
		 cout << "A::getThis()" << endl; 
		 return this; 
	 }
	 //covariant return type
};

class B : public A {
//class B{
public:
	void print(/*short*/ int x)  { cout << "B" << endl; } 
	//���� �Ǽ��� Ÿ���� �ٸ� �Ķ���͸� �ִ´ٸ�?
	//virtual�̾ A�� print�Լ��� ȣ��ȴ�.
	// -> �Լ��� �Ķ���Ͱ� �ٸ��� overriding�� �� �� x
	// -> overloading�� �ߴٰ� �Ǵ��ؼ� A�� ȣ���ϰ� ��
	// => �̷� ��Ȳ�� ���ϱ� ���� override������ ��� -> ������ override�̾�� ���� ���� -> �ٸ� ��� ������ ���� �߻�

	virtual B* getThis() { 
		cout << "B::getThis()" << endl; 
		return this;
	}
	//�Ϲ������� ����Ÿ���� �ٸ��� override�Ұ�
	//A*�� B*�� �θ��ڽ� ����� override ��
};

class C : public B {
public: 
	//void print(int x) final { cout << "C" << endl; } 
	// finalŰ���带 ���� ���� Ŭ�������� override�� �� �� ����
};

class D : public C {
public: 
	 //void print(int x) { cout << "D" << endl;}
	 //C���� final �����ڸ� �����߱⿡ ���� �߻�
};
int main() {

	A a;

	B b;

	C c;

	D d;

	//������ �ٲ��ֱ�
	A& ref = b;
	ref.print(1);

	b.getThis()->print(0); //B
	ref.getThis()->print(0); //A -> B�� getThis�� ������ A�� ���� -> ref�� A�̱� ������ �ٽ� A�������ͷ� �ٲ۴����� Ŭ���� ȣ��


	cout << typeid(b.getThis()).name() << endl; //B*
	cout << typeid(ref.getThis()).name() << endl; //A*

}