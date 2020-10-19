#include <iostream>
#include <string>
using namespace std;
//정적 멤버 변수 static
int generateID() {
	static int s_id = 0;
	return ++s_id;
}
class Something {
public:
	static int s_val; //가능
	//static 멤버 변수는 초기화 불가능 //static int m_val =1;  불가능
	static const int s_val2 = 1;//가능
	//static const일 경우 무조건 초기화 해줘야 함(이후 변경은 불가능)
	static  constexpr int s_val3 = 1; //가능
	//constexpr는 컴파일시에 확실히 결정 되어야 함
};

int Something::s_val = 1; //이렇게 해줘야 함(중복선언 문제)
//static member의 경우 cpp파일 안에 정의해야함(헤더에 정의시 컴파일 에러)
// -> 정의는 한 곳에 있어야 한다는 원칙에 위배되므로 중복선언 문제

//int Something::s_val2 = 3; //const일 경우 대입 불가능

int main() {
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << Something::s_val << " " << &Something::s_val << endl;  //static이기에 메모리에 정적으로 존재, 인스턴스가 없어도 주소를 가짐
	Something st1;
	Something st2;
	st1.s_val = 2;

	cout << st1.s_val << "  " << &st1.s_val << endl;
	cout << st2.s_val << "  " << &st2.s_val << endl;
	//static -> 변수의 주소 일치
	Something::s_val = 1024;
	cout << Something::s_val << " " << &Something::s_val << endl;
}