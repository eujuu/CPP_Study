#include <iostream>
using namespace std;
// ��ӹ��� �Լ��� ���߱�(����������ϵ��� ����)

class Base {
protected:
	int m_i;
	//protected: derived�� ��ӹ޾� Ŭ���� ���ο��� ��밡��, �ܺο����� ���� �Ұ�

public:
	Base(int val)
		: m_i(val)
	{

	}
	void print() {
		cout <<"I'm Base " << endl;
	}
	
};
class Derived :public Base{
protected:
	double m_d;
	using Base::print; //private���� �ٲٱ�,�̸��� ������ �� -> ��ȣ ġ�� �ȵ�!!
public:
	Derived(int val)
		: Base(val)
	{

	}
	using Base::m_i; //m_i�� derived�ȿ����� public�� �Ǿ����..

private:
	
	void print() = delete; //�ڽĿ����� ���� �Ұ�, �θ�� ������ ���� �� ��� ����
};
int main() {
	Base base(5);
	base.print(); //base������ �������� ��� ����


	Derived derived(7);
	derived.m_i = 1024; //access specifier�� ������ Ŭ�������� �ٲٱ� ����
						//Base������ protected������, Derived���� �̸� �ٲ������ν� publicó�� ���
	//derived.print(); //Base������ public������, Derived���� �̸� private���� ���
}