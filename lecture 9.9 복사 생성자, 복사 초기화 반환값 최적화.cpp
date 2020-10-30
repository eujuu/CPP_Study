#include <iostream>
#include <cassert>
using namespace std;
// 복사 생성자, 복사 초기화 RVO(Return Value Optimization)

class Fraction {
private:
	int m_numerator;
	int m_denominator;

	//복사 막으려면 private으로 옮기기, 외부에서 사용 불가
	/*
	Fraction(const Fraction& fraction)  //copy constructor, 자기 자신과 똑같이 생긴 인스턴스 타입이 들어오는 것
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy Constructor called" << endl;
	}
	*/

public:
	Fraction(int  num = 0, int den = 1) : m_numerator(num), m_denominator(den) {
		assert(den != 0);
	}

	Fraction(const Fraction& fraction)  //copy constructor, 자기 자신과 똑같이 생긴 인스턴스 타입이 들어오는 것
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
	cout << &tmp << endl; //디버그 모드에선 이 주소와 아래의 주소가 다름 -> 복사를 해야만 함
	return tmp;
}

int main() {

	Fraction frac(3, 5);

	cout << frac << endl;

	Fraction fr_copy(frac);
	cout << fr_copy << endl;

	//이 경우에는 복사 생성자가 호출 안 됨. 컴파일러가 Fraction(3,10)대신 (3,10)으로 생략해서 넣어준 것
	Fraction fr_copy2(Fraction(3, 10)); 
	cout << fr_copy2 << endl;

	//release mode에서는 copy constructor가 아님 -> 컴파일러가 반환값 최적화를 해줌(디버그 모드에서는 안해줌)
	Fraction result = doSomething();
	cout << &result << endl; //릴리즈 모드에서는 주소가 같음, 그냥 해당 인스턴스가 그대로 이동한 것.
	cout << result << endl;



}