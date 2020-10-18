#include "Calc.h"
using namespace std;
Calc::Calc(int init_val) : m_val(init_val) {}

Calc& Calc::add(int val) {
	m_val += val;
	return *this;
}

Calc& Calc::sub(int val) { 
	m_val -= val;
	return *this;
}

Calc& Calc::mult(int val) {
	m_val *= val;
	return *this;
}

void Calc::print() {
	cout << m_val << endl;
}
