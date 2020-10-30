#include <iostream>
#include <cassert>
using namespace std;
// ���� ������, ���� �ʱ�ȭ RVO(Return Value Optimization)

class Fraction {
private:
	int m_numerator;
	int m_denominator;

	//���� �������� private���� �ű��, �ܺο��� ��� �Ұ�
	/*
	Fraction(const Fraction& fraction)  //copy constructor, �ڱ� �ڽŰ� �Ȱ��� ���� �ν��Ͻ� Ÿ���� ������ ��
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy Constructor called" << endl;
	}
	*/

public:
	Fraction(int  num = 0, int den = 1) : m_numerator(num), m_denominator(den) {
		assert(den != 0);
	}

	Fraction(const Fraction& fraction)  //copy constructor, �ڱ� �ڽŰ� �Ȱ��� ���� �ν��Ͻ� Ÿ���� ������ ��
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy Constructor called" << endl;
	}
	friend ostream& operator << (ostream& out, const Fraction& f) {
		cout << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

Fraction doSomething() {
	Fraction tmp(1, 2);
	cout << &tmp << endl; //����� ��忡�� �� �ּҿ� �Ʒ��� �ּҰ� �ٸ� -> ���縦 �ؾ߸� ��
	return tmp;
}

int main() {

	Fraction frac(3, 5);

	cout << frac << endl;

	Fraction fr_copy(frac);
	cout << fr_copy << endl;

	//�� ��쿡�� ���� �����ڰ� ȣ�� �� ��. �����Ϸ��� Fraction(3,10)��� (3,10)���� �����ؼ� �־��� ��
	Fraction fr_copy2(Fraction(3, 10)); 
	cout << fr_copy2 << endl;

	//release mode������ copy constructor�� �ƴ� -> �����Ϸ��� ��ȯ�� ����ȭ�� ����(����� ��忡���� ������)
	Fraction result = doSomething();
	cout << &result << endl; //������ ��忡���� �ּҰ� ����, �׳� �ش� �ν��Ͻ��� �״�� �̵��� ��.
	cout << result << endl;



}