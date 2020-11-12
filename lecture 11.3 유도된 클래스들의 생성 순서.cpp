#include "Student.h"
#include  "Teacher.h"
using namespace std;
// Derived ������ Ŭ�������� ���� ����

class Mother {
public:
	int m_i;
	
	Mother(const int& i_in = 1) //default constructor���� ����� ȿ��^^
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
		: Mother(1024), m_d(1.0) //����������� �׻� Mother class�� constructor�� ���� �����Ŵ

		//:m_d(1.0) //m_i�ʱ�ȭ ���� m_d�� �ʱ�ȭ ��
		//: Mother(), m_d(1.0) //�տ� Mother()�� �����ִ� ��
		//: m_i(1024) // �Ұ��� -> mother construction���� ���̱� ������ -> initialize list���� ��� �Ұ�
	{
		/*
		* // 4���� ��� ����
		m_i = 10; //private�Ұ�
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
	Child c1; //Mother construction -> child construction������ ����

	C c;// A-> B -> C ����

	B b; // A-> B ����

	//Destructor�� ������ ������ �ݴ��

}