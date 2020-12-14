#include "MyArray.h"
template<typename T>
void MyArray<T>::print() {
	for (int i = 0; i < m_length; i++)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

//explicit instantiation
template void MyArray<char>::print(); // -> char type�� ���� instantiation �� ���̴� �׷��� �����ض�!!!
template void MyArray<double>::print(); 

//Ŭ���� ��ü��
template class MyArray<char>;
template class MyArray<double>;
