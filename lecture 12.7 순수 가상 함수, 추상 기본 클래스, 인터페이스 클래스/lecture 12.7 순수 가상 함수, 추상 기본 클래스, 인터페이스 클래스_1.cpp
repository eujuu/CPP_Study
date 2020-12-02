#include <iostream>
#include <string>
using namespace std;
// 순수 가상 함수, 추상  기본 클래스, 인터페이스 클래스

class Animal {
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const = 0; //pure virtual function, body를 없앰
	//클래스 설계시 상속구조를 한꺼번에 설계하도록 도와주는 문법

};

void Animal::speak() const { //pure도 별도로 body 를 정의할 수 있긴 함, 하지만 쓸모는 업승ㅁ(호출불가)
	cout << m_name << " ??? " << endl;
}

class Cat : public Animal {
public: 
	Cat(string name) 
		: Animal(name)
	{}
	
	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};
class Dog : public Animal {
public: 
	Dog(string name)
		: Animal(name)
	{}

	void speak() const {
		cout << m_name << " Woof " << endl;
	}
};

class Cow : public Animal {
public:
	Cow(string name)
		: Animal(name)
	{}
	void speak() const {
		cout << m_name << " Moooo " << endl;
	}
};

int main() {
	//Animal ani("HI"); //생성불가 -> pure virtual function이 하나라도 들어간 클래스 = abstract class -> object를 만들 수 업음
	
	Cow cow("hello"); //speak없으면 생성불가 -> 자식클래스에서 speak를 override해주지 않으면 생성불가
	cow.speak();
}