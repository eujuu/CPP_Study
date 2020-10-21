#include <iostream>
#include <string>
using namespace std;
//익명 객체 anonymous
//이름이 붙은 변수 선언 없이 바로 사용

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
	//a를 더이상 사용x
	//A().print(); //A() : r-value, 재사용 불가(소멸자 호출), 한 번 생성후 바로 소멸
	
	A a(1);
	a.print();

	A(1).printDouble();

	cout << add(Cents(6), Cents(8)).getCents();
	cout << int(6) + int(8) << endl; //과연 이게 casting인가??
}