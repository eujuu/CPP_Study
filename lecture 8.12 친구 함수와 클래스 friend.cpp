#include <iostream>
#include <string>
using namespace std;
//ģ�� �Լ��� Ŭ����
//Ŭ�������� ��ȣ�ۿ�
//Encapsulaton ������ ���� friend�� �̿�

class B; //���� ����
class A {
private:
	int m_val = 1;

	friend void doSomething(A & a, B& b);
	//Ŭ������ friend function -> Ư��Ŭ������ private��� ���� ����
	//Ŭ���� A�����ÿ��� Ŭ���� B�� ���翡 ���� ���� ����(Syntax Error)-> ���漱��(forward declaration)���ֱ�

	friend class B; //�ٸ� Ŭ������ function����(class��°�� ������)
	//friend void B::doSomething2(A& a); //member function���� ���� ���

};

class B {
private:
	int m_val = 2;
	friend  void doSomething(A& a, B& b);
public:
	//�ٸ� Ŭ������ �� function ����
	void doSomething2(A& a) {
		cout << a.m_val << endl;
	}
};

void doSomething(A& a, B& b) {
	cout << a.m_val << " " << b.m_val << endl;
	// �� Ŭ���� �ۿ��� �����ؾ� �ϴ� ��찡 �ִٸ� �� �Լ��� Ŭ������ friend �� ����
}
int main() {
	A a; B b;
	doSomething(a, b);
	b.doSomething2(a);
}