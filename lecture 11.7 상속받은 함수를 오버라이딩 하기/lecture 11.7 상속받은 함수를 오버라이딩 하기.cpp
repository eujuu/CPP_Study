#include <iostream>
using namespace std;
// ��ӹ��� �Լ��� �������̵� �ϱ� 
// output operator overloading

class Base {
protected:
	int m_i;

public:
	Base(int val)
		: m_i(val)
	{

	}
	void print() {
		cout <<"I'm Base " << endl;
	}
	//output operator overloading
	friend ostream& operator << (ostream& out, const Base& b) {
		out << "This is base output" << endl;
		return out;
	}
};
class Derived :public Base{
protected:
	double m_i;

public:
	Derived(int val)
		: Base(val)
	{

	}
	//������ �����ִ� print�Լ� + Base�κ��� ������ print�Լ� 2�� ������?
	// 1. derived�� �Լ� �̸��� �ٲ��ֱ�
	void print() {
		//print(); //��� -> ���ѹݺ��� ������ ��

		//2.
		Base::print();
		cout << "I'm Derived " << endl;
	}
	//output operator overloading
	friend ostream& operator << (ostream& out, const Derived& b) {
		out << static_cast<Base>(b) ; //static cast�� ���� base class operator overloading�� ȣ�� ��
		//�� ��?? -> derived�� base�� �޸𸮸� ������ �ֱ� ������ cast�� �����ϴ�.
		out << "This is derived output" << endl;
		return out;
	}
};
int main() {
	Base base(5);
	base.print();
	cout << base;

	cout << endl;

	Derived derived(7);
	derived.print();
	cout << derived;
}