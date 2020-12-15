#pragma once
#include <assert.h>
#include <iostream>

template<typename T, unsigned int T_SIZE> 
//T_SIZE = m_length��ü
//T_SIZE�� ������ Ÿ�ӿ� ������(������ �� �� ����)

class MyArray {
private:
	//int m_length;
	T* m_data; //T m_data[T_SIZE]

public:
	MyArray(){
		m_data = new T[T_SIZE];
	}

	~MyArray() {
		delete[] m_data;
	}

	T& operator [](int idx) {
		assert(idx >= 0 && idx < T_SIZE);
		return m_data[idx];
	}
	int getLength() {
		return T_SIZE;
	}

	void print() {
		//explicit instantiation�� ����Ϸ��� �ϸ�, ��� ��츦 ����������ϱ� ������ ������ ���;;
		//Non-type���ÿ��� �׳� ����� �ִ� �� ��õ��
		for (int i = 0; i < T_SIZE; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};


