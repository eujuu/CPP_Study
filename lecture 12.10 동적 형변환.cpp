#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
using namespace std;
// ���� ����ȯ Dynamic Casting
// �θ�Ŭ������ �����ͷ� �ٲ��ְ� �ٽ� �ڽ�Ŭ������ �����ͷ� �ٲ��ִ� ���

class Base {
public:
	int m_i = 0;

	virtual void print() {
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base {
public:
	int m_j = 1024;

	virtual void print() override {
		cout << "I'm derived" << endl;
	}
};

class Derived2 : public Base {
public:
	string m_name = "Dr. Two";

	virtual void print() override {
		cout << "I'm derived" << endl;
	}
};

int main() {
	Derived1 d1;
	Base* base = &d1;

	auto* base_to_d1 = dynamic_cast<Derived1*>(base);//��������ȯ
	//base���� ���� derived1���� �ִ� �͵�(base�� m_j�� ���� �Ұ�)�� �����Ϸ� �� ��
	//base�� �ٽ� derived1�� �ٲپ���� ��
	
	cout<< base_to_d1->m_j << endl;

	//Derived2�� ��������ȯ -> �ȵ�! ��Ÿ�ӿ� ����üũ
	// ** Dynamic Cast�� cast ���н� null pointer�� �־��� -> �ƹ��� ���� �ȳ���

	auto* base_to_d2 = dynamic_cast<Derived2*>(base);//��������ȯ
	if (base_to_d2 != nullptr)
		cout << base_to_d2->m_name << endl;
	else
		cout << "failed" << endl;


	//Static cast�� ��밡��
	auto* base_to_d3 =static_cast<Derived1*>(base);//��������ȯ
	if (base_to_d3 != nullptr)
		base_to_d3->print();
	else
		cout << "Failed" << endl;

	//Static cast�� ��밡�� -> static�� ��Ÿ�ӿ��� ����üũ�� ���� ->�׳� �Ǵ´�� �־���
	// ���⼭�� �׷��� �����ϰԵ�
	auto* base_to_d4 = static_cast<Derived2*>(base);//��������ȯ
	if (base_to_d4 != nullptr)
		base_to_d4->print();
	else
		cout << "Failed" << endl;
}