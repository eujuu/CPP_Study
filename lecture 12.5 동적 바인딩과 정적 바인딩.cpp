#include <iostream>
#include <string>
using namespace std;
// 동적 바인딩과 정적 바인딩
// 가상함수를 이용하는 다형성이 어떻게 내부적으로 작동하는지 이해하려면?? 위 차이를 이해하면 됨

int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}

int main() {
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0: add, 1: sub, 2: mul" << endl;
	cin >> op;

	//static binding (early binding)
	int result;
	switch (op) {
	case 0: result = add(x, y); break;
	case 1: result = sub(x, y); break;
	case 2: result = mul(x, y); break;
	}

	//Dynamic binding (late binding)
	//게임엔진의 경우 유연하게 변해야하기 때문에 동적바인딩 필수!!
	int(*func_ptr)(int, int) = nullptr; //안정해짐

	switch (op) {
	case 0: func_ptr = add; break;
	case 1: func_ptr = sub; break;
	case 2: func_ptr = mul; break;
	}
	cout << func_ptr(x, y) << endl;

	/*
	속도: static > Dynamic
	-> 정적바인딩 : 딱 정해짐
	-> 동적바인딩 : function pointer 넣어주기 + 실행시에도 주소를 타고 가야 함
	*/
}