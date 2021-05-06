#pragma once
#include <iostream>

class Student {
public:
	Student();
	Student(unsigned int groupNumber, std::string lastName);
	Student(const Student& student);
	virtual ~Student();

	void setGroupNumber(unsigned int groupNumber);
	void setLastName(std::string lastName);
	void setGroupNumber(std::istream& in);
	void setLastName(std::istream& in);


	unsigned int getGroupNumber()const { return m_groupNumber; }
	virtual std::string getLastName()const { return m_lastName; }

	void operator()(std::string lastname);
	Student& operator= (const Student& student);

private:
	unsigned int m_groupNumber;
	std::string m_lastName;
};

std::ostream& operator <<(std::ostream& out, const Student& s);
std::istream& operator >>(std::istream& in, Student& s);