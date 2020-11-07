#include <iostream>
#include <cassert> //assert.h
#include <string>
#include <cmath> //sin(), cos()
#include <vector>
using namespace std;
// ������ ���� �μ� ���� Passing Arguments by Reference (Call by Reference)

typedef int* pint;
//void foo(int& x) {
void foo(int *&x){ // (int*)&x �̷��� �Ǿ��ִٰ� �����ϸ� ���� 
//void foo(pint &x){ // �̷��� �ᵵ ��
	cout << "In Func: " << x << " " << &x <<  endl;
}

//C, C++ �� ���ϰ� �ϳ���..
void getSinCos(const double &degrees, double& sin_out, double& cos_out) {
	// degrees : �Է� (const�� �̿��Ͽ� �ٲ��������� ���������� ǥ��)
	// sin_out, cos_out : ���
	static const double pi = 3.141592;

	const double radians = degrees * pi / 180.0; //�ٲ��� ���� ���� �� const!

	sin_out = sin(radians);
	cos_out = cos(radians);


}
void addOne(int& y) {
	//���۷��� ���޽� ���� ���� �״�� �ٲ�
	//x�� y�� ����
	//�ּҰ� ����
	// call by value�� �޸� ���簡 �̷������ ����
	cout <<"In Func: "<< y << " " << &y<< endl;

	y = y + 1;

}
//void printElement(const vector<int>&arr){
void printElement(int(&arr)[4]) {
	//���ȣ []�ȿ� element���� ��
	// ���� array�� ���� �� ���� array���� ���� array�� ���� ���� ���� -> �׷��� Ŭ���� ���°�� ����
	// �ƴϸ� ����
	for (int i=0; i< 4; i++)
		cout << arr[i] << " ";
	cout << endl;

}
int main() {
	int x = 5;
	cout <<  x << " " << &x << endl;

	addOne(x); //�Ű������� �Լ� ��ü�� ���ڷν� ����
	cout << x << " " << &x << endl;

	double sin(0.0);
	double cos(0.0);
	getSinCos(30.0, sin, cos);
	cout << sin << " " << cos << endl;

	//���۷����� �޾ƾ��ϴµ� literal�� �ּҰ� ���⶧���� �̷��� �Ұ���
	// 1. �Ű������� &�� ���ֱ� 2. const ���̱�
	// foo(6);

	//�����Ϳ� ���� ���۷���
	int y = 5;
	int* ptr = &y;
	cout << "In main: " << ptr << " " << &ptr << endl;

	foo(ptr);

	//array�� �Ķ���ͷ� ����
	int arr[]{ 1, 2, 3, 4 };
	vector<int>arr2{ 1 ,2, 3, 4 };
	printElement(arr);
}