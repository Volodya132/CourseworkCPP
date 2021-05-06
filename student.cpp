#include "student.h"
#include "stringfunc.h"

#include <stdexcept>
#include <locale> 


Student::Student()
	: m_groupNumber(0)
	, m_lastName("")
{ }

Student::Student(unsigned int groupNumber, std::string lastName)
	: m_groupNumber(groupNumber)
	, m_lastName(lastName)
{ }

Student::Student(const Student& student)
	: m_groupNumber(student.m_groupNumber)
	, m_lastName(student.m_lastName)
{ }

Student::~Student()
{
	m_groupNumber = 0;
	m_lastName = "";
}

void Student::setGroupNumber(unsigned int groupNumber)
{
	if (groupNumber < 1)
	{
		throw std::invalid_argument("Некоректний ввід!");
	}
	m_groupNumber = groupNumber;
}

void Student::setLastName(std::string lastName)
{ 
	
	if (lastName.empty())
	{
		throw std::invalid_argument("Некоректний ввід!");
	}
	if (isUA(lastName) || isENG(lastName))
	{
		m_lastName = lastName;
		return;
	}
	else
	{
		throw std::invalid_argument("Некоректний ввід! Очікується українська або англійська мова!");
	}
		
}

void Student::setGroupNumber(std::istream& in)
{
	int groupNumber;
	std::cout << "Введіть номер групи: "; in >> groupNumber;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "Некоректний ввід!" << std::endl;
		setGroupNumber(in);
		return;
	}
	try
	{
		setGroupNumber(groupNumber);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		setGroupNumber(in);
	}
}

void Student::setLastName(std::istream& in)
{
	std::string lastName;
	std::cout << "Введіть прізвище студента: "; getline(in, lastName);
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "Некоректний ввід!" << std::endl;
		setLastName(in);
		return;
	}
	try
	{
		setLastName(lastName);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		setLastName(in);
	}
}

std::ostream& operator <<(std::ostream& out, const Student& s)
{
	out << "Номер групи: " << s.getGroupNumber() << std::endl;
	out << "Прізвище: " << s.getLastName() << std::endl;
	return out;
}

std::istream& operator >>(std::istream& in, Student& s)
{
	s.setGroupNumber(in);
	in.clear();
	in.ignore(32767, '\n');
	s.setLastName(in);
	return in;
}

void Student::operator()(std::string lastname)
{
	m_lastName = lastname;
}

Student& Student::operator= (const Student& student)
{
	this->m_lastName = student.m_lastName;
	this->m_groupNumber = student.m_groupNumber;

	return *this;
}