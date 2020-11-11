#pragma once

#include"Person.h"

class Student : public Person {
private:
	//std::string m_name; //teacher과 동일한 변수
	int m_intel;//intelligence(Student만의 고유 변수)

public:
	Student(const std::string& name_in = "No Name", const int& intel_in = 0)
		//:m_name(name_in), m_intel(intel_in)  //student가 생성될 때 m_name은 정의가 되어 있지않음 -> 당근 오류  -> Person의 생성자를 호출해서 간접적으로 사용
		:Person(name_in), m_intel(intel_in)
	{

	}

	void setIntel(const int& intel_in) {
		m_intel = intel_in;
	}

	int getIntel() {
		return m_intel;
	}

	void study() {
		std::cout << getName() << " is studying. " << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Student& student) {
		out << student.getName() << " " << student.m_intel;
		return out;
	}
};
