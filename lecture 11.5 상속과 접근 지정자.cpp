#include <iostream>
using namespace std;
//��Ӱ� ���� ������

class Base {
public:
	int m_public;
protected: //�ڽ� Ŭ���� ��� ����
	int m_protected;
private:
	int m_private;
};

class Derived : public Base {
public:
	Derived() {
		//���� ���� ����
		m_public = 123; //����
		m_protected = 123;//����
		//m_private = 123;//�Ұ���
	}
};

class Derived2 :protected Base { //�� ���������� ����
public:
	Derived2() {
		//���� ���� ����
		//Base::m_public = this -> m_public = m_public
		Base::m_public; //����
		Base::m_protected;//����
		//Base::m_private;//�Ұ���
	}
};

class Derived3 :private Base { 
public:
	Derived3() {
		//���� ���� ����
		Base::m_public; //����
		Base::m_protected;//����
		//Base::m_private;//�Ұ���
	}
};

class GrandChild : public Derived3 {
public:
	GrandChild() {
		// m_protected�� ������ ��  �ִ°�?
		// private���� ����� �ް� �Ǹ� grandchild�������� �Ұ�
		//Derived3::m_public; //�Ұ� -> private������ 
		//Derived3::m_protected;

	}
};
int main() {
	Base base;
	base.m_public = 123; //����
	// base.m_protected = 123;  //�Ұ���
	// base.m_private = 123;//�Ұ���

	Derived derived;
	derived.m_public = 1024;
	//derived.m_protected = 1024;//�Ұ���
	//derived.m_private = 1024;//�Ұ���

	Derived2 derived2;
	//derived2.m_public = 1024; //�Ұ���
}