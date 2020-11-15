#include <iostream>
using namespace std;
//상속과 접근 지정자

class Base {
public:
	int m_public;
protected: //자식 클래스 사용 가능
	int m_protected;
private:
	int m_private;
};

class Derived : public Base {
public:
	Derived() {
		//접근 가능 여부
		m_public = 123; //가능
		m_protected = 123;//가능
		//m_private = 123;//불가능
	}
};

class Derived2 :protected Base { //더 엄격한쪽을 따름
public:
	Derived2() {
		//접근 가능 여부
		//Base::m_public = this -> m_public = m_public
		Base::m_public; //가능
		Base::m_protected;//가능
		//Base::m_private;//불가능
	}
};

class Derived3 :private Base { 
public:
	Derived3() {
		//접근 가능 여부
		Base::m_public; //가능
		Base::m_protected;//가능
		//Base::m_private;//불가능
	}
};

class GrandChild : public Derived3 {
public:
	GrandChild() {
		// m_protected를 가져올 수  있는가?
		// private으로 상속을 받게 되면 grandchild에서부터 불가
		//Derived3::m_public; //불가 -> private상태임 
		//Derived3::m_protected;

	}
};
int main() {
	Base base;
	base.m_public = 123; //가능
	// base.m_protected = 123;  //불가능
	// base.m_private = 123;//불가능

	Derived derived;
	derived.m_public = 1024;
	//derived.m_protected = 1024;//불가능
	//derived.m_private = 1024;//불가능

	Derived2 derived2;
	//derived2.m_public = 1024; //불가능
}