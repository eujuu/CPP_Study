#include <iostream>
using namespace std;
// ������ Ŭ������(�ڽ�Ŭ������) ���ο� ��� �߰��ϱ�

class Base {
//private:
protected:
	int m_val;
public:
	Base(int val)
		:m_val(val)
	{

	}

};

class Derived : public Base {
public:
	Derived(int val)
		:Base(val)
	{

	}
	void doSomething() {
		//base�� ���� �ǵ帮�� �ʴ� ���� �׳� �� ���� ��
	}
	void setValue(int val) {
		//�ڽ� Ŭ������ ������ �θ�Ŭ���� ������ ���� ���Ǵ� ��쿡 ���ٹ�� ����ؾ���

		Base::m_val = val;  // private��� ���ٺҰ� 
		//1. �θ� Ŭ������ getValue�� public �Լ��� ����� -> ���� �� ��� �����ս� ����
		//2. private��� protected�� �ٲ۴�.
	}
};

int main() {
	
}