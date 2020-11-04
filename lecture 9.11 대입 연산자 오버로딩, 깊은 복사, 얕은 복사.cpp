#include <iostream>
#include <cassert> //assert.h
#include <array>
using namespace std;
// ���� ������ �����ε�, �������� vs ���� ���� Deep copy vs Shallow copy
// ���� �Ҵ�� �޸𸮿� ���� ������ ������ ����ν� ������ �ִ� ���
// -> ���� ����� ���� ����Ŀ� ���� 

//�����Ҵ� �ϱ� ������ �׳� string ������(�����ս��� �� ������ �� ����)
// �ʿ��� �κ��� ��ӹ޾Ƽ� �߰� ����

class MyString {
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "") {
		cout << "Constructor" << endl;
		assert(source); //���� �ʾҴ���

		m_length = strlen(source) + 1; //���ڰ��� + 1, (���ڿ��� �������� �˸�������)��ĳ���� �ڸ� �߰�1
		m_data = new char[m_length];

		for (int i = 0; i < m_length; i++)
			m_data[i] = source[i]; //�� ����

		m_data[m_length - 1] = '\0'; //��ĳ����
	}
	~MyString() {
		//cout << "Destructor" << endl;
		delete[] m_data; //�޸� �����(leak�� ���� ����)
	}

	//Copy Constructor
	MyString(const MyString& source) {
		cout << "Copy Constructor " << endl;
		// �޸� �ٽ� �Ҵ�, ���� ���� -> ���� ����
		// �׳� �ּ� ���� -> ���� ����

		
		m_length = source.m_length;

		if (source.m_data != nullptr) {
			m_data = new char[m_length]; // �޸� ���� �Ҵ�
			for (int i = 0; i < m_length; i++)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
			//m_data = 0;
			
	}
	//���� ������ ���⿣ �ٻڰ� ���� ���縦 ���� ������,,?
	//MyString(const MyString& source) = delete; //�ƿ� ���ƹ�����!

	//Assignment operator
	MyString& operator = (const MyString& source) {
		//shallow copy
		/*
			this -> m_data = source.m_data;
			this-> m_length = source.m_length; //default
			//�����Ҵ翡�� �� ����� ū ������ �� �� �ִ�!!
		*/

		cout << "Assignment operator " << endl;

		// �ڱⰡ �ڱ����� ����
		// MyString hello("Hello"); hello = hello; 
		// �̷��� ��쿡 �ƹ��͵� ���� ���ϰ� ����
		if (this == &source) return *this; //prevent self-assignment

		delete[] m_data; //���� ������ ����(���� �̹� ���� �־��� �� �����ϱ�,,)

		
		m_length = source.m_length;

		if (source.m_data != nullptr) {
			m_data = new char[m_length]; // �޸� ���� �Ҵ�
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

	cout << (int*)hello.m_data << endl; //�ּ�
	cout << hello.getString() << endl;

	{
		MyString copy = hello;// ���� ������ ȣ��(�����ϰ� �ִ� ���̹Ƿ�), ������ ���ϸ� �⺻ �����ڰ� ȣ���(���� ����)
		//copy = hello; //���� ������ ȣ��
		cout << (int*)copy.m_data << endl;//copy�� hello�� �ּ� �����ʹ� ����
		cout << copy.getString() << endl; //copy�� ������ �ּҸ� ���縸��
		//�ڱⰡ new�� �� ���� ����. ������ new�� �Ҵ�Ȱ� �Ѱ��� �ִ� ��
		//�Ҹ��ڰ� ȣ��Ǹ鼭 delete�� �ϰ� ��
		//hello�� m_data�� ���� �ּҸ� ����Ű�� ����, �������� �� �����Ͱ� �Ҹ��ڷ� ���� ������ ����
	}//copy�� �Ҹ�

	//copy constructor, assignment overloading ����!!

	cout << hello.getString() << endl; //���� ������ Ȥ�� ���Կ����ڰ� ������ ����(�ּҰ��� �����Ǿ����Ƿ�)

	MyString str1 = hello; // copy constructor
	//MyString str1(hello);
	//�򰥸��� ������ ��ó�� ����; 
	MyString str2;
	str2 = hello; // assignment operator

	
}