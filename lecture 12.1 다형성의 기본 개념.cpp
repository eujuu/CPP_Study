#include <iostream>
#include <string>
using namespace std;
// 상속과 포인터 연관시켜,, -> 자식클래스의 객체에 부모 클래스의 포인터를 사용한다면?
//다형성의 기본 개념
//virtual

class Animal {
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	//void speak() const //포인터 사용시 모두 이쪽으로 오게 됨
	virtual void speak() const //다형성
	{
		cout << m_name << " ??? " << endl;
	}
};

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
		:Animal(name)
	{}

	void speak() const {
		cout << m_name << " Woof " << endl;
	}
};
int main() {
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	ptr_animal1->speak();
	ptr_animal2->speak(); //자기가 부모케이스인줄 알고 작동

	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for (int i = 0; i < 5; i++)
		cats[i].speak();

	for (int i = 0; i < 2; i++)
		dogs[i].speak();
	//번거롭다!!!

	Animal* my_animals[] = {&cats[0],&cats[1],&cats[2],&cats[3],&cats[4], &dogs[0], &dogs[1] }; //같은 부모로 상속받았기에 casting 가능

	for (int i = 0; i < 7; i++)
		my_animals[i]->speak();


}