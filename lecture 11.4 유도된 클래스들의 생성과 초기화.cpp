#include "Student.h"
#include  "Teacher.h"
using namespace std;
// 유도된 클래스들의 생성과 초기화

class Mother {
private:
	int m_i;
public:
	Mother(const int& i_in = 1) 
		:m_i(i_in)
	{
		cout << "Mother Construction " << endl;
	}
};

class Child : public Mother {
public:
	//float m_d;//size = 8 (Mother + m_d ->8)
	double m_d;//size = 16 (Mother + m_d ->16(패딩때메 12아니고 16) )
public:
	Child()
		: Mother(1024), m_d(1.0)
	{
	
		cout << "Child Construction " << endl;
	}
};

class A {
public:
	A(int a) {
		cout << "A: " << a << endl;
	}
	~A() {
		cout << "Descturctor A " << endl;
	}
};

class B : public A {
public:
	B(int a, double b) 
		: A(a)
	{
		cout << "B: " << b << endl;
	}
	~B() {
		cout << "Descturctor B " << endl;
	}
};

class C :public B {
public:
	C(int a, double b, char c)
		:B(a, b)
	{
		cout << "C: " << c << endl;
	}
	~C() {
		cout << "Descturctor C " << endl;
	}
};
int main() {
	Child c1; //size= 16 할당

	cout << sizeof(Mother) << endl;
	cout << sizeof(Child) << endl; //메모리 할당시 Mother클래스의 메모리도 받을만큼 크게 할당받음

	//Grandchild는 Grandmother의 생성자를 직접 호출할 수 없다.
	// 생성순서: A -> B -> C
	// 소멸순서: C -> B -> A
	C c(1024, 3.14, 'a');

}