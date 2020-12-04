#include <iostream>
#include <string>
using namespace std;
// 가상 기본 클래스와 다이아몬드 문제

//다이아몬드구조 -> A가 두 개가 생기는 문제가 발생 B1의 부모인 A와 B2의 부모인 A가 다르게 됨
/*
class A {};
class B1 :public A {};
class B2 :public A {};
class C :public B1, public B2 {};
*/

// B1의 부모인 A와 B2의 부모인 A가 같게 하려면(가상 기본 클래스)
/*
class A {};
class B1 : virtual public A {};
class B2 : virtual public A {};
class C : public B1, public B2 {};
*/

class PoweredDevice {
public:
	int m_i;

	PoweredDevice(int power) {
		cout << "Powered Device: " << power << "\n";
	}
};

class Scanner : virtual public PoweredDevice {
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << "\n";
	}
};

class Printer : virtual public PoweredDevice {
public:
	Printer(int printer, int power)
		:PoweredDevice(power)
	{
		cout << "Printer: " << printer << "\n";
	}
};

class Copier : public Scanner, public Printer {
public:
	Copier(int scanner, int printer, int power)
		:Scanner(scanner, power) , Printer(printer, power)
		, PoweredDevice(power) //virtual 사용시 작성
	{
		
	}
};
int main() {
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;
	// (virtual이 없으면) PoweredDevice 두 번 호출, 위 주소가 각각 다름
	// (virtual이 있으면) PoweredDevice 한 번 호출, 위 주소가 각각 같음

}