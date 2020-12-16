#pragma once
#include <iostream>

template <class T> //class T �� ���ؼ�  Templitize �Ǿ�����
class Storage {
private:
	T m_value;

public:
	Storage(T val) {
		m_value = val;
	}
	~Storage() {

	}
	void print() {
		std::cout << m_value << std::endl;
	}

};


/*
// Storage.cpp�� �̵� -> �׳� �̵��� �ϸ� main ���� Specialization���θ� ��
//double Ÿ�Կ� ���ؼ��� Ư��ȭ�� ��Ű�� ���� ���
template<>
void Storage<double>::print() {
	std::cout << "Double Type: ";
	std::cout << std::scientific << m_value << std::endl;
}
*/