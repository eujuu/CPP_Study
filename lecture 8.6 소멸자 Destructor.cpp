#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//�Ҹ��� Destructor
class Simple {
private:
	int m_id;
public:
	Simple(const int& id_in) : m_id(id_in) {
		cout << "Constructor " << m_id << endl;
	}
	~Simple(){
		cout << "Destructor " << m_id << endl;
	} //�Ҹ���,  �Ҹ��ڴ� �Ķ���� ����
	//�ڱ� ������ ��� �� �Ҹ���  ȣ��
	// �ν��Ͻ��� �޸𸮿��� ������  �� ���ο��� ȣ��
	// �����Ҵ����� ���������쿡�� ������ ����� �ڵ����� �޸� �������� �ʱ� ������ delete���� �޸𸮸� ������ ���� �Ҹ���ȣ��
	// �Ҹ��� ���� ȣ���� ��������ʴ´�.	
};

class IntArray {
private:
	int* m_arr = nullptr;
	int m_length = 0;
public:
	IntArray(const int length_in) {
		m_length	= length_in;
		m_arr		= new int[m_length];//���ڵ常 �ۼ��ϸ� memory leak �߻�
		cout << "Constructor " << endl;
	}
	~IntArray() {
		if(m_arr != nullptr) delete [] m_arr;
	}
	int size() { return m_length; }

};
int main() {
	/*
	Simple s1(0);
	Simple s2(1);
	// 0 ���� -> 1 ���� -> 1 �Ҹ� -> 0 �Ҹ�
	*/
	/*
	Simple* s1 = new Simple(0);
	Simple s2(1);
	delete s1;
	//0 ����-> 1 �ļ� -> 0 �Ҹ� -> 1 �Ҹ�
	*/
	while (true) {
		IntArray  my_int_arr(10000);
		
	}
}