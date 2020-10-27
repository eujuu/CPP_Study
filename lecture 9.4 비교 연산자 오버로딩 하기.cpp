#include <iostream>
#include <cstdarg> //for ellipsis
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
//비교 연산자 오버로딩 (==, !=, >=, <=)
// if 문 안에 user define type을 사용하려면 반드시 구현되어 있어야 함
// std 이용해서 sorting할때 크기 비교 연산자가 반드시 구현되어 있어야 함

class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend ostream& operator <<(ostream& out, const Cents& cents){
		out << cents.m_cents;
		return out;
	}

	friend bool operator == (const Cents& c1, const Cents& c2) { //비교 연산자
		return  c1.m_cents == c2.m_cents;
	}
	friend bool operator != (const Cents& c1, const Cents& c2) { //비교 연산자
		return  c1.m_cents != c2.m_cents;
	}
	friend bool operator > (const Cents& c1, const Cents& c2) {
		return c1.m_cents > c2.m_cents;
	}
	friend bool operator <  (const Cents& c1, const Cents& c2) {
		return c1.m_cents < c2.m_cents;
	}
	
};
int main() {
	//비교 연산자
	int a = 3, b = 3;
	//if (a == b) cout << "Equal\n";

	//User Defined Type
	Cents cents1(6);
	Cents cents2(6);
	cout << std::boolalpha;

	if (cents1 == cents2) cout << "Equal\n";

	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; i++) {
		arr[i].getCents() = i;
	}

	//random
	random_device rd;
	mt19937 g(rd());
	shuffle(arr.begin(), arr.end(), g);

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;


	sort(arr.begin(), arr.end()); // 크기 비교 연산자(기본으로 < 가 있어야 함) 없을때는 불가능!!
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;
}