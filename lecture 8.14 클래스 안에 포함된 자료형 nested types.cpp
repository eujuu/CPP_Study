#include <iostream>
#include <string>
using namespace std;
//Ŭ���� �ȿ� ���Ե� �ڷ��� Nested Types 
//(��ɿ� ���߾� Ư�� �ڷ����� ����� ���)
//->�ش� �ڷ����� Ŭ���� �ȿ����� ���

class Fruit {

public:
	enum FruitType { //Fruit Ŭ���������� ���� ���ɼ��� ���� ���, enum class �� ����
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
	//Fruit banana(Fruit::FT_cl::BANANA); //������ Ÿ�Ժ�ȯ ��
	if (apple.getType() == Fruit::APPLE) { //��
		cout << "Apple" << endl;
	}
}s