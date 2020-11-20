#include <iostream>
#include <string>
using namespace std;
// override, final 지정자, 공변covariant 반환형


class A {
public: 
	/*virtual*/  void print(int x) { cout << "A" << endl; }
	 virtual A* getThis() { 
		 cout << "A::getThis()" << endl; 
		 return this; 
	 }
	 //covariant return type
};

class B : public A {
//class B{
public:
	void print(/*short*/ int x)  { cout << "B" << endl; } 
	//만약 실수로 타입이 다른 파라미터를 넣는다면?
	//virtual이어도 A의 print함수가 호출된다.
	// -> 함수는 파라미터가 다르면 overriding을 할 수 x
	// -> overloading을 했다고 판단해서 A를 호출하게 됨
	// => 이런 상황을 피하기 위해 override지정자 사용 -> 무조건 override이어야 함을 말함 -> 다를 경우 컴파일 에러 발생

	virtual B* getThis() { 
		cout << "B::getThis()" << endl; 
		return this;
	}
	//일반적으로 리턴타입이 다르면 override불가
	//A*와 B*가 부모자식 관계라 override 됨
};

class C : public B {
public: 
	//void print(int x) final { cout << "C" << endl; } 
	// final키워드를 쓰면 밑의 클래스들은 override를 할 수 없음
};

class D : public C {
public: 
	 //void print(int x) { cout << "D" << endl;}
	 //C에서 final 지정자를 적용했기에 에러 발생
};
int main() {

	A a;

	B b;

	C c;

	D d;

	//포인터 바꿔주기
	A& ref = b;
	ref.print(1);

	b.getThis()->print(0); //B
	ref.getThis()->print(0); //A -> B의 getThis로 들어갔지만 A가 나옴 -> ref가 A이기 때문에 다시 A의포인터로 바꾼다음에 클래스 호출


	cout << typeid(b.getThis()).name() << endl; //B*
	cout << typeid(ref.getThis()).name() << endl; //A*

}