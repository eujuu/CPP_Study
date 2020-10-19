#include <iostream>
#include <string>
using namespace std;
//���� ��� ���� static
int generateID() {
	static int s_id = 0;
	return ++s_id;
}
class Something {
public:
	static int s_val; //����
	//static ��� ������ �ʱ�ȭ �Ұ��� //static int m_val =1;  �Ұ���
	static const int s_val2 = 1;//����
	//static const�� ��� ������ �ʱ�ȭ ����� ��(���� ������ �Ұ���)
	static  constexpr int s_val3 = 1; //����
	//constexpr�� �����Ͻÿ� Ȯ���� ���� �Ǿ�� ��
};

int Something::s_val = 1; //�̷��� ����� ��(�ߺ����� ����)
//static member�� ��� cpp���� �ȿ� �����ؾ���(����� ���ǽ� ������ ����)
// -> ���Ǵ� �� ���� �־�� �Ѵٴ� ��Ģ�� ����ǹǷ� �ߺ����� ����

//int Something::s_val2 = 3; //const�� ��� ���� �Ұ���

int main() {
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << generateID() << endl;
	cout << Something::s_val << " " << &Something::s_val << endl;  //static�̱⿡ �޸𸮿� �������� ����, �ν��Ͻ��� ��� �ּҸ� ����
	Something st1;
	Something st2;
	st1.s_val = 2;

	cout << st1.s_val << "  " << &st1.s_val << endl;
	cout << st2.s_val << "  " << &st2.s_val << endl;
	//static -> ������ �ּ� ��ġ
	Something::s_val = 1024;
	cout << Something::s_val << " " << &Something::s_val << endl;
}