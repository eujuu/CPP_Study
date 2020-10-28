#include <iostream>
#include <cassert>
using namespace std;
// ��ȣ ������((), parenthesis) �����ε��� �Լ� ��ü(Function object, Functor)
// ��ȣ �����ڴ� Ư¡ �� �Լ� ȣ�� ��ȣ�� ����

class Accumulator {
private:
	int m_counter = 0;
public:
	int operator()(int i) { return (m_counter += i); } //�Լ��ε� ���� ����(Functor)
	// ÷�� �����ε� ����� ����
	// �Լ� ��üó�� ���
};
int main() {
	Accumulator acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl; //chaining�� ���� ����

}