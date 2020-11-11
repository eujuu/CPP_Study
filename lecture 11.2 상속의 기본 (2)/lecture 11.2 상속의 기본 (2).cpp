#include "Student.h"
#include  "Teacher.h"
using namespace std;
//상속의 기본 Inheritance (is-a relationship) - 2

int main() {
	std::string name;//사용가능

	Student std("Jack");
	std.setName("Jack Jack");
	//std.getName();
	cout << std.getName() << endl;

	Teacher teacher1("Dr.H");
	teacher1.setName("Dr.K");
	cout << teacher1.getName() << endl;

	cout << std << endl;
	cout << teacher1 << endl;

	std.doNothing();
	teacher1.doNothing();

	std.study();
	teacher1.teach();

	Person  person;
	person.setName("Mr.Incredible");
	cout << person.getName()  <<endl;
	//person.study(); //불가
}