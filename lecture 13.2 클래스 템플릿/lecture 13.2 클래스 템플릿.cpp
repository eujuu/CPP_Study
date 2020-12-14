#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
#include "MyArray.h"
//#include "MyArray.cpp" //이렇게해도 실행되지만, 나중에 프로그램이 커지면 문제가 될 수 있음
using namespace std;
// 클래스 템플릿 Templates


int main() {
	//MyArray my_arr(10);	//parameter에 들어갈 argument가 설정 안됨
	MyArray<double >my_arr(10); 
	//instantiation 필요하다는건 앎
	//main에서는 print함수를 컴파일 할 때는, MyArray.cpp의 내용을 모른다.
	// => MyArray.cpp에서 print함수 실행시 어떤 타입으로 컴파일 해야할지 모르는 경우 발생

	// ***explicit instantiation 필요
	// 1. 함수를 explicit instantiation'
	// 2. 클래스를 explicit instatiation

	for (int i = 0; i < my_arr.getLength(); ++i) {
		my_arr[i] = i +65;
	}

	my_arr.print();

}