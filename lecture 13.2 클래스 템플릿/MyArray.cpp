#include "MyArray.h"
template<typename T>
void MyArray<T>::print() {
	for (int i = 0; i < m_length; i++)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

//explicit instantiation
template void MyArray<char>::print(); // -> char type에 대해 instantiation 할 것이니 그렇게 빌드해라!!!
template void MyArray<double>::print(); 

//클래스 자체를
template class MyArray<char>;
template class MyArray<double>;
