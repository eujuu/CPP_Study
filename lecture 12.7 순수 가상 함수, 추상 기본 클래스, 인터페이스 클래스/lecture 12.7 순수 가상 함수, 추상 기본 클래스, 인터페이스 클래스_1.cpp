#include <iostream>
#include <string>
using namespace std;
// ���� ���� �Լ�, �߻�  �⺻ Ŭ����, �������̽� Ŭ����

class Animal {
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const = 0; //pure virtual function, body�� ����
	//Ŭ���� ����� ��ӱ����� �Ѳ����� �����ϵ��� �����ִ� ����

};

void Animal::speak() const { //pure�� ������ body �� ������ �� �ֱ� ��, ������ ����� ���¤�(ȣ��Ұ�)
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
	//Animal ani("HI"); //�����Ұ� -> pure virtual function�� �ϳ��� �� Ŭ���� = abstract class -> object�� ���� �� ����
	
	Cow cow("hello"); //speak������ �����Ұ� -> �ڽ�Ŭ�������� speak�� override������ ������ �����Ұ�
	cow.speak();
}