#include <iostream>
#include <string>
using namespace std;
//����� ���α׷����� ���� Defensive Programming
//����ڰ� ��� ����ϵ� ���������� ��ǵ���

int main() {
	// Syntax Error ��������
	// int x //�����ݷ���  ����

	// Semantic Errors ����, �ǹ� ����
	int  x;
	cin >> x;
	if (x >= 5) //5�̻��� ���
		cout << "x is greater than 5" << endl;//5�ʰ��� ���
	//������ ����, �����ڰ� �ƴϸ� �˱� ����

	// Violated Assumption ��������
	// ����ڰ� ���� �ۼ��� ��İ� ���� �ٸ��� ���α׷� ���
	string hello = "hello, my name is Jack jack";
	int ix;
	cin >> ix;
	cout << hello[ix] << endl;
	//string ���� �ʰ��Ͽ� ix ���Է��� ��쿣 runtime error

	cout << "Input from 0 to " << hello.size() - 1 << endl; //�̸� ���� ���,,�׷��� ��..
	//������ �̸� �˻�(����� ���α׷���), ������ġ�� �����صξ�� ��
	//�����Ϸ��� ������ ������ �� �ֵ���
	while (true) {
		int ix;
		cin >> ix;
		if (ix >= 0 && ix <= hello.size() - 1) {
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}

}