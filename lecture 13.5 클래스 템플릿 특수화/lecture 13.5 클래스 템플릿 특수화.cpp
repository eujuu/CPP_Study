#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <functional> //reference_wrapper
#include "Storage8.h"
using namespace std;
// Ŭ���� ���ø� Ư��ȭ Specialization

template<typename T>
class A {
public:
	A(const T& input){}
	void doSomething(){
		cout << typeid(T).name() << endl;
	}
	void test() {

	}

};

//char type specialization
template<> 
class A<char> {
public:
	A(const char& temp) {}
	void doSomething() {
		cout << "Char type specialization" << endl;
	}
	//test member function�� ����->a_char.test()���Ұ�
};



int main() {
	A<int>		a_int(1); //instantiation
	A<double>	a_double(3.14);
	A<char>		a_char('a');
	//c++17�̻󿡼��� A a_int(1);��  �ص� �� -> �Ķ���ͷ� ���� ���� �����ϱ⶧��

	a_int.test();
	a_double.test();
	//a_char.test();


	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	//Storage8 for integers
	Storage8 <int> intStorage;
	for (int cnt = 0; cnt < 8; cnt++)
		intStorage.set(cnt, cnt);

	for (int cnt = 0; cnt < 8; cnt++)
		cout << intStorage.get(cnt) << endl;

	cout << "Size of Storage8<int> " << sizeof(Storage8<int>) << endl;

	//Storage8 for bool
	Storage8 <bool> boolStorage;
	for (int cnt = 0; cnt < 8; cnt++)
		boolStorage.set(cnt, cnt & 3);

	for (int cnt = 0; cnt < 8; cnt++)
		cout << (boolStorage.get(cnt) ? "True" : "False") << endl;

	cout << "Size of Storage8<bool> " << sizeof(Storage8<bool>) << endl;
	//specialization ���� �� ũ�� = 1
	//specialization ������ �� ũ�� = 8


}