#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
// this 포인터와 연쇄 호출(Chaining member Functions)
// class 는 붕어빵을 찍어내는 틀과 같다!
// 인스턴스들을 어떻게 구분할 것인가??

class Simple {
private:
	int m_id;
public:
	Simple(int id) {
		this -> setID(id); //그냥 setID(id)와 같음, this->는숨겨져 있음
		//현재 주소(this)를 갖고 있는 인스턴스에서 setID를 실행한다.
		//(*this).setID(id);
		this->m_id; //현재 주소(this)를 갖고 있는 인스턴스에서 m_id에 접근한다.

		//cout << this << endl; //자기 자신의 주소 출력
	}
	//s1과 s2에 이 함수들이 따로 존재? 그건 아님. 중복해서사용
	void setID(int id) { m_id = id; }
	int	 getId() { return m_id; }
};

class Calc {
private:
	int m_value;
public:
	Calc(int init_val): m_value(init_val){}

	void add(int val) {		m_value += val;	}
	void sub(int val) {		m_value -= val;	}
	void mult (int val) {	m_value *= val;	}
	void print() {
		cout << m_value << endl;
	}
};

class Calc2 {
private:
	int m_value;
public:
	Calc2(int init_val) : m_value(init_val) {}

	Calc2& add(int val) { m_value += val;  return *this;}
	Calc2& sub(int val) { m_value -= val; return *this;	}
	Calc2& mult(int val) { m_value *= val; return *this;}
	void print() {
		cout << m_value << endl;
	}
};

int main() {
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	//cout << &s1 << " " << &s2 << endl;
	//Simple::setID(&s1, 1));//개념상 이런것
	//Simple::setID(&s2, 4));

	Calc cal(10);
	cal.add(10);
	cal.sub(1);
	cal.mult(2); //이렇게 하면 귀찮다!!
	cal.print();

	Calc2 cal2(10);
	cal2.add(10).sub(1).mult(2).print(); //Chaining Member Function
	/*==
	Calc2& temp1 = cal2.add(10);
	Calc2& temp2 = temp1.sub(1);
	Calc2& temp3 = temp2.mult(2);
	temp3.print();
	*/
}