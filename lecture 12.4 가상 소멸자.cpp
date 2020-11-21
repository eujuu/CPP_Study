#include <iostream>
#include <string>
using namespace std;
// ���� �Ҹ���
// ��ӱ�������, �����ڴ� �ڽ�Ŭ���� �ڽ��� ������ ���.
//				 �Ҹ��ڴ� ���� �Ҹ��ڸ� ����ϴ°� ����


class Base {
public:
	virtual ~Base() {
		cout << "~Base() " << endl;
	}
};
class Derived : public Base {
private:
	int* m_array;

public:
	Derived(int length) {
		m_array = new int[length];
	}

	virtual ~Derived() override{ //�̸��� �ٸ��� ������ override�����ڴ� �Ұ��� -> virtual�� ���ָ� ����x!!
		//�ڽ� Ŭ���������� virtual�� �����ִ°� �׳� ǥ���� ����
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main() {

	//Derived derived(5);
	//�Ҹ��ڴ� ������ ȣ�� ������ �ݴ� -> ~derived - ~base


	//������ ���
	Derived* derived = new Derived(5); // �����Ҵ�
	
	Base* base = derived; //derived ������

	//derived�� ���������� ���� �� ���� -> �������� ������ Ȱ���ϱ� ���ؼ� base�� �����ϴ°� ����
	delete base; // Base�� �Ҹ��ڸ� ȣ�� ->derived�� �Ҹ��� �ȵǴ� memory leak���� �̾���

	//*** Base�� �Ҹ��ڸ� virtual�� ����� �ȴ�!
	// �ڽ�Ŭ���� �Ҹ��� ȣ�� �� �θ� Ŭ���� �Ҹ��� ȣ��!! -> memory leak�� ����!
	

}