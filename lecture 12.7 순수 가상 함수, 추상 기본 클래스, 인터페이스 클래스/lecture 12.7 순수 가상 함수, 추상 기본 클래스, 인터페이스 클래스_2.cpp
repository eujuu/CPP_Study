#include <iostream>
#include <string>
using namespace std;
//  인터페이스 클래스
// = 내부에 있는 함수들이 모두 pure virtual function일 경우
//  ~을 해야한다만 가지고 있는 구조

class IErrorLog {
public:
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog {
public: 
	bool reportError(const char* errorMessage) override {
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog {
public:
	bool reportError(const char* errorMessage) override {
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log) { //인터페이스 타입
	log.reportError("Runtime error");
}

int main() {

	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log); //상속을 받는 구조이기에 가능
	doSomething(console_log);
	
}