#include <iostream>

using namespace std;
// ���� ������ �����ε� (++, --)
// ������(prefix), ������(postfix)�Ŀ� ���� ������ ���� �ٸ�

class Digit {
private:
	int m_digit;
public:
	Digit(int digit = 0): m_digit(digit){}

	friend ostream& operator << (ostream& out, const Digit& d) {
		out << d.m_digit;
		return out;
	}

	//prefix
	Digit& operator ++ () {
		++m_digit;
		return *this; // �ڱ� �ڽ��� ����
	}
	Digit& operator -- () {
		--m_digit;
		return *this;
	}

	//postfix
	Digit operator ++ (int) { //���� ��ġ�Ƿ�, dummy�� int�� �־���
		Digit temp(m_digit); //���簪 ����
		++(*this);//�������� 1����
		return temp; //���ϱ� ���� �� ����
	}

};
int main() {
	// ���� ������
	int a = 10;
	cout << ++a << endl; //��� ���� ������
	cout << a << endl;
	cout << a++ << endl; //��� ���� ������
	cout << a << endl;

	Digit d(5);

	cout << ++d << endl;
	cout << d << endl;

	cout << d++ << endl;
	cout << d << endl;

}