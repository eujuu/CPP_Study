#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//�Ű�����(Parameter)�� ������(Argument)�� ����
int foo(int x, int y); //������ ���� x,y�� foo��� �Լ��� �Ķ�����̴�.

int foo(int x, int y) { 
	//x, y����, �ʱ�ȭ, argument���� �����ؼ� ����
	//parameter: �Լ��� � ����� �ϴ����� �������ִ�(�ٲ��ִ�) ����
	return x + y; //body, x�� y�� ���� ���� ���ϰ� ��ȭ

} //�Լ��� ������ ���ÿ� �Ķ���ʹ� �����(��������)
int main() {
	int x = 1, y = 2;

	foo(6, 7); //6, 7 : arguments (actual parameters, �ǸŰ�����, ������)
	foo(x, y + 1);
	//x�� ���� ���� �޾�(1 = argument) �Լ��� �Ķ���ͷ� ����
	//argument�� parameter�� ����
}