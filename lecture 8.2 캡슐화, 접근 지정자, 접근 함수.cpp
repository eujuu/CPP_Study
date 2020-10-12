#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//Encapsulation

class Date2 {
	int m_month;
	int m_day;
	int m_year; //private
public:
	void setDate(const int& month_input, const int& day_input, const int& year_input) {
		//���� Ŭ������ ����� private�� ���� ����, �ܺο� �ǻ����
		//access Function
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}
	void setMonth(const int& month_input) { //setters
		m_month = month_input;
	}
	void setDay(const int& day_input) {
		m_day = day_input;
	}
	void setYear(const int& year_input) {
		m_year = year_input;
	}
	const int& getDay() { //getters
		return m_day;
	}
	int getMonth() {
		return m_month; 
	}
	void copyFrom(const Date2& origin) {
		m_month = origin.m_month;
		m_day = origin.m_day;
		m_year = origin.m_year;
		//private�ε� ��� origin�� ��������� ���� ����??
		//�ٸ� �޸𸮿� �־, ���� Ŭ�������� �������� �����ٰ� �� �� ����
		//���� Ŭ����, �ٸ� �ν��Ͻ��� ��� ���� ����

	}
};
class Date{
//struct Date{
public: //access specifier
	int m_month;
	int m_day;
	int m_year;
};

int main() {

	Date today{ 10, 12, 2020 }; //uniform initialization
	today.m_month = 10;
	today.m_day = 12;
	today.m_year = 2020; //public�ƴϸ� �̷��� ���� �Ұ�, ������ ����� �����ؾ��Ұ� �ʹ� ��������..!

	Date2 today2;
	today2.setDate(10, 12, 2020);
	today2.setMonth(11);
	cout << today2.getDay();

	Date2 copy;
	//copy.setDate(today2.getMonth(), today2.getDay(), today2.setYear());
	copy.copyFrom(today2);

}