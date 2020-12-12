#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
using namespace std;
// 객체 잘림(object slicing)과 reference_wrapper
// 부모보다 자식 클래스가 더 많은 정보를 갖고잇음

// 객체를 강제로대입하면?  -> 자식클래스에만 있는 정보들은 잘려서사라짐 = 객체잘림
// reference wrapper-> 이를 방지

class Base {
public:
	int m_i = 0;

	virtual void print() {
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base {
public:
	int m_j = 1;

	virtual void print() override {
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base b) {
	b.print();
}

int main() {
	Derived d;
	Base b = d;
	Base b1;

	b.print(); 
	//(&사용시)derived 출력
	//(&사용X,복사대입)base 출력-> 다형성이 사라짐

	doSomething(d); 
	//(파라미터에 &사용시)derived출력, 다형성구현
	//(파라미터에 &사용X)base출력, 다형성 구현X

	//vector<Base>my_vec;
	//vector<Base&>my_vec;  //vector는 레퍼런스 & 사용 불가능
	vector<Base*>my_vec;

	my_vec.push_back(&b1);
	my_vec.push_back(&d);

	for (auto& ele : my_vec) {
		//ele.print(); //base일때
		ele->print();
	}
	//base, base출력 -> derived를 넣었지만, push back과정에서 slicing이 발생해서  둘 다 base가됨
	//(포인터사용) base, derived  출력

	vector<reference_wrapper<Base>> my_vec2; //reference를 저장하는 벡터가 됨

	my_vec2.push_back(b1);
	my_vec2.push_back(d);

	for (auto& ele : my_vec2) {
		ele.get().print(); //reference로 부터 받아옴(get)
	}
	//base, derived 출력
}