#include "Storage.h"

//double 타입에 대해서는 특수화를 시키고 싶은 경우
template<>
void Storage<double>::print() {
	std::cout << "Double Type: ";
	std::cout << std::scientific << m_value << std::endl;
}