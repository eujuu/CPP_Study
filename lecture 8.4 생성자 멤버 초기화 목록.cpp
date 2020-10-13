#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
//생성자의 멤버 이니셜라이져 리스트Member Initializer List(멤버 초기화 리스트)
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
    //non static member들은이렇게도 초기화 가능, 생성자와 초기화 모두 되어 있다면 생성자의 우선순위가 더 높다(여기는 무시됨)
public:
    Something()
        //: m_i(1), m_d(3.14), m_c('a')//초기화
        : m_i{ 1 }
        , m_d{ 3.14 }
        , m_c{ 'a' }
        , m_arr{ 1, 2, 3, 4, 5 }
        , m_b{ m_i - 1 } //도 가능, 형변환은 안된다는 점.(자동으로 cast 안해줌)
    {
        m_i *= 2; m_d *= 3.0, m_c += 3; 
        //initializer이후 다시 값 대입을 해주기 때문에 마지막 값이 위 라인이 됨
        //initializer list가 무시된게 아님!!
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