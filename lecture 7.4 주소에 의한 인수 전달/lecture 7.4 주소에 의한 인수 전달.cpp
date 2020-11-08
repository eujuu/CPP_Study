#include <iostream>
#include <cassert> //assert.h
#include <string>
#include <cmath> //sin(), cos()
#include <vector>
using namespace std;
// 주소에 의한 인수 전달(포인터 사용), Passing Arguments by Address (Call by Address)
// C-Style 코딩에서는 쓰게 됨, array를 보낼때에도 잘 쓰임
// 최근에는 reference많이 씀^^...

void foo(const int* ptr) { //주소만을 보낸다.
	//*ptr += 1;
	cout << *ptr << " " << ptr <<" " << &ptr << endl;

	//const 사용시
	//*ptr = 10; //dereferencing 값 못바꿈


}
void cal(double degrees, double* sin_out, double* cos_out) {
	*sin_out = 1.0;
	*cos_out = 2.0;
}

void printElement(int* arr, int length, const  int *  ptr) {  //arr의 값이 실제로 변화한다.
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	//[]는 de-referencing
	cout << endl;
	int x = 1;
	ptr = &x; //const 임에도 에러가 안남, 못바꾸게 하려면?
				//int * const ptr; 이라고 하면 됨!!
	cout <<"ptr: " <<  *ptr << endl;
}
int main() {
	int val = 5;
	cout << val << " " << &val << endl;

	int* ptr = &val;
	cout << &ptr << endl;
	foo(&val); //method 1
	foo(ptr);  //method 2, 이 ptr의 주소와 함수에서 쓰이는 ptr의 주소는 다르다.
				           //포인터변수도 변수임. 결국은 주소라는 값을, 값에 의한 전달로 보낸거임.. 복사가 된 것! 그래서 둘의 주소가 다름
	//foo(5);  //literal불가, const해도 불가

	double degrees = 30;
	double sin, cos;
	cal(degrees, &sin, &cos);
	cout << sin << " " << cos << endl;

	int arr[] = { 1, 2, 3, 4 };
	cout << "ptr: " << *ptr << endl;
	printElement(arr, 4, ptr);
}