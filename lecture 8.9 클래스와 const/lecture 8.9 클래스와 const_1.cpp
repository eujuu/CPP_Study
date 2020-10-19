#include<iostream>
using namespace std;
//const를 쓸 수있는 곳은 많이 쓰는게 좋음
class Something {
public:
	int  m_val = 0;
	Something(const Something& st_in) { 
		m_val = st_in.m_val; 
		cout << "Copy Constructor" << endl;
	}//copy Constructor

	Something() { cout << "Constructor" << endl; }

	void setValue(int val) { m_val = val; }
	int  getValue() const { //이 member function이 const이다. member variable을 바꾸지 않음을 명시하는 것.
		return m_val;
	}
};

void print(Something st) {
	//parameter로  들어온 st는 복사가 됨, 복사를 안하기 위해 const 레퍼런스 사용
	//constructor 는 한 번만 됨 왜??
	//copy constructor가 숨어있다!!
	cout << &st << endl;
	cout << st.getValue() << endl;
}
int main() {
	const int i = 0; //const는 변수를 상수로 만들고 싶을 때 사용

	const Something some; //인스턴스, 변수, object혼용해서 사용
	//object some을 const로 만든다는 것은 member variable을 const로 만든것과 동일한 효과
	//const로 만들면 const member function만 사용가능
	//some.setValue(3); //const 설정시 해당 함수 사용 불가

	//cout << some.getValue() << endl;
	//m_val을 바꾸지않음에도 오류, 컴파일러가 판단하는건 member function이 const냐 아니냐를 봄
	Something  st;
	cout << &st << endl;
	print(st);
}