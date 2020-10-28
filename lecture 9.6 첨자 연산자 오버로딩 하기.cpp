#include <iostream>
#include <cassert>
using namespace std;
//÷�� ������ �����ε� ([], subscript operator)


class IntList {
private:
	int m_list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

public:
	void setItem(int idx, int val) {
		m_list[idx] = val;
	}

	int getItem(int idx) {
		return m_list[idx];
	}

	int* getList() {
		return m_list; //array��ü�� pointer
	}

	int& operator [](const int idx) { //���۷��� ����: ���� �а� �ٲ� ���� �ֱ� ����
		assert(idx >= 0);
		assert(idx < 10); //���� ����� �� ����
		//�� if�� �Ⱦ���?? []�� ��û ���� ���� -> if�� ���ٸ� �ξ� ������ ��...����X

		return m_list[idx];
	}
	const int& operator [](const int idx) const { //�̰� �־�� const��ü�� ���ؼ��� �б� ����(�ȹٲٴ���)
		assert(idx >= 0);
		assert(idx < 10); //���� ����� �� ����

		return m_list[idx];
	}
};
int main() {
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl; //method 1
	my_list.getList()[3] = 10; //�� ��ȯ
	cout << my_list.getList()[3] << endl;

	//�����ε�
	my_list[3] = 100; //�׻� �ּҸ� ������ �ִ� lvalue���� �� -> ���۷��� ���
	cout << my_list[3] << endl;
	cout << my_list[-1] << endl;

	const IntList my_constlist;
	cout << my_constlist[3] << endl;

	IntList* list = new IntList;
	 (*list)[3] =10; // OK
	//list[3] = 10; // Not Ok, list�� ������

}