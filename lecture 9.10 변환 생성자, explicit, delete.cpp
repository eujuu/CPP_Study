#include <iostream>
#include <cassert> //assert.h
#include <array>
using namespace std;
// 변환 생성자 Converting Constructor, explicit,delete
// 프로그래머의 편의를 위한 변환 생성자
// explicit: 변환생성자를 사용 못하도록 함
// delete  : 특정한 생성자를 사용하지 못하도록 지워버림(동적할당이랑 다른 delete)
class Fraction {
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(char) = delete;//char는 사용하지 못하게 delete

	explicit Fraction(int  num = 0, int den = 1) //더 엄격하게 하라고 하는 것, convertin constructor로써의 기능 불가
		: m_numerator(num), m_denominator(den) {
		assert(den != 0);
	}

	Fraction(const Fraction& fraction)  
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy Constructor called" << endl;
	}
	friend ostream& operator << (ostream& out, const Fraction& f) {
		cout << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};
void doSomething(Fraction frac) {
	cout << frac << endl;
}
int main() {
	Fraction frac(7);

	//모두 가능
	doSomething(frac);
	doSomething(Fraction(7));
	//doSomething(7); //explicit생성자일 경우 사용 불가능,

	Fraction frac2('c'); //delete에서 사용 불가, delete가 아닐경우 c의 아스키값인 99가 들어감
}