#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//Constructors(생성자)
//만들어지자마자 이러한 속성을 가지고 있어야 해!
class Second {
public: 
	Second() {
		cout << "Class Second constructor()" << endl;
	}
};
class  First {
	Second sec;
public:
	First() {
		cout << "Class First constructor()" << endl;
	}
};
class Fraction { //분수
private:
	int m_numerator; //분자
	int m_denominator; //분모
	//2, 변수 선언시 초기화
	// int m_numerator = 0;
	// int m_denominator = 1;

public:
	// 생성자는 기본적으로 아무 일도 안하는 형태로 숨겨져 있음, 생성자가 없으면 인스턴스 생성 아예 불가
	// 생성자는 인스턴스를 만드는게 아님, 그냥 선언될때 호출되는 함수! 이름이 현혹되지 말것
	// Fraction() {} //한 개라도 생성자를 만들면 기본 생성자는 만들지 않는다.
	//3, 생성자
	Fraction() {
		m_numerator = 0;
		m_denominator = 1;
	}
	Fraction(const int &num_in /*= 0*/, const int & den_in = 1) { 
		//의도적 호출 x, 자동으로 호출이 된다.
		//클래스가 선언이 됨과 동시에 실행 된다.
		m_numerator = num_in;
		m_denominator = den_in;
		cout << "Fraction() Constructor" << endl;
	}

	void print() {
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int main() {
 	Fraction fra; //생성자 실행(메모리에 자리를 잡고 그 뒤에 바로 실행된다)
	//생성자의 파라미터가 하나도 없을 경우엔 ()를 항상 뺀다!! 디폴트 값을 이용할때에도 아무것도 안쓰면 괄호 없애야 함
	fra.print();


	Fraction oneThirds(1.0, 3); 
	// Fraction oneThirds = Fraction{1, 3}; //권장 X
	// Fraction oneThirds{1, 3}; //생성자가 있을 경우 uniform Intialization도 가능! 생성자 호출해준다!

	// unifrom Initialization = 타입 변환을 허용하지 않는다. 좀 더 엄격(copy initialization보다)
	// Fraction oneThirds{1.0, 3}; //에러
	// Fraction oneThirds(1.0, 3); //warning만 뜨고 되긴 됨
	oneThirds.print();

	//1, public 변수로 바꿔준 후 변수 지정
	//Fraction fra{ 0, 1 };
	
	First fir; //second의 생성자가 먼저 실행되고 그 다음 first의 생성자가 실행됨
	//second가 first의 member이므로, memeber를 먼저 초기화를 해주어야 first가 작업 가능!
	//그렇기에 second가 먼저!


}