#include <iostream>
using namespace std;
// 유도된 클래스에(자식클래스에) 새로운 기능 추가하기

class Base {
//private:
protected:
	int m_val;
public:
	Base(int val)
		:m_val(val)
	{

	}

};

class Derived : public Base {
public:
	Derived(int val)
		:Base(val)
	{

	}
	void doSomething() {
		//base의 값을 건드리지 않는 경우는 그냥 막 만들어도 됨
	}
	void setValue(int val) {
		//자식 클래스의 변수와 부모클래스 변수가 같이 사용되는 경우에 접근방법 고려해야함

		Base::m_val = val;  // private멤버 접근불가 
		//1. 부모 클래스에 getValue등 public 함수를 만든다 -> 자주 쓸 경우 퍼포먼스 저하
		//2. private대신 protected로 바꾼다.
	}
};

int main() {
	
}