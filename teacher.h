#pragma once
#include <iostream>


class Teacher{
public:
	Teacher();
	Teacher(std::string m_occupation, std::string lastName);
	Teacher(const Teacher& teacher);
	virtual ~Teacher();

	void setOccupation(std::string occupation);
	void setLastName(std::string lastName);
	void setOccupation(std::istream& in);
	void setLastName(std::istream& in);

	std::string getOccupation()const { return m_occupation; }
	virtual std::string getLastName()const { return m_lastName; }

	void operator()(std::string lastname);
	Teacher& operator= (const Teacher& teacher);
private:
	std::string m_occupation;
	std::string m_lastName;
}; 

std::ostream& operator <<(std::ostream& out, const Teacher& t);
std::istream& operator >>(std::istream& in, Teacher& t);