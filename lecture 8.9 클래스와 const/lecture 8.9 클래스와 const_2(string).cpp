#include <iostream>
#include <string>
using namespace std;

class Something {
public:
	string m_val = "default";
	const  string& getValue() const { //const로 member function을 만드는 경우엔 리턴타입도 const로 만든다
		cout << "const version" << endl;
		return m_val;
	}
	string& getValue() {
		cout << "non-const version" << endl;
		return  m_val;
	}

};
int main() {
	Something st;
	st.getValue() = 10; //값 변경 가능

	const  Something st2;
	st2.getValue(); //const유무에 따라 다른 함수로!, 오버로딩

	//오버로딩할때, 매개변수가 다른 경우에 사용한다고 했음
	//근데 const에 따라서도 달라짐, 많이 사용되지는 않음

}