#include <iostream>
#include <cassert> //assert.h
#include <array>
using namespace std;
// �ܾ��ϱ� assert
// ���α׷����� ����뿡 ��κ� �ð� �Ҹ� ->  �����Ϸ��� ������ ���� �� �ִٸ�?!??!
// assert -> run time�� üũ����
// static assert -> compile time�� ���� �߻���Ŵ

void printVal(const array<int, 5>& my_arr, const int& idx) {
	assert(idx >= 0);
	assert(idx <= my_arr.size() - 1); //���� ������ �� �� �ְ� ��

	
	cout << my_arr[idx] << endl;
}

int main() {
	//Release ��忡���� �۵� ����(assert�� ���귮 �Ҹ�Ǳ� ������)
	//Debug��忡�� ���α׷��Ӱ� �׽�Ʈ �� �� ���, ������ ã����

	//assert(false); //�����߻� ���� �˷���,

	const int num = 5;
	assert(num == 5); //�ݵ�� 5���߸� �Ѵ�. comment ����..
	//�ּ��� ���ܵθ� 5���� �ƴ��� ������ ��

	array<int, 5> my_arr{1, 2, 3, 4, 5};
	printVal(my_arr, 4);

	const int x = 5;
	assert(x == 5);
	// ������ �߰��� �ٲ� �� �����Ƿ� static_assert ��� �Ұ� -> const�� ���� ��� ����
	static_assert(x == 5, "x should be 5"); //���� �޽��� �߰�
}