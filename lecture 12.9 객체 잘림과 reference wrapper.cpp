#include <iostream>
#include <string>
#include <vector>
#include <functional> //reference_wrapper
using namespace std;
// ��ü �߸�(object slicing)�� reference_wrapper
// �θ𺸴� �ڽ� Ŭ������ �� ���� ������ ��������

// ��ü�� �����δ����ϸ�?  -> �ڽ�Ŭ�������� �ִ� �������� �߷�������� = ��ü�߸�
// reference wrapper-> �̸� ����

class Base {
public:
	int m_i = 0;

	virtual void print() {
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base {
public:
	int m_j = 1;

	virtual void print() override {
		cout << "I'm derived" << endl;
	}
};

void doSomething(Base b) {
	b.print();
}

int main() {
	Derived d;
	Base b = d;
	Base b1;

	b.print(); 
	//(&����)derived ���
	//(&���X,�������)base ���-> �������� �����

	doSomething(d); 
	//(�Ķ���Ϳ� &����)derived���, ����������
	//(�Ķ���Ϳ� &���X)base���, ������ ����X

	//vector<Base>my_vec;
	//vector<Base&>my_vec;  //vector�� ���۷��� & ��� �Ұ���
	vector<Base*>my_vec;

	my_vec.push_back(&b1);
	my_vec.push_back(&d);

	for (auto& ele : my_vec) {
		//ele.print(); //base�϶�
		ele->print();
	}
	//base, base��� -> derived�� �־�����, push back�������� slicing�� �߻��ؼ�  �� �� base����
	//(�����ͻ��) base, derived  ���

	vector<reference_wrapper<Base>> my_vec2; //reference�� �����ϴ� ���Ͱ� ��

	my_vec2.push_back(b1);
	my_vec2.push_back(d);

	for (auto& ele : my_vec2) {
		ele.get().print(); //reference�� ���� �޾ƿ�(get)
	}
	//base, derived ���
}