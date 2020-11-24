#include <iostream>
#include <string>
using namespace std;
// ���� ���ε��� ���� ���ε�
// �����Լ��� �̿��ϴ� �������� ��� ���������� �۵��ϴ��� �����Ϸ���?? �� ���̸� �����ϸ� ��

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
	//���ӿ����� ��� �����ϰ� ���ؾ��ϱ� ������ �������ε� �ʼ�!!
	int(*func_ptr)(int, int) = nullptr; //��������

	switch (op) {
	case 0: func_ptr = add; break;
	case 1: func_ptr = sub; break;
	case 2: func_ptr = mul; break;
	}
	cout << func_ptr(x, y) << endl;

	/*
	�ӵ�: static > Dynamic
	-> �������ε� : �� ������
	-> �������ε� : function pointer �־��ֱ� + ����ÿ��� �ּҸ� Ÿ�� ���� ��
	*/
}