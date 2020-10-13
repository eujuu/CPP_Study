#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//�������� ��� �̴ϼȶ����� ����ƮMember Initializer List(��� �ʱ�ȭ ����Ʈ)
class B {
private:
    int m_b;
public:
    B(const int& m_b_in) : m_b(m_b_in) {

    }
};
class Something {
private:

    int     m_i = 100;
    double  m_d = 100.0;
    char    m_c = 'F';
    int     m_arr[5] =  { 100, 200, 300, 400, 500 };
    B       m_b{ 1024 };
    //non static member�����̷��Ե� �ʱ�ȭ ����, �����ڿ� �ʱ�ȭ ��� �Ǿ� �ִٸ� �������� �켱������ �� ����(����� ���õ�)
public:
    Something()
        //: m_i(1), m_d(3.14), m_c('a')//�ʱ�ȭ
        : m_i{ 1 }
        , m_d{ 3.14 }
        , m_c{ 'a' }
        , m_arr{ 1, 2, 3, 4, 5 }
        , m_b{ m_i - 1 } //�� ����, ����ȯ�� �ȵȴٴ� ��.(�ڵ����� cast ������)
    {
        m_i *= 2; m_d *= 3.0, m_c += 3; 
        //initializer���� �ٽ� �� ������ ���ֱ� ������ ������ ���� �� ������ ��
        //initializer list�� ���õȰ� �ƴ�!!
    }
    void print() {
        cout << m_i << " " << m_d << " " << m_c << endl;
        for (auto& e : m_arr)
            cout << e << " ";
        cout << endl;
     
    }
};
int main() {
    Something som;
    som.print();
}