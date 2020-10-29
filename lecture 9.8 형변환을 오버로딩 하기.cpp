#include <iostream>
#include <cassert>
using namespace std;
// 형변환(static_cast)을 오버로딩

class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0) {
		m_cents = cents;
	}
	int getCents() { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	operator int() { //int로 바꾸는 형변환
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
	/* //아래와 같음
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