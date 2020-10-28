#include <iostream>
#include <cassert>
using namespace std;
// 괄호 연산자((), parenthesis) 오버로딩과 함수 객체(Function object, Functor)
// 괄호 연산자는 특징 상 함수 호출 괄호와 동일

class Accumulator {
private:
	int m_counter = 0;
public:
	int operator()(int i) { return (m_counter += i); } //함수로도 구현 가능(Functor)
	// 첨자 오버로딩 방법과 유사
	// 함수 객체처럼 사용
};
int main() {
	Accumulator acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl; //chaining도 구현 가능

}