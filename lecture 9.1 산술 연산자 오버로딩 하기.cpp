#include <iostream>
#include <cstdarg> //for ellipsis
using namespace std;
//��� ������(+, -, *, /) �����ε� Overloading
class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0) :m_cents(cents) {}
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }//method1

	//friend Cents operator + (const Cents& c1, const  Cents& c2); //method3, getCents()�� ���� ������
	//{return Cents(c1.getCents() + c2.getCents());	} //method4, �ƿ�  Ŭ���� �ȿ� ���� ����

	Cents operator + (const Cents& c2) { //method5
		return Cents(this->m_cents + c2.m_cents);
	}

	//��� function���θ� �ؾ��ϴ� ������(���� ���� ���·θ� �����ε� ����)
	// = assignment
	// [..] subscript(array�� index)
	// (..) function call(parameter)
	// -> member selection operator
};


void add(const  Cents& c1, const Cents& c2, Cents& c_out) {//method1, ������
	c_out.getCents() = c1.getCents() + c2.getCents();
}

/*
Cents operator + (const Cents& c1, const  Cents& c2) { //method2, ������ �����ε�, getCents()�Լ� ���
	return Cents(c1.getCents() + c2.getCents());
}
*/
/*
Cents operator + (const Cents& c1, const  Cents& c2) { //method3, friend�� ����ؼ� m_cents�� �ٷ� ����
	return Cents(c1.m_cents + c2.m_cents);
}*/

int main() {
	Cents cents1(6);
	Cents cents2(8);

	Cents sum;
	add(cents1, cents2, sum);//method1
	cout << sum.getCents() << endl;
	//cout << cents1.getCents() + cents2.getCents() << endl;

	cout << (cents1 + cents2).getCents() << endl;//method2, ������ �����ε�
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;//������ �����ε� + �͸�ü
	cout << (cents1 + cents2 + Cents(6)+ Cents(10)).getCents()<< endl;//������ �����ε� + �͸�ü

	cout << (cents1 + cents2 + Cents(6) + Cents(10) + Cents(100)).getCents() << endl;//������ �����ε� + �͸�ü

	// ? :(���� ������, ���׿�����) �����ε� �Ұ�
	// size of�� �����ε� �Ұ�
	// ::(scope ������) �����ε� �Ұ�
	// . member selection �����ε� �Ұ�
	// .* member  pointer selection �����ε� �Ұ�
	// ^ ������ �켱������ �ſ� ���� -> ����Ϸ��� ��ȣ�� �μ� ����ؾ���, �׷��� �׳� �����ε� ���ϴ°� ����^^

	// ������ �켱������ ���� �Ұ�. ������ ������ �켱�������� ���� ����� ��� �켱 ���� ����
	// �����Ѱ� �׳� �Լ����� ������

}