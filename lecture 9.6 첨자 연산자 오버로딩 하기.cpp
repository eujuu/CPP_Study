#include <iostream>
#include <cassert>
using namespace std;
//첨자 연산자 오버로딩 ([], subscript operator)


class IntList {
private:
	int m_list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

public:
	void setItem(int idx, int val) {
		m_list[idx] = val;
	}

	int getItem(int idx) {
		return m_list[idx];
	}

	int* getList() {
		return m_list; //array자체가 pointer
	}

	int& operator [](const int idx) { //레퍼런스 리턴: 값을 읽고 바꿀 수도 있기 때문
		assert(idx >= 0);
		assert(idx < 10); //범위 벗어나는 것 방지
		//왜 if문 안쓰고?? []는 엄청 많이 쓰임 -> if를 쓴다면 훨씬 느려질 것...권장X

		return m_list[idx];
	}
	const int& operator [](const int idx) const { //이게 있어야 const객체에 대해서도 읽기 가능(안바꾸더라도)
		assert(idx >= 0);
		assert(idx < 10); //범위 벗어나는 것 방지

		return m_list[idx];
	}
};
int main() {
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl; //method 1
	my_list.getList()[3] = 10; //값 변환
	cout << my_list.getList()[3] << endl;

	//오버로딩
	my_list[3] = 100; //항상 주소를 가지고 있는 lvalue여야 함 -> 레퍼런스 사용
	cout << my_list[3] << endl;
	cout << my_list[-1] << endl;

	const IntList my_constlist;
	cout << my_constlist[3] << endl;

	IntList* list = new IntList;
	 (*list)[3] =10; // OK
	//list[3] = 10; // Not Ok, list가 포인터

}