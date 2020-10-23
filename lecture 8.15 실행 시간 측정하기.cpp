#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;
//실행시간 측정하기

class Timer {
	using  clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1>>;

	chrono::time_point<clock_t> start_time = clock_t::now(); //시작시간(Timer가 만들어질때의 현재시간을 재게 됨)

public:
	void elapsed() {
		chrono::time_point<clock_t> end_time = clock_t::now(); //끝난 시간
		
		cout << chrono::duration_cast<second_t>(end_time - start_time).count() << endl; //초로 변환해서 출력
	}
};
int main() {
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() }; //random number generator
	
	vector<int> vec(100000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	shuffle(begin(vec), end(vec), mersenne_engine);//섞기

	//for (auto& e : vec) cout << e << " ";
	//cout << endl;

	Timer timer;
	sort(begin(vec), end(vec));

	timer.elapsed();

	//Debug: 0.269
	//Release: 0.006(배포시 release로 배포하기 때문에 실제측정시간은 release로 사용)
	//시간 측정은 여러 번 재야함(여러 요소에(멀티쓰레딩 유무, 쿨러, 클락, 타 프로그램 사용 여부 등) 의해 시간이 달라지므로)

	//for (auto& e : vec) cout << e << " ";
	//cout << endl;

}