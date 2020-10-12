#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//Constructors(������)
//��������ڸ��� �̷��� �Ӽ��� ������ �־�� ��!
class Second {
public: 
	Second() {
		cout << "Class Second constructor()" << endl;
	}
};
class  First {
	Second sec;
public:
	First() {
		cout << "Class First constructor()" << endl;
	}
};
class Fraction { //�м�
private:
	int m_numerator; //����
	int m_denominator; //�и�
	//2, ���� ����� �ʱ�ȭ
	// int m_numerator = 0;
	// int m_denominator = 1;

public:
	// �����ڴ� �⺻������ �ƹ� �ϵ� ���ϴ� ���·� ������ ����, �����ڰ� ������ �ν��Ͻ� ���� �ƿ� �Ұ�
	// �����ڴ� �ν��Ͻ��� ����°� �ƴ�, �׳� ����ɶ� ȣ��Ǵ� �Լ�! �̸��� ��Ȥ���� ����
	// Fraction() {} //�� ���� �����ڸ� ����� �⺻ �����ڴ� ������ �ʴ´�.
	//3, ������
	Fraction() {
		m_numerator = 0;
		m_denominator = 1;
	}
	Fraction(const int &num_in /*= 0*/, const int & den_in = 1) { 
		//�ǵ��� ȣ�� x, �ڵ����� ȣ���� �ȴ�.
		//Ŭ������ ������ �ʰ� ���ÿ� ���� �ȴ�.
		m_numerator = num_in;
		m_denominator = den_in;
		cout << "Fraction() Constructor" << endl;
	}

	void print() {
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

int main() {
 	Fraction fra; //������ ����(�޸𸮿� �ڸ��� ��� �� �ڿ� �ٷ� ����ȴ�)
	//�������� �Ķ���Ͱ� �ϳ��� ���� ��쿣 ()�� �׻� ����!! ����Ʈ ���� �̿��Ҷ����� �ƹ��͵� �Ⱦ��� ��ȣ ���־� ��
	fra.print();


	Fraction oneThirds(1.0, 3); 
	// Fraction oneThirds = Fraction{1, 3}; //���� X
	// Fraction oneThirds{1, 3}; //�����ڰ� ���� ��� uniform Intialization�� ����! ������ ȣ�����ش�!

	// unifrom Initialization = Ÿ�� ��ȯ�� ������� �ʴ´�. �� �� ����(copy initialization����)
	// Fraction oneThirds{1.0, 3}; //����
	// Fraction oneThirds(1.0, 3); //warning�� �߰� �Ǳ� ��
	oneThirds.print();

	//1, public ������ �ٲ��� �� ���� ����
	//Fraction fra{ 0, 1 };
	
	First fir; //second�� �����ڰ� ���� ����ǰ� �� ���� first�� �����ڰ� �����
	//second�� first�� member�̹Ƿ�, memeber�� ���� �ʱ�ȭ�� ���־�� first�� �۾� ����!
	//�׷��⿡ second�� ����!


}