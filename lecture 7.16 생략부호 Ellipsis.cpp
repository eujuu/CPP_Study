#include <iostream>
#include <cstdarg> //for ellipsis
using namespace std;
//���� ��ȣ Ellipsis 

double findAverage(int count, ...) { //count = parameter argument ����
	double sum = 0;

	va_list list; //char * -> ���ڿ��� ����
	va_start(list, count); //argument ����

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int); //(list, type), Ÿ���� �̸� �����Ǿ� �־�� ��. �� �о� ���̱�
	va_end(list);

	return sum / count;
}

int main() {
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl; //1����
	cout << findAverage(3, 1, 2, 3) << endl; //3����
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl; //5����
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl; //10��, �ѱ� ���ڴ� 5���ۿ� �����Ƿ� ������ ��

}