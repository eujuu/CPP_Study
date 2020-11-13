#include "Student.h"
#include  "Teacher.h"
using namespace std;
// ������ Ŭ�������� ������ �ʱ�ȭ

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
	double m_d;//size = 16 (Mother + m_d ->16(�е����� 12�ƴϰ� 16) )
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
	Child c1; //size= 16 �Ҵ�

	cout << sizeof(Mother) << endl;
	cout << sizeof(Child) << endl; //�޸� �Ҵ�� MotherŬ������ �޸𸮵� ������ŭ ũ�� �Ҵ����

	//Grandchild�� Grandmother�� �����ڸ� ���� ȣ���� �� ����.
	// ��������: A -> B -> C
	// �Ҹ����: C -> B -> A
	C c(1024, 3.14, 'a');

}