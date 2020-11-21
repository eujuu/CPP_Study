#include <iostream>
#include <string>
using namespace std;
// 가상 소멸자
// 상속구조에서, 생성자는 자식클래스 자신의 생성자 사용.
//				 소멸자는 가상 소멸자를 사용하는게 좋음


class Base {
public:
	virtual ~Base() {
		cout << "~Base() " << endl;
	}
};
class Derived : public Base {
private:
	int* m_array;

public:
	Derived(int length) {
		m_array = new int[length];
	}

	virtual ~Derived() override{ //이름이 다르기 때문에 override지정자는 불가능 -> virtual을 써주면 문제x!!
		//자식 클래스에서도 virtual을 적어주는건 그냥 표현을 위해
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main() {

	//Derived derived(5);
	//소멸자는 생성자 호출 순서의 반대 -> ~derived - ~base


	//다형성 사용
	Derived* derived = new Derived(5); // 동적할당
	
	Base* base = derived; //derived 포인터

	//derived는 여러가지가 있을 수 있음 -> 다형성의 장점을 활용하기 위해선 base를 삭제하는게 좋음
	delete base; // Base의 소멸자만 호출 ->derived가 소멸이 안되니 memory leak으로 이어짐

	//*** Base의 소멸자를 virtual로 만들면 된다!
	// 자식클래스 소멸자 호출 후 부모 클래스 소멸자 호출!! -> memory leak도 방지!
	

}