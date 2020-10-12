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
		//같은 클래스의 멤버는 private에 접근 가능, 외부와 의사소통
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
		//private인데 어떻게 origin의 멤버변수에 접근 가능??
		//다른 메모리에 있어도, 같은 클래스에서 나왔으면 가져다가 쓸 수 있음
		//같은 클래스, 다른 인스턴스의 멤버 접근 가능

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
	today.m_year = 2020; //public아니면 이렇게 지정 불가, 변수명 변경시 수정해야할게 너무 많아진다..!

	Date2 today2;
	today2.setDate(10, 12, 2020);
	today2.setMonth(11);
	cout << today2.getDay();

	Date2 copy;
	//copy.setDate(today2.getMonth(), today2.getDay(), today2.setYear());
	copy.copyFrom(today2);

}