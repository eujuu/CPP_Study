#include <iostream>
#include <cassert> //assert.h
#include <string>
using namespace std;
// ����� �μ� command line arguments
// main��ȣ���� �Ű�����

// 0: �������� �̸�
// ����: ������ �Է��� ������
// cmd���� ���� or �Ӽ� -> ����� -> ����μ����� ����� ������ �Է�
// cd ���
int main(int argc, char* argv[]) {
	// int argc: ����
	// char* argv[]: ���� ����
	
	for (int cnt = 0; cnt < argc; ++cnt) {
		string argv_single = argv[cnt]; //�����϶� string��ȯ�� ���

		if (cnt == 1) {
			int input_number = stoi(argv_single);
			cout << input_number + 1 <<endl;
		}
		cout << argv[cnt] << endl;
	}
	//boost library - ��ǥ�� ���̺귯�� - Ŀ�ǵ忡���� �� �� ���ϰ� �ۼ� ����
	return 0;
}