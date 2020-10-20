#include <iostream>
#include <string>
using namespace std;
//방어적 프로그래밍의 개념 Defensive Programming
//사용자가 어떻게 사용하든 정상적으로 운영되도록

int main() {
	// Syntax Error 문법오류
	// int x //세미콜론의  부재

	// Semantic Errors 문맥, 의미 오류
	int  x;
	cin >> x;
	if (x >= 5) //5이상인 경우
		cout << "x is greater than 5" << endl;//5초과인 경우
	//논리적인 오류, 설계자가 아니면 알기 힘듦

	// Violated Assumption 가정위반
	// 사용자가 내가 작성한 방식과 완전 다르게 프로그램 사용
	string hello = "hello, my name is Jack jack";
	int ix;
	cin >> ix;
	cout << hello[ix] << endl;
	//string 범위 초과하여 ix 를입력한 경우엔 runtime error

	cout << "Input from 0 to " << hello.size() - 1 << endl; //미리 범위 명시,,그래도 좀..
	//오류를 미리 검사(방어적 프로그래밍), 안전장치를 마련해두어야 함
	//컴파일러가 오류를 방지할 수 있도록
	while (true) {
		int ix;
		cin >> ix;
		if (ix >= 0 && ix <= hello.size() - 1) {
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}

}