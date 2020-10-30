#include <iostream>
#include <cassert> //assert.h
#include <array>
using namespace std;
// 단언하기 assert
// 프로그래밍은 디버깅에 대부분 시간 소모 ->  컴파일러의 도움을 받을 수 있다면?!??!
// assert -> run time에 체크해줌
// static assert -> compile time에 오류 발생시킴

void printVal(const array<int, 5>& my_arr, const int& idx) {
	assert(idx >= 0);
	assert(idx <= my_arr.size() - 1); //문제 지점을 알 수 있게 됨

	
	cout << my_arr[idx] << endl;
}

int main() {
	//Release 모드에서는 작동 안함(assert도 연산량 소모되기 때문에)
	//Debug모드에서 프로그래머가 테스트 할 때 사용, 오류를 찾아줌

	//assert(false); //오류발생 지점 알려줌,

	const int num = 5;
	assert(num == 5); //반드시 5여야만 한다. comment 같이..
	//주석만 남겨두면 5인지 아닌지 찍어봐야 함

	array<int, 5> my_arr{1, 2, 3, 4, 5};
	printVal(my_arr, 4);

	const int x = 5;
	assert(x == 5);
	// 변수는 중간에 바뀔 수 있으므로 static_assert 사용 불가 -> const를 쓰면 사용 가능
	static_assert(x == 5, "x should be 5"); //에러 메시지 추가
}