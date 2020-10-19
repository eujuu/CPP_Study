#include <iostream>
#include <string>
using namespace std;

class Something {
public:
	string m_val = "default";
	const  string& getValue() const { //const�� member function�� ����� ��쿣 ����Ÿ�Ե� const�� �����
		cout << "const version" << endl;
		return m_val;
	}
	string& getValue() {
		cout << "non-const version" << endl;
		return  m_val;
	}

};
int main() {
	Something st;
	st.getValue() = 10; //�� ���� ����

	const  Something st2;
	st2.getValue(); //const������ ���� �ٸ� �Լ���!, �����ε�

	//�����ε��Ҷ�, �Ű������� �ٸ� ��쿡 ����Ѵٰ� ����
	//�ٵ� const�� ���󼭵� �޶���, ���� �������� ����

}