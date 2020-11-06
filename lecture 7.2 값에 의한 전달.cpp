#include <iostream>
#include <cassert> //assert.h
#include <string>
using namespace std;
//���� ���� ���� Passing Arguments by Value(Call by Value)


void doSomething(int y) { // �� ����
	// (��) 1. ���ϴ� 2. �ܺη� ������ ��ġ�� �ʴ´�.(�Ű����� y�� �Լ��ȿ��� �ְ�, �Լ��� ������ ����� -> �� �ο��ִ�.)
	
	cout << "In Func " << y << " " << &y << endl;
}

int main(int argc, char* argv[]) {
	doSomething(5); //int y ���� -> �ش� �޸𸮿� 5��� ���� ���簡 �Ǿ� �ʱ�ȭ

	int x = 6; //x�� ���޵Ǵ°� �ƴ϶� 6�̶�� ���� ���޵Ǵ� ��

	cout << "In main " << x << " " << &x << endl;
	doSomething(x); //6����
	doSomething(x + 1); //7����


}