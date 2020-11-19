#include <iostream>
#include <string>
using namespace std;
// 가상함수 Virtual Functions 와 다형성 Polymorphism

class A {
public: 
	 virtual void print() { cout << "A" << endl; }
	 //virtual table을 보면서 찾아가는 과정 -> 느림 -> 호출이 빈번한 함수에 쓰는건 좋지 않음
};

class B : public A {
//class B{
public:
	void print() { cout << "B" << endl; } //virtual일 경우 본인 것을 사용
};

class C : public B {
public: 
	void print() { cout << "C" << endl; } 
	//A를 직접 상속받은 것이 아니어도, A의 레퍼런스를 통해 print호출했을때 직접 본인걸 사용
	//B가 virtual이 아니어도. 
	//가장 상위 클래스가 virtual이면 밑에 있는 것들도 다 virtual처럼 행동
	//그래서 관습적으로 하위 클래스들도 virtual키워드를 적어두는 경우 많음
};

class D : public C {
public: 
	//overriding의 return type이 다르다면?
	// -> A와 달라 컴파일 불가(맨 위에 있는거 중심으로 정함)
	/*int*/ void print() { cout << "D" << endl; return 0; }
};
int main() {

	A a;
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();

	//포인터 바꿔주기
	B& ref = c;
	ref.print();

}