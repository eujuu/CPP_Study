#include <iostream>
#include <cassert>
using namespace std;
// ����ȯ(static_cast)�� �����ε�

class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0) {
		m_cents = cents;
	}
	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	operator int() { //int�� �ٲٴ� ����ȯ
		cout << "cast here: " << endl;
		return m_cents;
	}
};

class Dollar {
private:
	int m_dollars = 0;
public:
	Dollar (const int& input) : m_dollars(input){}
	operator Cents() {
		return Cents(m_dollars * 100);
	}
};

void printInt(const int& value) {
	cout << value << endl;
}
int main() {
	Cents cents(7);
	/* //�Ʒ��� ����
	int val = (int)cents;
	val = int(cents);
	val = static_cast<int>(cents);
	*/

	printInt(cents);
	cout << Cents(7) << endl;

	Dollar dol(2);
	Cents cents2 = dol;
	printInt(cents2);

}