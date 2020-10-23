#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;
//����ð� �����ϱ�

class Timer {
	using  clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1>>;

	chrono::time_point<clock_t> start_time = clock_t::now(); //���۽ð�(Timer�� ����������� ����ð��� ��� ��)

public:
	void elapsed() {
		chrono::time_point<clock_t> end_time = clock_t::now(); //���� �ð�
		
		cout << chrono::duration_cast<second_t>(end_time - start_time).count() << endl; //�ʷ� ��ȯ�ؼ� ���
	}
};
int main() {
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() }; //random number generator
	
	vector<int> vec(100000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	shuffle(begin(vec), end(vec), mersenne_engine);//����

	//for (auto& e : vec) cout << e << " ";
	//cout << endl;

	Timer timer;
	sort(begin(vec), end(vec));

	timer.elapsed();

	//Debug: 0.269
	//Release: 0.006(������ release�� �����ϱ� ������ ���������ð��� release�� ���)
	//�ð� ������ ���� �� �����(���� ��ҿ�(��Ƽ������ ����, ��, Ŭ��, Ÿ ���α׷� ��� ���� ��) ���� �ð��� �޶����Ƿ�)

	//for (auto& e : vec) cout << e << " ";
	//cout << endl;

}