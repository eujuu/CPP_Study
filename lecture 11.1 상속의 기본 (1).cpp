#include <iostream>
#include <cassert> //assert.h
#include <string>
#include <cmath> //sin(), cos()
#include <vector>
using namespace std;
//����� �⺻ Inheritance (is-a relationship) - 1
// ��ü���⿡�� ���� �߿�
// �������� ����(��� �⺻, ������)
// �θ� �ڽĿ��� ���𰡸� �Ѱ��ش�.
// �θ� Ŭ������ ������� ����. �ٸ� ������ ���� ��


class Mother { //�θ�, Generalized Class(���� Ŭ������ ����Ǵ� �κ��� ������ Ŭ���� -> �Ϲ�ȭ�� Ŭ����)
//protected : //private����, �ڽ����״� ��� o
private:  //private�� �ڽ����׵� ��� x

	int m_i;

public:
	Mother() :m_i(0){}
	
	Mother(const int& i_in) //���� -> parameter�� ������ �����ڰ� ���� default�����ڰ� �����
		: m_i(i_in)
	{
		cout << "Mother Constructor " << endl;
	}
	
	void setValue(const int& i_in) {
		m_i = i_in;
	}
	int getValue() {
		return m_i;
	}
};
//���
class Child : public Mother { //Child class is derived from mother class
	//Encapsulation����
private:
	double m_d;
public:
	//�����ڴ� �θ� Ŭ�����κ��� ���� ������ ���θ� �����ִ� ����(?)�� ������ �Բ� ����ϱ� ����
	// +) ������ ���� ���� = �޸� �Ҵ�� �� initialize�ϱ�����(�޸� �Ҵ�ǰ� �ű⿡ �����ؼ��־��ּ��� �� �ƴ�!!)
	
	//****** child Ŭ������ ������ �� �� �ڵ����� Mother class�� default �����ڸ� ���� ȣ���ϰ� ��

	Child(const int& i_in, const double& d_in)
		//:m_i(i_in),m_d(d_in) //private, protected ��� �Ұ� ->�� ������ �ƴ�
		//�� ������δ� �ʱ�ȭ �Ұ� -> m_i�� �޸𸮰� ���� �����̱⿡
		//initialize list���x

		//+����� ���^^
		:Mother(i_in),m_d(d_in)
	{
		/*
		Mother::setValue(i_in);
		m_d = d_in;
		*/
	}

	void setValue(const int& i_in, const double& d_in) {
		//m_i = i_in; //Mother �� ���� m_i�� ���� �Ұ�(private)
		Mother::setValue(i_in); //Mother class�� setValue ȣ��
		m_d = d_in;
	}
	void setValue(const double& d_in) {
		m_d = d_in;
	}
	double getValue() {
		return m_d;
	}
};
class Daughter :public Mother {

};
class Son : public Mother {

};
int main() {
	Mother mother(1024);
	//Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl; //1024

	Child child(1024, 128);
	//child.setValue(128);
	//child.setValue(128);
	child.Mother::setValue(1024);

	cout << child.getValue() << endl; //128  //mother�� �Ȱ��� �۵� -> mother�� �͵��� �⺻������ ���
									  //������ ��
	//child�� ȣ���ϴ� getValue�� �켱���� ȣ��,  ������ Mother Ŭ��������.
	cout << child.Mother::getValue() << endl; //1024


}