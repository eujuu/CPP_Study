#include "Calc.h"
using namespace std;
//Ŭ���� �ڵ�� ��� ����
//Ŭ������ ó������ ������Ͽ� ���� ��������Ǹ� �и��Ѵ�!


int main() {
	Calc cal(10);
	cal.add(10).sub(1).mult(2).print();
	Calc(10).add(10).sub(1).mult(2).print();
}