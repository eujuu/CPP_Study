#include <iostream>
#include <cassert> //assert.h
#include <string>
using namespace std;
// 명령줄 인수 command line arguments
// main괄호안의 매개변수

// 0: 실행파일 이름
// 이후: 본인이 입력한 데이터
// cmd에서 실행 or 속성 -> 디버깅 -> 명령인수에서 사용할 데이터 입력
// cd 경로
int main(int argc, char* argv[]) {
	// int argc: 개수
	// char* argv[]: 실제 내용
	
	for (int cnt = 0; cnt < argc; ++cnt) {
		string argv_single = argv[cnt]; //숫자일때 string변환후 출력

		if (cnt == 1) {
			int input_number = stoi(argv_single);
			cout << input_number + 1 <<endl;
		}
		cout << argv[cnt] << endl;
	}
	//boost library - 준표준 라이브러리 - 커맨드에서쓸 때 더 편리하게 작성 가능
	return 0;
}