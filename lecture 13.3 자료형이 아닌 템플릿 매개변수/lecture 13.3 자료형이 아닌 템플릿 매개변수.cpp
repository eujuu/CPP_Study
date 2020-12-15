#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
#include "MyArray.h"
using namespace std;
// 자료형이 아닌 템플릿 매개변수 Non-type Parameters


int main() {
	MyArray<double, 100> my_arr; //Non-type Parameter
	// == vector<double> my_arr; my_arr.resize(100);
	// == MyArray<double> my_arr(100);

	for (int i = 0; i < my_arr.getLength(); i++)
		my_arr[i] = i + 65;

	my_arr.print();


}