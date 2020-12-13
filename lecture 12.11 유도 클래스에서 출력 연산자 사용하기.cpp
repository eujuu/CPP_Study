#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
using namespace std;
// ����Ŭ�������� ��� ������ ����ϱ�
// ��� ��쿡�� ������ ��� �Ұ� -> ��¿�����!(�������̵� �Ұ�)

class Base {
public:
	Base() {}

	friend ostream& operator << (ostream& out, const Base& b)  { //����ƴ� -> �������̵� �Ұ�
		//�ڽ�Ŭ������ �̰�  ����������  �ʿ䰡 ����
		return b.print(out);
	}
	virtual ostream& print(ostream& out) const { //���� ��� ���ش�
		out << "Base";
		return out;
	}
};

class Derived : public Base {
public:
	Derived() {}

	virtual ostream& print(ostream& out) const override {
		out << "Derived";
		return out;
	}
};



int main() {
	Base b;
	cout << b << endl; //Base

	Derived d;
	cout << d << endl; //Derived

	Base& bref = d;
	cout << bref << endl;//Derived
}