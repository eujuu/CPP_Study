#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
using namespace std;
// 유도클래스에서 출력 연산자 사용하기
// 모든 경우에서 다형성 사용 불가 -> 출력연산자!(오버라이딩 불가)

class Base {
public:
	Base() {}

	friend ostream& operator << (ostream& out, const Base& b)  { //멤버아님 -> 오버라이딩 불가
		//자식클래스는 이걸  가지고있을  필요가 없음
		return b.print(out);
	}
	virtual ostream& print(ostream& out) const { //일을 대신 해준다
		out << "Base";
		return out;
	}
};

class Derived : public Base {
public:
	Derived() {}

	virtual ostream& print(ostream& out) const override {
		out << "Derived";
		return out;
	}
};



int main() {
	Base b;
	cout << b << endl; //Base

	Derived d;
	cout << d << endl; //Derived

	Base& bref = d;
	cout << bref << endl;//Derived
}