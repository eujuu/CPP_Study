#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
#include "Cents.h"
using namespace std;
// �Լ� ���ø� Templates
// �ܼ��۾� ���̱�
// �������� �ڷ����� ���� �ݺ��ؼ� �ۼ��ϴ� ���

template<typename T> //typename �Ǵ� class��� ����(ũ�����̳�������)
T getMax2(T x, T y) {
	//�����Ϸ��� T�ڸ��� ���� Ÿ���� ���� ã�Ƴ�
	return (x > y) ? x : y;
}

// �ǹ̾��� �ݺ��۾�!!
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
	//template���� ���� function -> ������ ����� ���� instantiation�̶�� ��
	cout << getMax2(1, 2) << endl; // �����Ϸ��� T��� int�� �־���
	cout << getMax2(3.14, 1.592) << endl;
	cout << getMax2(1.0f, 3.4f) << endl;
	cout << getMax2('a', 'b') << endl;

	//2. User-defined Datatype
	cout << getMax2(Cents(5), Cents(7)) << endl; //Template �۵��ÿ��� �ʿ��� ����� ��� �����Ǿ��־�� ��(���⼭�� ( <<�� > )



}