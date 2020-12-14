#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
#include "Cents.h"
using namespace std;
// 함수 템플릿 Templates
// 단순작업 줄이기
// 여러가지 자료형에 대해 반복해서 작성하는 경우

template<typename T> //typename 또는 class라고 적음(크게차이나지않음)
T getMax2(T x, T y) {
	//컴파일러가 T자리에 무슨 타입이 들어갈지 찾아냄
	return (x > y) ? x : y;
}

// 의미없는 반복작업!!
int getMax(int x, int y) {
	return (x > y) ? x : y;
}
int getMax(double x, double y) {
	return (x > y) ? x : y;
}
int getMax(float x, float y) {
	return (x > y) ? x : y;
}
int getMax(char x, char y) {
	return (x > y) ? x : y;
}

 

int main() {
	//1. built-in datatype
	//template으로 만든 function -> 실제로 만드는 것을 instantiation이라고 함
	cout << getMax2(1, 2) << endl; // 컴파일러가 T대신 int를 넣어줌
	cout << getMax2(3.14, 1.592) << endl;
	cout << getMax2(1.0f, 3.4f) << endl;
	cout << getMax2('a', 'b') << endl;

	//2. User-defined Datatype
	cout << getMax2(Cents(5), Cents(7)) << endl; //Template 작동시에도 필요한 기능은 모두 구현되어있어야 함(여기서는 ( <<와 > )



}