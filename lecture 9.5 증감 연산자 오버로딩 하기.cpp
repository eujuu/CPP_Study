#include <iostream>

using namespace std;
// 증감 연산자 오버로딩 (++, --)
// 전위형(prefix), 후위형(postfix)냐에 따라서 성질이 많이 다름

class Digit {
private:
	int m_digit;
public:
	Digit(int digit = 0): m_digit(digit){}

	friend ostream& operator << (ostream& out, const Digit& d) {
		out << d.m_digit;
		return out;
	}

	//prefix
	Digit& operator ++ () {
		++m_digit;
		return *this; // 자기 자신을 리턴
	}
	Digit& operator -- () {
		--m_digit;
		return *this;
	}

	//postfix
	Digit operator ++ (int) { //위와 겹치므로, dummy로 int를 넣어줌
		Digit temp(m_digit); //현재값 저장
		++(*this);//실제값은 1더함
		return temp; //더하기 전의 값 저장
	}

};
int main() {
	// 증감 연산자
	int a = 10;
	cout << ++a << endl; //출력 전에 더해짐
	cout << a << endl;
	cout << a++ << endl; //출력 이후 더해짐
	cout << a << endl;

	Digit d(5);

	cout << ++d << endl;
	cout << d << endl;

	cout << d++ << endl;
	cout << d << endl;

}