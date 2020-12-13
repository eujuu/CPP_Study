#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
using namespace std;
// 동적 형변환 Dynamic Casting
// 부모클래스의 포인터로 바꿔주고 다시 자식클래스의 포인터로 바꿔주는 경우

class Base {
public:
	int m_i = 0;

	virtual void print() {
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base {
public:
	int m_j = 1024;

	virtual void print() override {
		cout << "I'm derived" << endl;
	}
};

class Derived2 : public Base {
public:
	string m_name = "Dr. Two";

	virtual void print() override {
		cout << "I'm derived" << endl;
	}
};

int main() {
	Derived1 d1;
	Base* base = &d1;

	auto* base_to_d1 = dynamic_cast<Derived1*>(base);//동적형변환
	//base에는 없고 derived1에만 있는 것들(base가 m_j로 접근 불가)을 접근하려 할 때
	//base를 다시 derived1로 바꾸어야할 때
	
	cout<< base_to_d1->m_j << endl;

	//Derived2로 강제형변환 -> 안됨! 런타임에 에러체크
	// ** Dynamic Cast는 cast 실패시 null pointer를 넣어줌 -> 아무런 값이 안나옴

	auto* base_to_d2 = dynamic_cast<Derived2*>(base);//동적형변환
	if (base_to_d2 != nullptr)
		cout << base_to_d2->m_name << endl;
	else
		cout << "failed" << endl;


	//Static cast도 사용가능
	auto* base_to_d3 =static_cast<Derived1*>(base);//동적형변환
	if (base_to_d3 != nullptr)
		base_to_d3->print();
	else
		cout << "Failed" << endl;

	//Static cast도 사용가능 -> static은 런타임에서 에러체크를 안함 ->그냥 되는대로 넣어줌
	// 여기서는 그래서 성공하게됨
	auto* base_to_d4 = static_cast<Derived2*>(base);//동적형변환
	if (base_to_d4 != nullptr)
		base_to_d4->print();
	else
		cout << "Failed" << endl;
}