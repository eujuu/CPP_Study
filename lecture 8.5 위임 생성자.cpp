#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//���� ������
//Delegating Constructors
class Student {
private:
	int m_id;
	string m_name;
public:
	/*�̸��� �Է¹ް� ���� ��, ������ ���� ����õ!! ���� ���� ����̴�.
	- const���� �ִ°� ���� ����
	- ���� ������ �ϴ� �� �� �������� �ִ°� ����(�����, ���� � �־)	*/
	//Student (const string &name_in):m_id(0), m_name(name_in){}

	//�ߺ��ǰ� �ʱ�ȭ �ϱ� ���ٴ�, �����ڸ� �����ͼ� �����!!
	//���ӻ�����(c++11����)
	Student(const string& name_in): Student(0, name_in) {}
	//{ init(0, name_in);}
	Student(const int& id_in, const string& name_in) : m_id(id_in), m_name(name_in) {}
	//{		init(id_in, name_in);	}
	void init(const int& id_in, const string& name_in) { //�ʱ�ȭ �ڵ带 �и��ϴ� ���
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