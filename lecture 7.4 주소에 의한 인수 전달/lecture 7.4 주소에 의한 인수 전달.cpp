#include <iostream>
#include <cassert> //assert.h
#include <string>
#include <cmath> //sin(), cos()
#include <vector>
using namespace std;
// �ּҿ� ���� �μ� ����(������ ���), Passing Arguments by Address (Call by Address)
// C-Style �ڵ������� ���� ��, array�� ���������� �� ����
// �ֱٿ��� reference���� ��^^...

void foo(const int* ptr) { //�ּҸ��� ������.
	//*ptr += 1;
	cout << *ptr << " " << ptr <<" " << &ptr << endl;

	//const ����
	//*ptr = 10; //dereferencing �� ���ٲ�


}
void cal(double degrees, double* sin_out, double* cos_out) {
	*sin_out = 1.0;
	*cos_out = 2.0;
}

void printElement(int* arr, int length, const  int *  ptr) {  //arr�� ���� ������ ��ȭ�Ѵ�.
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	//[]�� de-referencing
	cout << endl;
	int x = 1;
	ptr = &x; //const �ӿ��� ������ �ȳ�, ���ٲٰ� �Ϸ���?
				//int * const ptr; �̶�� �ϸ� ��!!
	cout <<"ptr: " <<  *ptr << endl;
}
int main() {
	int val = 5;
	cout << val << " " << &val << endl;

	int* ptr = &val;
	cout << &ptr << endl;
	foo(&val); //method 1
	foo(ptr);  //method 2, �� ptr�� �ּҿ� �Լ����� ���̴� ptr�� �ּҴ� �ٸ���.
				           //�����ͺ����� ������. �ᱹ�� �ּҶ�� ����, ���� ���� ���޷� ��������.. ���簡 �� ��! �׷��� ���� �ּҰ� �ٸ�
	//foo(5);  //literal�Ұ�, const�ص� �Ұ�

	double degrees = 30;
	double sin, cos;
	cal(degrees, &sin, &cos);
	cout << sin << " " << cos << endl;

	int arr[] = { 1, 2, 3, 4 };
	cout << "ptr: " << *ptr << endl;
	printElement(arr, 4, ptr);
}