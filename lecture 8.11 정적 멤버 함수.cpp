#include <iostream>
#include <string>
using namespace std;
//정적 멤버 함수 static

class Something {
public:
	class _init {
	public:
		_init() {
			s_val = 9876; //내부클래스여서 접근 가능
		}
	};

private:
	static int  s_val;
	int m_val=10;
	static _init s_initializer;

public:
	//static member variable를 constructor에서 초기화 불가능
	//C++에서는 static 생성자 불가
	Something():m_val(123) //,s_val(1024)
	{}

	//그러면 어떻게???-> inner class  사용(위에 내용)
	//클래스 내부에서 static 초기화 가능!(간접적으로)

//---------------------------------------------------------------------
	static int getValue() {
		//return m_val; //static은 불가(this로 접근해야하는 모든것 사용 불가, s_val은 정적으로 메모리에 존재하므로 사용 가능

		return s_val; //static은 this포인터 사용 불가
	}
	int temp() {
		return this->s_val + this->m_val; //특정 인스턴스의 주소를 받아서, 해당 인스턴스의 변수 사용
	}
};

int	Something::s_val = 1024;
Something::_init Something::s_initializer; //얘가 만들어지면서 생성자 호출, s_val 초기화


int main() {
	//cout << Something::s_val << endl; //static이기에 가능(public일 때)
	cout << Something::getValue() << endl;

	Something s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_val << endl;

	//int (Something::*fptr1)() = s1.temp; 
	//불가능, temp라는 함수는 한 군데, s1이라는 인스턴스의 member variable을 가지고 해당 함수 사용
	int (Something:: * fptr1)() = &Something::temp;

	cout << (s2.*fptr1)() << endl;

	int (* fptr2)() = &Something::getValue;
	//Something을 떼줘야 동작, getValue를 특정 인스턴스와 상관없이 실행시킬 수 있는 function pointer
	cout << fptr2() << endl;

	//function의 주소가 특정 인스턴스와 묶여 있는게 아닐까? --> no!!!
	

}