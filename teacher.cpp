#include "teacher.h"
#include "stringfunc.h"

Teacher::Teacher()
	: m_occupation("")
	, m_lastName("")
{ }

Teacher::Teacher(std::string m_occupation, std::string lastName)
	: m_occupation("")
	, m_lastName("")
{ }

Teacher::Teacher(const Teacher & teacher)
	: m_occupation(teacher.m_occupation)
	, m_lastName(teacher.m_lastName)
{
}

Teacher::~Teacher()
{
	m_occupation = "";
	m_lastName = "";
}

void Teacher::setOccupation(std::string occupation)
{
	if (occupation.empty())
	{
		throw std::invalid_argument("����������� ���!");
	}
	m_occupation = occupation;
}

void Teacher::setLastName(std::string lastName)
{
	if (lastName.empty())
	{
		throw std::invalid_argument("����������� ���!");
	}
	if (isUA(lastName) || isENG(lastName))
	{
		m_lastName = lastName;
		return;
	}
	else
	{
		throw std::invalid_argument("����������� ���! ��������� ��������� ��� ��������� ����!");
	}
}

void Teacher::setOccupation(std::istream& in)
{
	std::string ocupation;
	std::cout << "������ ������ ���������: "; getline(in, ocupation);
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "����������� ���!" << std::endl;
		setOccupation(in);
		return;
	}
	try
	{
		setOccupation(ocupation);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		setOccupation(in);
	}
}

void Teacher::setLastName(std::istream& in)
{
	std::string lastName;
	std::cout << "������ ������� ���������: "; getline(in, lastName);
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "����������� ���!" << std::endl;
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

std::ostream& operator <<(std::ostream& out, const Teacher& t)
{
	out << "������: " << t.getOccupation() << std::endl;
	out << "�������: " << t.getLastName() << std::endl;
	return out;
}

std::istream& operator >>(std::istream& in, Teacher& t)
{
	t.setOccupation(in);
	t.setLastName(in);
	return in;
}

void Teacher::operator()(std::string lastname)
{
	m_lastName = lastname;
}

Teacher& Teacher::operator= (const Teacher& teacher)
{
	this->m_occupation = teacher.m_occupation;
	this->m_lastName = teacher.m_lastName;

	return *this;
}
