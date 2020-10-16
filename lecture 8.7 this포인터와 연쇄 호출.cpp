#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
// this �����Ϳ� ���� ȣ��(Chaining member Functions)
// class �� �ؾ�� ���� Ʋ�� ����!
// �ν��Ͻ����� ��� ������ ���ΰ�??

class Simple {
private:
	int m_id;
public:
	Simple(int id) {
		this -> setID(id); //�׳� setID(id)�� ����, this->�¼����� ����
		//���� �ּ�(this)�� ���� �ִ� �ν��Ͻ����� setID�� �����Ѵ�.
		//(*this).setID(id);
		this->m_id; //���� �ּ�(this)�� ���� �ִ� �ν��Ͻ����� m_id�� �����Ѵ�.

		//cout << this << endl; //�ڱ� �ڽ��� �ּ� ���
	}
	//s1�� s2�� �� �Լ����� ���� ����? �װ� �ƴ�. �ߺ��ؼ����
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
	//Simple::setID(&s1, 1));//����� �̷���
	//Simple::setID(&s2, 4));

	Calc cal(10);
	cal.add(10);
	cal.sub(1);
	cal.mult(2); //�̷��� �ϸ� ������!!
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