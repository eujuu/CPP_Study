#include <iostream>
#include <cassert> //assert.h
#include <array>
using namespace std;
// ��ȯ ������ Converting Constructor, explicit,delete
// ���α׷����� ���Ǹ� ���� ��ȯ ������
// explicit: ��ȯ�����ڸ� ��� ���ϵ��� ��
// delete  : Ư���� �����ڸ� ������� ���ϵ��� ��������(�����Ҵ��̶� �ٸ� delete)
class Fraction {
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(char) = delete;//char�� ������� ���ϰ� delete

	explicit Fraction(int  num = 0, int den = 1) //�� �����ϰ� �϶�� �ϴ� ��, convertin constructor�ν��� ��� �Ұ�
		: m_numerator(num), m_denominator(den) {
		assert(den != 0);
	}

	Fraction(const Fraction& fraction)  
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy Constructor called" << endl;
	}
	friend ostream& operator << (ostream& out, const Fraction& f) {
		cout << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};
void doSomething(Fraction frac) {
	cout << frac << endl;
}
int main() {
	Fraction frac(7);

	//��� ����
	doSomething(frac);
	doSomething(Fraction(7));
	//doSomething(7); //explicit�������� ��� ��� �Ұ���,

	Fraction frac2('c'); //delete���� ��� �Ұ�, delete�� �ƴҰ�� c�� �ƽ�Ű���� 99�� ��
}