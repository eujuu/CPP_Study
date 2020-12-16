#pragma once
#include <iostream>

//�ش� Ÿ�� 8���� �����ϴ� Ŭ����
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
class Storage8<bool> { //1bit�� ǥ�� ����
private:
	unsigned char m_data; //1byte�� bool ������ ǥ�� ����

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