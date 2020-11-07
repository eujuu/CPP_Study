#include <iostream>
#include <cassert> //assert.h
#include <string>
#include <cmath> //sin(), cos()
#include <vector>
using namespace std;
// 참조에 의한 인수 전달 Passing Arguments by Reference (Call by Reference)

typedef int* pint;
//void foo(int& x) {
void foo(int *&x){ // (int*)&x 이렇게 되어있다고 생각하면 편함 
//void foo(pint &x){ // 이렇게 써도 됨
	cout << "In Func: " << x << " " << &x <<  endl;
}

//C, C++ 은 리턴값 하나만..
void getSinCos(const double &degrees, double& sin_out, double& cos_out) {
	// degrees : 입력 (const를 이용하여 바뀌지않음을 간접적으로 표시)
	// sin_out, cos_out : 출력
	static const double pi = 3.141592;

	const double radians = degrees * pi / 180.0; //바뀌지 않을 것은 꼭 const!

	sin_out = sin(radians);
	cos_out = cos(radians);


}
void addOne(int& y) {
	//레퍼런스 전달시 값도 같이 그대로 바뀜
	//x와 y는 동일
	//주소가 동일
	// call by value와 달리 복사가 이루어지지 않음
	cout <<"In Func: "<< y << " " << &y<< endl;

	y = y + 1;

}
//void printElement(const vector<int>&arr){
void printElement(int(&arr)[4]) {
	//대괄호 []안에 element갯수 필
	// 원래 array를 보낼 땐 정적 array보다 동적 array를 보낼 때가 많음 -> 그래서 클래스 쓰는경우 많음
	// 아니면 벡터
	for (int i=0; i< 4; i++)
		cout << arr[i] << " ";
	cout << endl;

}
int main() {
	int x = 5;
	cout <<  x << " " << &x << endl;

	addOne(x); //매개변수로 함수 자체를 인자로써 전달
	cout << x << " " << &x << endl;

	double sin(0.0);
	double cos(0.0);
	getSinCos(30.0, sin, cos);
	cout << sin << " " << cos << endl;

	//레퍼런스로 받아야하는데 literal은 주소가 없기때문에 이렇게 불가능
	// 1. 매개변수의 &를 없애기 2. const 붙이기
	// foo(6);

	//포인터에 대한 레퍼런스
	int y = 5;
	int* ptr = &y;
	cout << "In main: " << ptr << " " << &ptr << endl;

	foo(ptr);

	//array를 파라미터로 전달
	int arr[]{ 1, 2, 3, 4 };
	vector<int>arr2{ 1 ,2, 3, 4 };
	printElement(arr);
}