#include <iostream>
#include <cassert> //assert.h
#include <string>
#include <cmath> //sin(), cos()
#include <vector>
using namespace std;
//상속의 기본 Inheritance (is-a relationship) - 1
// 객체지향에서 가장 중요
// 문법적인 측면(상속 기본, 생성자)
// 부모가 자식에게 무언가를 넘겨준다.
// 부모 클래스는 사라지지 않음. 다만 보이지 않을 뿐


class Mother { //부모, Generalized Class(여러 클래스의 공통되는 부분을 묶어준 클래스 -> 일반화된 클래스)
//protected : //private유지, 자식한테는 허용 o
private:  //private은 자식한테도 허용 x

	int m_i;

public:
	Mother() :m_i(0){}
	
	Mother(const int& i_in) //에러 -> parameter가 들어오는 생성자가 생겨 default생성자가 사라짐
		: m_i(i_in)
	{
		cout << "Mother Constructor " << endl;
	}
	
	void setValue(const int& i_in) {
		m_i = i_in;
	}
	int getValue() {
		return m_i;
	}
};
//상속
class Child : public Mother { //Child class is derived from mother class
	//Encapsulation유지
private:
	double m_d;
public:
	//생성자는 부모 클래스로부터 받은 변수와 본인만 갖고있는 변수(?)두 가지를 함께 사용하기 위함
	// +) 생성자 존재 이유 = 메모리 할당될 때 initialize하기위해(메모리 할당되고 거기에 복사해서넣어주세요 가 아님!!)
	
	//****** child 클래스가 생성이 될 때 자동으로 Mother class의 default 생성자를 같이 호출하게 됨

	Child(const int& i_in, const double& d_in)
		//:m_i(i_in),m_d(d_in) //private, protected 사용 불가 ->이 문제가 아님
		//위 방식으로는 초기화 불가 -> m_i가 메모리가 없는 상태이기에
		//initialize list사용x

		//+우아한 방법^^
		:Mother(i_in),m_d(d_in)
	{
		/*
		Mother::setValue(i_in);
		m_d = d_in;
		*/
	}

	void setValue(const int& i_in, const double& d_in) {
		//m_i = i_in; //Mother 의 변수 m_i에 접근 불가(private)
		Mother::setValue(i_in); //Mother class의 setValue 호출
		m_d = d_in;
	}
	void setValue(const double& d_in) {
		m_d = d_in;
	}
	double getValue() {
		return m_d;
	}
};
class Daughter :public Mother {

};
class Son : public Mother {

};
int main() {
	Mother mother(1024);
	//Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl; //1024

	Child child(1024, 128);
	//child.setValue(128);
	//child.setValue(128);
	child.Mother::setValue(1024);

	cout << child.getValue() << endl; //128  //mother와 똑같이 작동 -> mother의 것들을 기본적으로 사용
									  //재사용이 편리
	//child가 호출하는 getValue를 우선으로 호출,  없으면 Mother 클래스에서.
	cout << child.Mother::getValue() << endl; //1024


}