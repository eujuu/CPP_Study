#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//위임 생성자
//Delegating Constructors
class Student {
private:
	int m_id;
	string m_name;
public:
	/*이름만 입력받고 싶을 때, 하지만 아주 비추천!! 좋지 않은 방법이다.
	- const값을 넣는건 좋지 않음
	- 같은 동작을 하는 건 한 군데에만 있는게 좋다(디버깅, 수정 등에 있어서)	*/
	//Student (const string &name_in):m_id(0), m_name(name_in){}

	//중복되게 초기화 하기 보다는, 생성자를 가져와서 만든다!!
	//위임생성자(c++11이후)
	Student(const string& name_in): Student(0, name_in) {}
	//{ init(0, name_in);}
	Student(const int& id_in, const string& name_in) : m_id(id_in), m_name(name_in) {}
	//{		init(id_in, name_in);	}
	void init(const int& id_in, const string& name_in) { //초기화 코드를 분리하는 경우
		m_id = id_in;
		m_name = name_in;
	}

	void print() {
		cout << m_id << " " << m_name << endl;
	}
};
int main() {
	Student st1(0, "jack");
	st1.print();

	Student st2("Dash");
	st2.print();
}