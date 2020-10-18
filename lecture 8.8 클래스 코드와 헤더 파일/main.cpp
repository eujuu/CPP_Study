#include "Calc.h"
using namespace std;
//클래스 코드와 헤더 파일
//클래스는 처음부터 헤더파일에 만들어서 선언과정의를 분리한다!


int main() {
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();
	Calc(10).add(10).sub(1).mult(2).print();
}