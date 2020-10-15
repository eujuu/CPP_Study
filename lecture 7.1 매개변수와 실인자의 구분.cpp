#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//매개변수(Parameter)와 실인자(Argument)의 구분
int foo(int x, int y); //정수형 변수 x,y가 foo라는 함수의 파라미터이다.

int foo(int x, int y) { 
	//x, y선언, 초기화, argument값을 복사해서 받음
	//parameter: 함수가 어떤 기능을 하는지를 조절해주는(바꿔주는) 역할
	return x + y; //body, x와 y의 값에 따라 리턴값 변화

} //함수가 끝남과 동시에 파라미터는 사라짐(지역변수)
int main() {
	int x = 1, y = 2;

	foo(6, 7); //6, 7 : arguments (actual parameters, 실매개변수, 실인자)
	foo(x, y + 1);
	//x의 값을 전달 받아(1 = argument) 함수의 파라미터로 전달
	//argument가 parameter로 전달
}