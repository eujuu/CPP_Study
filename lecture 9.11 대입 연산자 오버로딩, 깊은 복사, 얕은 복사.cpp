#include <iostream>
#include <cassert> //assert.h
#include <array>
using namespace std;
// 대입 연산자 오버로딩, 깊은복사 vs 얕은 복사 Deep copy vs Shallow copy
// 동적 할당된 메모리에 대한 포인터 변수를 멤버로써 가지고 있는 경우
// -> 깊은 복사와 얕은 복사냐에 따라 

//동적할당 하기 싫으면 그냥 string 쓰세염(퍼포먼스는 좀 떨어질 수 있음)
// 필요한 부분은 상속받아서 추가 구현

class MyString {
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "") {
		cout << "Constructor" << endl;
		assert(source); //비지 않았는지

		m_length = strlen(source) + 1; //글자갯수 + 1, (문자열의 마지막을 알리기위한)널캐릭터 자리 추가1
		m_data = new char[m_length];

		for (int i = 0; i < m_length; i++)
			m_data[i] = source[i]; //값 복사

		m_data[m_length - 1] = '\0'; //널캐릭터
	}
	~MyString() {
		//cout << "Destructor" << endl;
		delete[] m_data; //메모리 지우기(leak을 막기 위해)
	}

	//Copy Constructor
	MyString(const MyString& source) {
		cout << "Copy Constructor " << endl;
		// 메모리 다시 할당, 값들 복사 -> 깊은 복사
		// 그냥 주소 전달 -> 얕은 복사

		
		m_length = source.m_length;

		if (source.m_data != nullptr) {
			m_data = new char[m_length]; // 메모리 새로 할당
			for (int i = 0; i < m_length; i++)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
			//m_data = 0;
			
	}
	//복사 생성자 쓰기엔 바쁘고 얕은 복사를 막고 싶으면,,?
	//MyString(const MyString& source) = delete; //아예 막아버리기!

	//Assignment operator
	MyString& operator = (const MyString& source) {
		//shallow copy
		/*
			this -> m_data = source.m_data;
			this-> m_length = source.m_length; //default
			//동적할당에선 이 방법이 큰 문제가 될 수 있다!!
		*/

		cout << "Assignment operator " << endl;

		// 자기가 자기한테 대입
		// MyString hello("Hello"); hello = hello; 
		// 이러한 경우에 아무것도 하지 못하게 막음
		if (this == &source) return *this; //prevent self-assignment

		delete[] m_data; //기존 데이터 삭제(내가 이미 갖고 있었을 수 있으니까,,)

		
		m_length = source.m_length;

		if (source.m_data != nullptr) {
			m_data = new char[m_length]; // 메모리 새로 할당
			for (int i = 0; i < m_length; i++)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
			
		return* this;

	}


	char* getString() { return m_data; }
	int getLength() { return m_length; }
};
int main() {
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl; //주소
	cout << hello.getString() << endl;

	{
		MyString copy = hello;// 복사 생성자 호출(생성하고 있는 중이므로), 구현을 안하면 기본 생성자가 호출됨(얕은 복사)
		//copy = hello; //대입 연산자 호출
		cout << (int*)copy.m_data << endl;//copy와 hello의 주소 데이터는 같음
		cout << copy.getString() << endl; //copy는 포인터 주소를 복사만함
		//자기가 new를 한 적이 없음. 힙에는 new로 할당된게 한개만 있는 것
		//소멸자가 호출되면서 delete를 하게 됨
		//hello의 m_data도 같은 주소를 가리키고 있음, 힙에서는 그 데이터가 소멸자로 인해 삭제된 상태
	}//copy는 소멸

	//copy constructor, assignment overloading 유의!!

	cout << hello.getString() << endl; //복사 생성자 혹은 대입연산자가 없으면 에러(주소값이 삭제되었으므로)

	MyString str1 = hello; // copy constructor
	//MyString str1(hello);
	//헷갈리기 싫으면 위처럼 쓰기; 
	MyString str2;
	str2 = hello; // assignment operator

	
}