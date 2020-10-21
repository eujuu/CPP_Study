#include <iostream>
#include <string>
using namespace std;
//�͸� ��ü anonymous
//�̸��� ���� ���� ���� ���� �ٷ� ���

class A {
public:
	int m_val;

	A(const int& input):m_val(input) {
		cout << "Constructor" << endl;
	}
	~A() {
		cout << "Destructor" << endl;
	}
	void print() {
		cout << "Hello" << endl;
	}
	void printDouble() {
		cout << m_val * 2 << endl;
	}
};

class Cents {
private:
	int m_cents;

public:
	Cents(int cents) {
		m_cents = cents;
	}
	int getCents() const {
		return m_cents;
	}
};
Cents add(const Cents& c1, const Cents& c2) {
	return Cents(c1.getCents() + c2.getCents());
}
int main() {
	//A a;
	//a.print();
	//a�� ���̻� ���x
	//A().print(); //A() : r-value, ���� �Ұ�(�Ҹ��� ȣ��), �� �� ������ �ٷ� �Ҹ�
	
	A a(1);
	a.print();

	A(1).printDouble();

	cout << add(Cents(6), Cents(8)).getCents();
	cout << int(6) + int(8) << endl; //���� �̰� casting�ΰ�??
}