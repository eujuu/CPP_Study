#pragma once
#include <iostream>
// ��������� using namespace std;�� ���� �ʴ°� ����
// ���� ���� �ִ� ��� ��ҵ��� ���� �ޱ� ����

//Ŭ�������� ���� ����
//template�����ÿ��� �׳� ���ǵ� ����� ���°� ���� �� ����
class Calc {
private:
	int m_val;

public:
	Calc(int init_val);
	Calc& add(int val);
	Calc& sub(int val);
	Calc& mult(int val);
	void print();
};
