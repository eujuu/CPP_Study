#pragma once
#include <iostream>

template <class T> //class T 에 대해서  Templitize 되어있음
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
// Storage.cpp로 이동 -> 그냥 이동만 하면 main 에서 Specialization여부를 모름
//double 타입에 대해서는 특수화를 시키고 싶은 경우
template<>
void Storage<double>::print() {
	std::cout << "Double Type: ";
	std::cout << std::scientific << m_value << std::endl;
}
*/