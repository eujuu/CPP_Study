#include <iostream>
using namespace std;
// 다중상속, 다이아몬드 상속 구조


class A {
	
};

class B1 : public A {

};

class B2 : public A {

};
class C : public B1, public B2 {

};

int main() {


}