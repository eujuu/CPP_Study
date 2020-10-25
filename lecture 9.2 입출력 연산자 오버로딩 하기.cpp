#include <iostream>
#include <cstdarg> //for ellipsis
#include <fstream>
using namespace std;
//����� ������ �����ε� (<<, >>)

class Point {
private:
	double m_x, m_y, m_z;
public:
	Point(double x = 0.0, double y  =0.0, double z =0.0) : m_x(x), m_y(y), m_z(z){}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	void print() {
		cout << m_x << " " << m_y << " " << m_z << endl; //method1
	}
	
	//method2
	//file������ε� ��� ����
	friend ostream& operator << (ostream& out, const Point& point) { //(output stream, ��� ���)
		out << "(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")" <<endl;

		return out;
	}

	friend istream& operator >> (istream& in, Point& point) { //(input stream, �Է� ���)
		
		in >> point.m_x >> point.m_y >> point.m_z;
		return in;
	}
};
int main() {
	ofstream of("out.txt"); //�����̸�
	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5 , 2.0);
	
	//method1 ������� ����
	/*p1.print();
	cout << endl;
	p2.print();
	cout << endl;*/ 

	//method2
	cout << p1 << p2;
	of << p1 <<  p2 << endl; //���Ϸ� ����
	of.close();

	Point p3;
	cin >> p3;
	cout << p3;
}