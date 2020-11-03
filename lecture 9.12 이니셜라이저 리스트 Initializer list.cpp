#include <iostream>
#include <cassert> //assert.h
#include <array>
using namespace std;
//이니셜라이저 리스트 std::initializer_list
// 사용자 정의 자료형에서, 값을 초기화
class IntArray {
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length) : m_length(length) {
		m_data = new int[length]; //길이만 입력받으면 메모리를 잡아주는 생성자
	}

	//이니셜라이저 리스트 생성자
	IntArray(const std::initializer_list <int>& list) 
		:IntArray(list.size())  //여기서 위의 생성자를 호출해서 메모리를 받아주고 있음
	{
		int cnt = 0;
		for (auto& element : list) {
			m_data[cnt++] = element;
		}
		//for (unsigned count = 0; count < list.size(); ++count) 
		//	m_data[count] = list[count]; //error, 이니셜라이저 리스트는 대괄호 [] 사용x

	}
	//이니셜라이저리스트 사용시 대입연산자도 같이 overload해주는게 좋다
	IntArray& operator = (const IntArray& arr) {
		this->m_data = arr.m_data;
		this->m_length = arr.m_length;
		return *this;
	}
	friend ostream& operator << (ostream& out, IntArray& arr){
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}
};
int main() {
	int  my_arr1[5] = { 1, 2, 3, 4, 5 };
	int* my_arr2 = new int[5]{ 1, 2,  3, 4, 5 };
	auto il = { 10,20,30 };

	IntArray int_array { 1,2,3,4, 5 };//이니셜라이저 리스트 생성자 사용
	int_array = { 2, 3, 4, 5,6 };
	cout << int_array << endl; 
}