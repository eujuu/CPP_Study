#include <iostream>
#include <string>
using namespace std;
// �����Լ� Virtual Functions �� ������ Polymorphism

class A {
public: 
	 virtual void print() { cout << "A" << endl; }
	 //virtual table�� ���鼭 ã�ư��� ���� -> ���� -> ȣ���� ����� �Լ��� ���°� ���� ����
};

class B : public A {
//class B{
public:
	void print() { cout << "B" << endl; } //virtual�� ��� ���� ���� ���
};

class C : public B {
public: 
	void print() { cout << "C" << endl; } 
	//A�� ���� ��ӹ��� ���� �ƴϾ, A�� ���۷����� ���� printȣ�������� ���� ���ΰ� ���
	//B�� virtual�� �ƴϾ. 
	//���� ���� Ŭ������ virtual�̸� �ؿ� �ִ� �͵鵵 �� virtualó�� �ൿ
	//�׷��� ���������� ���� Ŭ�����鵵 virtualŰ���带 ����δ� ��� ����
};

class D : public C {
public: 
	//overriding�� return type�� �ٸ��ٸ�?
	// -> A�� �޶� ������ �Ұ�(�� ���� �ִ°� �߽����� ����)
	/*int*/ void print() { cout << "D" << endl; return 0; }
};
int main() {

	A a;
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();

	//������ �ٲ��ֱ�
	B& ref = c;
	ref.print();

}