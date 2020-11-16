#include <iostream>
using namespace std;
// 상속받은 함수를 오버라이딩 하기 
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
	//본인이 갖고있는 print함수 + Base로부터 가져온 print함수 2개 구분은?
	// 1. derived의 함수 이름을 바꿔주기
	void print() {
		//print(); //재귀 -> 무한반복에 빠지게 됨

		//2.
		Base::print();
		cout << "I'm Derived " << endl;
	}
	//output operator overloading
	friend ostream& operator << (ostream& out, const Derived& b) {
		out << static_cast<Base>(b) ; //static cast를 통해 base class operator overloading이 호출 됨
		//왜 돼?? -> derived는 base의 메모리를 가지고 있기 때문에 cast가 가능하다.
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