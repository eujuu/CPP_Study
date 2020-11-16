#include <iostream>
using namespace std;
// 상속받은 함수를 감추기(사용하지못하도록 막기)

class Base {
protected:
	int m_i;
	//protected: derived가 상속받아 클래스 내부에서 사용가능, 외부에서는 접근 불가

public:
	Base(int val)
		: m_i(val)
	{

	}
	void print() {
		cout <<"I'm Base " << endl;
	}
	
};
class Derived :public Base{
protected:
	double m_d;
	using Base::print; //private으로 바꾸기,이름만 있으면 됨 -> 괄호 치면 안됨!!
public:
	Derived(int val)
		: Base(val)
	{

	}
	using Base::m_i; //m_i가 derived안에서는 public이 되어버림..

private:
	
	void print() = delete; //자식에서는 접근 불가, 부모는 여전히 접근 및 사용 가능
};
int main() {
	Base base(5);
	base.print(); //base에서는 문제없이 사용 가능


	Derived derived(7);
	derived.m_i = 1024; //access specifier를 유도된 클래스에서 바꾸기 가능
						//Base에서는 protected였지만, Derived에서 이를 바꿔줌으로써 public처럼 사용
	//derived.print(); //Base에서는 public였지만, Derived에서 이를 private으로 사용
}