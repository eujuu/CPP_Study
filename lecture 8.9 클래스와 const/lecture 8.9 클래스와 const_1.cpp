#include<iostream>
using namespace std;
//const�� �� ���ִ� ���� ���� ���°� ����
class Something {
public:
	int  m_val = 0;
	Something(const Something& st_in) { 
		m_val = st_in.m_val; 
		cout << "Copy Constructor" << endl;
	}//copy Constructor

	Something() { cout << "Constructor" << endl; }

	void setValue(int val) { m_val = val; }
	int  getValue() const { //�� member function�� const�̴�. member variable�� �ٲ��� ������ ����ϴ� ��.
		return m_val;
	}
};

void print(Something st) {
	//parameter��  ���� st�� ���簡 ��, ���縦 ���ϱ� ���� const ���۷��� ���
	//constructor �� �� ���� �� ��??
	//copy constructor�� �����ִ�!!
	cout << &st << endl;
	cout << st.getValue() << endl;
}
int main() {
	const int i = 0; //const�� ������ ����� ����� ���� �� ���

	const Something some; //�ν��Ͻ�, ����, objectȥ���ؼ� ���
	//object some�� const�� ����ٴ� ���� member variable�� const�� ����Ͱ� ������ ȿ��
	//const�� ����� const member function�� ��밡��
	//some.setValue(3); //const ������ �ش� �Լ� ��� �Ұ�

	//cout << some.getValue() << endl;
	//m_val�� �ٲ����������� ����, �����Ϸ��� �Ǵ��ϴ°� member function�� const�� �ƴϳĸ� ��
	Something  st;
	cout << &st << endl;
	print(st);
}