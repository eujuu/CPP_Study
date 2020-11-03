#include <iostream>
#include <cassert> //assert.h
#include <array>
using namespace std;
//�̴ϼȶ����� ����Ʈ std::initializer_list
// ����� ���� �ڷ�������, ���� �ʱ�ȭ
class IntArray {
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length) : m_length(length) {
		m_data = new int[length]; //���̸� �Է¹����� �޸𸮸� ����ִ� ������
	}

	//�̴ϼȶ����� ����Ʈ ������
	IntArray(const std::initializer_list <int>& list) 
		:IntArray(list.size())  //���⼭ ���� �����ڸ� ȣ���ؼ� �޸𸮸� �޾��ְ� ����
	{
		int cnt = 0;
		for (auto& element : list) {
			m_data[cnt++] = element;
		}
		//for (unsigned count = 0; count < list.size(); ++count) 
		//	m_data[count] = list[count]; //error, �̴ϼȶ����� ����Ʈ�� ���ȣ [] ���x

	}
	//�̴ϼȶ���������Ʈ ���� ���Կ����ڵ� ���� overload���ִ°� ����
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

	IntArray int_array { 1,2,3,4, 5 };//�̴ϼȶ����� ����Ʈ ������ ���
	int_array = { 2, 3, 4, 5,6 };
	cout << int_array << endl; 
}