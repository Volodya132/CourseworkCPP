#include "exam.h"
#include "stringfunc.h"

#include <fstream>

Exam::Exam()
	: m_nameDiscipline("")
	, m_countHours(0)
	, m_dateExam()
	, m_rating(0)
{ }


Exam::Exam(Student student, Teacher teacher, std::string nameDiscipline, unsigned int countHours, Date dateExam, unsigned int rating)
	: Student(student)
	, Teacher(teacher)
	, m_nameDiscipline(nameDiscipline)
	, m_countHours(countHours)
	, m_dateExam(dateExam)
	, m_rating(rating)
{

}

Exam::~Exam()
{
	m_nameDiscipline = "";
	m_countHours = 0;
	m_dateExam = Date();
	m_rating = 0;
}

void Exam::setStudent(Student& student)
{
	setGroupNumber(student.getGroupNumber());
	Student::setLastName(student.getLastName());
}

void Exam::setTeacher(Teacher& teacher)
{
	setOccupation(teacher.getOccupation());
	Teacher::setLastName(teacher.getLastName());
}

void Exam::setNameDiscipline(std::string nameDiscipline)
{
	if (nameDiscipline.empty())
	{
		throw std::invalid_argument("Некоректний ввід!");
	}
	m_nameDiscipline = nameDiscipline;
}

void Exam::setCountHours(unsigned int countHours)
{
	if (countHours < 0)
	{
		throw std::invalid_argument("Некоректний ввід!");
	}
	m_countHours = countHours;
}

void Exam::setDateExam(Date dateExam)
{
	m_dateExam = dateExam;
}

void Exam::setRating(unsigned int rating)
{
	if ((rating < 0) || (rating > 100))
	{
		throw std::invalid_argument("Некоректний ввід!");
	}
	m_rating = rating;
}

void Exam::setStudent(std::istream& in)
{
	Student student;
	std::cout << "-Введіть дані студента: " << std::endl;
	in >> student;
	setStudent(student);
	std::cout << std::endl;
}

void Exam::setTeacher(std::istream& in)
{
	Teacher teacher;
	std::cout << "-Введіть дані викладача: " << std::endl;
	in >> teacher;
	setTeacher(teacher);
	std::cout << std::endl;
	
}

void Exam::setNameDiscipline(std::istream& in)
{
	std::string nameDiscipline;
	std::cout << "-Введіть назву дисципліни: ";  getline(in, nameDiscipline);
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "Некоректний ввід!" << std::endl;
		setNameDiscipline(in);
		return;
	}
	try
	{
		setNameDiscipline(nameDiscipline);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		setNameDiscipline(in);
	}
	std::cout << std::endl;
}

void Exam::setCountHours(std::istream& in)
{
	int countHours;
	std::cout << "-Введіть кількість годин: "; in >> countHours;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "Некоректний ввід!" << std::endl;
		setCountHours(in);
		return;
	}
	try
	{
		setCountHours(countHours);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		setCountHours(in);
	}
	std::cout << std::endl;
}

void Exam::setDateExam(std::istream& in)
{
	Date date;
	std::cout << "-Введіть дату проведення екзамену: " <<std::endl;
	in >> date;
	setDateExam(date);
	std::cout << std::endl;
}

void Exam::setRating(std::istream& in)
{
	int rating;
	std::cout << "-Введіть оцінку: "; in >> rating;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "Некоректний ввід!" << std::endl;
		setRating(in);
		return;
	}
	try
	{
		setRating(rating);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		setRating(in);
	}
	std::cout << std::endl;
}

std::string Exam::getLastName() const
{
	return "Викладач: " + Teacher::getLastName() + '\n' +
		   "Студент: " + Student::getLastName();
}



std::ostream& operator <<(std::ostream& out, const Exam& exam)
{
	const Teacher *t = &exam;
	out << t->getLastName() << std::endl;
	//out << "Студент: " << exam.Student::getLastName() << std::endl;
	out << "Назва дисципліни: " << exam.getNameDiscipline() << std::endl;
	out << "Кількість годин: " << exam.getCountHours() << std::endl;
	out << "Дата проведення: " << exam.getDateExam() << std::endl;
	out << "Оцінка: " << exam.getRating() << std::endl;
	
	return out;
}

bool operator<(const Exam& ex1, const Exam& ex2)
{
	return ex1.getDateExam() < ex2.getDateExam();
}

bool operator>(const Exam& ex1, const Exam& ex2)
{
	return ex1.getDateExam() > ex2.getDateExam();
}

std::istream& operator>>(std::istream& in, Exam& exam)
{
	in.clear();
	in.ignore(32767, '\n');
	exam.setTeacher(in);
	exam.setStudent(in);
	exam.setNameDiscipline(in);
	exam.setCountHours(in);
	exam.setDateExam(in);
	exam.setRating(in);

	return in;
}
