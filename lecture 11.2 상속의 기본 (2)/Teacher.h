#pragma once

#include"Person.h" //string�� ���⼭

class Teacher : public Person {
private:
	//std::string m_name; //student�� ������ ����

public:
	Teacher(const std::string& name_in = "No Name")
		//:m_name(name_in)
		:Person(name_in)
	{
		//this->getName(); //���� ����
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
