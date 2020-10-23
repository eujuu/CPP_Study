#include <iostream>
#include <cstdarg> //for ellipsis
using namespace std;
//생략 부호 Ellipsis 

double findAverage(int count, ...) { //count = parameter argument 개수
	double sum = 0;

	va_list list; //char * -> 문자열로 받음
	va_start(list, count); //argument 개수

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int); //(list, type), 타입은 미리 결정되어 있어야 함. 값 읽어 들이기
	va_end(list);

	return sum / count;
}

int main() {
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl; //1개만
	cout << findAverage(3, 1, 2, 3) << endl; //3개만
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl; //5개만
	cout << findAverage(10, 1, 2, 3, 4, 5) << endl; //10개, 넘긴 인자는 5개밖에 없으므로 오류가 남

}