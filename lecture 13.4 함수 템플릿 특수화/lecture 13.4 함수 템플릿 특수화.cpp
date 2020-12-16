#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
#include "Storage.h"
using namespace std;
// �Լ� ���ø� Ư��ȭ Specialization

template <typename T>
T getMax(T x, T y) {
	return (x > y) ? x : y;
}
//Ư���� type�� ���ؼ� specialization
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
	//Storage.cpp�� �ִ� ������ �� -> specialization�� �˰� �Ϸ���?
	//1. ����� �׳� �ٽ� �ִ´�.
	//2. main���� Storage.cpp�� include��Ų��. -> �ᱹ main�ڵ忡 specialization������ ���� �Ͱ� ��������
}