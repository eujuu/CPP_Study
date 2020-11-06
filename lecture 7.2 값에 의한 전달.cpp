#include <iostream>
#include <cassert> //assert.h
#include <string>
using namespace std;
//값에 의한 전달 Passing Arguments by Value(Call by Value)


void doSomething(int y) { // 값 복사
	// (장) 1. 편하다 2. 외부로 영향을 끼치지 않는다.(매개변수 y는 함수안에만 있고, 함수가 끝나면 사라짐 -> 잘 싸여있다.)
	
	cout << "In Func " << y << " " << &y << endl;
}

int main(int argc, char* argv[]) {
	doSomething(5); //int y 선언 -> 해당 메모리에 5라는 값이 복사가 되어 초기화

	int x = 6; //x가 전달되는게 아니라 6이라는 값만 전달되는 것

	cout << "In main " << x << " " << &x << endl;
	doSomething(x); //6전달
	doSomething(x + 1); //7전달


}