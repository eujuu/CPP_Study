#include "Student.h"
#include  "Teacher.h"
using namespace std;
// Derived 유도된 클래스들의 생성 순서

class Mother {
public:
	int m_i;
	
	Mother(const int& i_in = 1) //default constructor까지 만드는 효과^^
		:m_i(i_in)
	{
		cout << "Mother Construction " << endl;
	}
};

class Child : public Mother {
public:
	double m_d;

public:
	Child()
		: Mother(1024), m_d(1.0) //순서상관없이 항상 Mother class의 constructor를 먼저 실행시킴

		//:m_d(1.0) //m_i초기화 이후 m_d가 초기화 됨
		//: Mother(), m_d(1.0) //앞에 Mother()가 숨어있는 것
		//: m_i(1024) // 불가능 -> mother construction수행 전이기 때문에 -> initialize list에만 사용 불가
	{
		/*
		* // 4가지 모두 가능
		m_i = 10; //private불가
		this->m_i = 10;
		Mother::m_i = 1024;
		this->Mother::m_i = 1024;
		*/
		cout << "Child Construction " << endl;
	}
};

class A {
public:
	A(){
		cout << "A Constructor " << endl;
	}
};

class B : public A {
public:
	B() {
		cout << "B Constructor " << endl;
	}
};

class C : public B {
public:
	C() {
		cout << "C Constructor " << endl;
	}
};
int main() {
	Child c1; //Mother construction -> child construction순으로 생성

	C c;// A-> B -> C 순서

	B b; // A-> B 순서

	//Destructor는 생성자 순서의 반대로

}