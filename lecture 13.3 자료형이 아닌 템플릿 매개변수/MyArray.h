#pragma once
#include <assert.h>
#include <iostream>

template<typename T, unsigned int T_SIZE> 
//T_SIZE = m_length대체
//T_SIZE가 컴파일 타임에 결정됨(변수는 들어갈 수 없음)

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
		//explicit instantiation을 사용하려고 하면, 모든 경우를 설정해줘야하기 때문에 구현이 어렵;;
		//Non-type사용시에는 그냥 헤더에 넣는 것 추천스
		for (int i = 0; i < T_SIZE; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};


