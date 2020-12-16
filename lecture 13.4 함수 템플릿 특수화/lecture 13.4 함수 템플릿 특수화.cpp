#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
#include "Storage.h"
using namespace std;
// 함수 템플릿 특수화 Specialization

template <typename T>
T getMax(T x, T y) {
	return (x > y) ? x : y;
}
//특수한 type에 대해서 specialization
template <>
char getMax(char x, char y) {
	cout << "Warning : Comparing chars" << endl;
	return (x > y) ? x : y; 
}

int main() {
	cout << getMax(1, 2) << endl;
	// == getMax<int>(1,2)

	cout << getMax('a', 'b') << endl;

	Storage <int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();
	//Storage.cpp에 있는 내용을 모름 -> specialization을 알게 하려면?
	//1. 헤더에 그냥 다시 넣는다.
	//2. main에서 Storage.cpp를 include시킨다. -> 결국 main코드에 specialization내용을 넣은 것과 마찬가지
}