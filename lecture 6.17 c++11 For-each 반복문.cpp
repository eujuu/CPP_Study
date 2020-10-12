#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
struct Person {
	int age;
	double weight;
};
int main() {
	// int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,34, 55, 89 };

	vector<int>fibonacci = { 0, 1, 1, 2, 3, 5, 8, 13, 21,34, 55, 89 };
	int max_num = numeric_limits<int>::lowest();
	for (const auto& num : fibonacci)
		max_num = max(max_num, num);
	cout << max_num;
}