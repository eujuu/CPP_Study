#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
#include "MyArray.h"
//#include "MyArray.cpp" //�̷����ص� ���������, ���߿� ���α׷��� Ŀ���� ������ �� �� ����
using namespace std;
// Ŭ���� ���ø� Templates


int main() {
	//MyArray my_arr(10);	//parameter�� �� argument�� ���� �ȵ�
	MyArray<double >my_arr(10); 
	//instantiation �ʿ��ϴٴ°� ��
	//main������ print�Լ��� ������ �� ����, MyArray.cpp�� ������ �𸥴�.
	// => MyArray.cpp���� print�Լ� ����� � Ÿ������ ������ �ؾ����� �𸣴� ��� �߻�

	// ***explicit instantiation �ʿ�
	// 1. �Լ��� explicit instantiation'
	// 2. Ŭ������ explicit instatiation

	for (int i = 0; i < my_arr.getLength(); ++i) {
		my_arr[i] = i +65;
	}

	my_arr.print();

}