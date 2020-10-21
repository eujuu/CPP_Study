#include <iostream>
#include <string>
using namespace std;
//친구 함수와 클래스
//클래스간의 상호작용
//Encapsulaton 유지를 위해 friend를 이용

class B; //전방 선언
class A {
private:
	int m_val = 1;

	friend void doSomething(A & a, B& b);
	//클래스의 friend function -> 특정클래스의 private멤버 접근 가능
	//클래스 A구현시에는 클래스 B의 존재에 대해 알지 못함(Syntax Error)-> 전방선언(forward declaration)해주기

	friend class B; //다른 클래스의 function접근(class통째로 열어줌)
	//friend void B::doSomething2(A& a); //member function에만 접근 허용

};

class B {
private:
	int m_val = 2;
	friend  void doSomething(A& a, B& b);
public:
	//다른 클래스가 내 function 접근
	void doSomething2(A& a) {
		cout << a.m_val << endl;
	}
};

void doSomething(A& a, B& b) {
	cout << a.m_val << " " << b.m_val << endl;
	// 꼭 클래스 밖에서 접근해야 하는 경우가 있다면 이 함수를 클래스의 friend 로 선언
}
int main() {
	A a; B b;
	doSomething(a, b);
	b.doSomething2(a);
}