#include <iostream>
#include <string>
using namespace std;
//인라인 함수
//프로그램을 빠르게 만들기 위해 인라인을 사용하여 최적화
//보통 헤더 파일에 함수를 정의할 때 많이 사용

inline int min(int x, int y) { //인라인 사용시  함수가 아닌 것처럼 작동
	//인라인은 권장?하는 느낌, 무조건적으로 되는 게 아니라 컴파일러가 보기에 가능할 거 같은 경우에
	//모든 함수를 인라인으로 다 바꿔준다고 해서 빨라지는거 아님
	//요즘 컴파일러는 인라인이 아니어도 인라인처럼 사용하면 빨라질거같은거에 알아서 적용

	return x > y ? y : x;
}
int main() {
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;
	//과정: min함수 호출, 변수 선언, 인자 복사, 리턴, 값을 받아오고 출력  
	//이런 과정의 시간이 더 오래 걸릴 때가 있음 -> 인라인 사용

	//인라인 사용시 아래와 같이 동작(이렇게 컴파일 됨) -> 인라인은 컴파일러가 함!!
	//함수 호출 x, 변수 선언 x, 인자 복사 x
	//컴파일러가 이렇게 해줄지는 잘 모름
	cout << (5 > 6 ? 6 : 5) << endl;
	cout << (3 > 2 ? 2 : 3) << endl;
	//인라인이 엄청 많은 경우 컴파일 된 프로그램이 너무 커질 수 있음(너무 커지면 메모리안에서 데이터가 왔다갔다 하면서 더 많은 시간 소요)
	// -> 인라인의 효과를 못볼 수 있음

}