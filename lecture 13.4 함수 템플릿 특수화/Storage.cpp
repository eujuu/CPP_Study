#include "Storage.h"

//double Ÿ�Կ� ���ؼ��� Ư��ȭ�� ��Ű�� ���� ���
template<>
void Storage<double>::print() {
	std::cout << "Double Type: ";
	std::cout << std::scientific << m_value << std::endl;
}