#include <iostream>
#include <cstdarg> //for ellipsis
using namespace std;
//산술 연산자(+, -, *, /) 오버로딩 Overloading
class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0) :m_cents(cents) {}
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }//method1

	//friend Cents operator + (const Cents& c1, const  Cents& c2); //method3, getCents()를 쓰기 싫을때
	//{return Cents(c1.getCents() + c2.getCents());	} //method4, 아예  클래스 안에 정의 쓰기

	Cents operator + (const Cents& c2) { //method5
		return Cents(this->m_cents + c2.m_cents);
	}

	//멤버 function으로만 해야하는 연산자(위와 같은 형태로만 오버로딩 가능)
	// = assignment
	// [..] subscript(array의 index)
	// (..) function call(parameter)
	// -> member selection operator
};


void add(const  Cents& c1, const Cents& c2, Cents& c_out) {//method1, 불편함
	c_out.getCents() = c1.getCents() + c2.getCents();
}

/*
Cents operator + (const Cents& c1, const  Cents& c2) { //method2, 연산자 오버로딩, getCents()함수 사용
	return Cents(c1.getCents() + c2.getCents());
}
*/
/*
Cents operator + (const Cents& c1, const  Cents& c2) { //method3, friend를 사용해서 m_cents에 바로 접근
	return Cents(c1.m_cents + c2.m_cents);
}*/

int main() {
	Cents cents1(6);
	Cents cents2(8);

	Cents sum;
	add(cents1, cents2, sum);//method1
	cout << sum.getCents() << endl;
	//cout << cents1.getCents() + cents2.getCents() << endl;

	cout << (cents1 + cents2).getCents() << endl;//method2, 연산자 오버로딩
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;//연산자 오버로딩 + 익명객체
	cout << (cents1 + cents2 + Cents(6)+ Cents(10)).getCents()<< endl;//연산자 오버로딩 + 익명객체

	cout << (cents1 + cents2 + Cents(6) + Cents(10) + Cents(100)).getCents() << endl;//연산자 오버로딩 + 익명객체

	// ? :(조건 연산자, 삼항연산자) 오버로딩 불가
	// size of도 오버로딩 불가
	// ::(scope 연산자) 오버로딩 불가
	// . member selection 오버로딩 불가
	// .* member  pointer selection 오버로딩 불가
	// ^ 연산자 우선순위가 매우 낮음 -> 사용하려면 괄호로 싸서 사용해야함, 그래서 그냥 오버로딩 안하는게 편함^^

	// 연산자 우선순위는 수정 불가. 기존의 연산자 우선순위보다 내가 만든건 당근 우선 순위 낮음
	// 위험한건 그냥 함수만들어서 쓰세요

}