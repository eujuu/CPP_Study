#include <iostream>
#include <string>
using namespace std;
//클래스 안에 포함된 자료형 Nested Types 
//(기능에 맞추어 특정 자료형을 만들어 사용)
//->해당 자료형이 클래스 안에서만 사용

class Fruit {

public:
	enum FruitType { //Fruit 클래스에서만 사용될 가능성이 높을 경우, enum class 도 가능
		APPLE, BANANA, CHERRY,
	};
	enum class FT_cl {
		APPLE, BANANA, CHERRY,
	};
	class InnerClass {

	};
	struct InnerStruct {

	};
	

private:
	FruitType m_type;
public:
	Fruit(FruitType type):m_type(type)
	{}

	FruitType getType() { return m_type; }
};
int main() {
	Fruit apple(Fruit::APPLE);
	//Fruit banana(Fruit::FT_cl::BANANA); //생성자 타입변환 필
	if (apple.getType() == Fruit::APPLE) { //비교
		cout << "Apple" << endl;
	}
}s