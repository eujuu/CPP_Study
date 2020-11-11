#pragma once

#include"Person.h" //string은 여기서

class Teacher : public Person {
private:
	//std::string m_name; //student와 동일한 변수

public:
	Teacher(const std::string& name_in = "No Name")
		//:m_name(name_in)
		:Person(name_in)
	{
		//this->getName(); //문제 없음
	}
	void teach() {
		std::cout << getName() << " is teaching. " << std::endl;
	}
	friend std::ostream& operator << (std::ostream& out, const Teacher& teacher) {
		//out << teacher.m_name << " ";
		out << teacher.getName() << " ";
		return out;
	}
};
