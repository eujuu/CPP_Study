#include <iostream>
#include <string>
using namespace std;
//���� ��� �Լ� static

class Something {
public:
	class _init {
	public:
		_init() {
			s_val = 9876; //����Ŭ�������� ���� ����
		}
	};

private:
	static int  s_val;
	int m_val=10;
	static _init s_initializer;

public:
	//static member variable�� constructor���� �ʱ�ȭ �Ұ���
	//C++������ static ������ �Ұ�
	Something():m_val(123) //,s_val(1024)
	{}

	//�׷��� ���???-> inner class  ���(���� ����)
	//Ŭ���� ���ο��� static �ʱ�ȭ ����!(����������)

//---------------------------------------------------------------------
	static int getValue() {
		//return m_val; //static�� �Ұ�(this�� �����ؾ��ϴ� ���� ��� �Ұ�, s_val�� �������� �޸𸮿� �����ϹǷ� ��� ����

		return s_val; //static�� this������ ��� �Ұ�
	}
	int temp() {
		return this->s_val + this->m_val; //Ư�� �ν��Ͻ��� �ּҸ� �޾Ƽ�, �ش� �ν��Ͻ��� ���� ���
	}
};

int	Something::s_val = 1024;
Something::_init Something::s_initializer; //�갡 ��������鼭 ������ ȣ��, s_val �ʱ�ȭ


int main() {
	//cout << Something::s_val << endl; //static�̱⿡ ����(public�� ��)
	cout << Something::getValue() << endl;

	Something s1, s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_val << endl;

	//int (Something::*fptr1)() = s1.temp; 
	//�Ұ���, temp��� �Լ��� �� ����, s1�̶�� �ν��Ͻ��� member variable�� ������ �ش� �Լ� ���
	int (Something:: * fptr1)() = &Something::temp;

	cout << (s2.*fptr1)() << endl;

	int (* fptr2)() = &Something::getValue;
	//Something�� ����� ����, getValue�� Ư�� �ν��Ͻ��� ������� �����ų �� �ִ� function pointer
	cout << fptr2() << endl;

	//function�� �ּҰ� Ư�� �ν��Ͻ��� ���� �ִ°� �ƴұ�? --> no!!!
	

}