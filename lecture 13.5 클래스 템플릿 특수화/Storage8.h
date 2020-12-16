#pragma once
#include <iostream>

//해당 타입 8개를 저장하는 클래스
template<class T>
class Storage8 {
private:
	T m_arr[8];

public:
	void set(int idx, const T& val) {
		m_arr[idx] = val;
	}
	const T& get(int idx) {
		return m_arr[idx];
	}

};
/*
template<>
class Storage8<bool> { //1bit로 표현 가능
private:
	unsigned char m_data; //1byte로 bool 여덟개 표현 가능

public:
	Storage8() :m_data(0) {

	}

	void set(int idx, bool val) {
		unsigned char mask = 1 << idx;

		if (val)
			m_data |= mask;
		else
			m_data &= ~mask;
	}

	bool get(int idx) {
		unsigned char mask = 1 << idx;

		return (m_data & mask) != 0;
	}
};
*/