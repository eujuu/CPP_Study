#pragma once
#include <iostream>
// 헤더에서는 using namespace std;를 쓰지 않는게 좋음
// 파일 내에 있는 모든 요소들이 영향 받기 때문

//클래스에는 선언만 남게
//template구현시에는 그냥 정의도 헤더에 쓰는게 편할 수 있음
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
