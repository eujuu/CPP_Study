#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//소멸자 Destructor
class Simple {
private:
	int m_id;
public:
	Simple(const int& id_in) : m_id(id_in) {
		cout << "Constructor " << m_id << endl;
	}
	~Simple(){
		cout << "Destructor " << m_id << endl;
	} //소멸자,  소멸자는 파라미터 없음
	//자기 영역을 벗어날 때 소멸자  호출
	// 인스턴스가 메모리에서 해제될  때 내부에서 호출
	// 동적할당으로 만들어진경우에는 영역을 벗어나도 자동으로 메모리 해제되지 않기 때문에 delete으로 메모리를 해제할 때만 소멸자호출
	// 소멸자 직접 호출은 권장되지않는다.	
};

class IntArray {
private:
	int* m_arr = nullptr;
	int m_length = 0;
public:
	IntArray(const int length_in) {
		m_length	= length_in;
		m_arr		= new int[m_length];//이코드만 작성하면 memory leak 발생
		cout << "Constructor " << endl;
	}
	~IntArray() {
		if(m_arr != nullptr) delete [] m_arr;
	}
	int size() { return m_length; }

};
int main() {
	/*
	Simple s1(0);
	Simple s2(1);
	// 0 생성 -> 1 생성 -> 1 소멸 -> 0 소멸
	*/
	/*
	Simple* s1 = new Simple(0);
	Simple s2(1);
	delete s1;
	//0 생성-> 1 셍성 -> 0 소멸 -> 1 소멸
	*/
	while (true) {
		IntArray  my_int_arr(10000);
		
	}
}