#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

// Object = 데이터 + 기능
// Friend : name, address, age, height, weight, ...
//			print()

//struct Friend { //데이터를 묶어줄 때 struct사용

class Friend{ //기능 사용시 class 주로 사용
public:  //access specifier(접근 지정자)
	string m_name; //member variable(public, private, protected)
	string m_address;
	int m_age;
	double height_;
	double _weight; //m_(variable), _(variable), (variable)_ 이런식으로들 많이 지음
	//ver3
	void Print() {
		cout << m_name << " " <<m_address << " " << m_age << " " << height_ << " " <<_weight << endl;
	}
};

//ver2
void Print(const Friend& fr) {
	cout << fr.m_name << " " << fr.m_address << " " << fr.m_age << " " << fr.height_ << " " << fr._weight << endl;
}

//ver1
void Print(const string& name, const string& address, const int& age, const double& height, const double& weight) {
	cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
}
int main() {
	Friend jj{"ej", "yi", 24, 163, 51}; //메모리를 차지하도록 정의 해주는 것 = instanciation, Friend는 인스턴스라고 불림
	cout << &jj << endl;

	//Print(jj.name, jj.address, jj.age, jj.height, jj.weight);
	//Print(jj);
	jj.Print();

	vector<Friend> my_friends;
	my_friends.resize(2);

	for (auto& ele : my_friends)
		ele.Print();


	//vector< string> name_vec;
	//vector<string> addr_vec;
	//vector <int> age_vec;
	//vector<double> height_vec;
	//vector<double> weight_vec;

	

}