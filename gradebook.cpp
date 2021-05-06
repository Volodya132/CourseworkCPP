#include "gradebook.h"

#include <algorithm>


GradeBook::GradeBook(const MyVector<Exam> &exams)
	: m_exams(exams)
{
}

GradeBook::~GradeBook()
{
	m_exams.clear();
}

void GradeBook::addExam(Exam exam)
{
	m_exams.addElement(exam);
}

void GradeBook::addExam(std::istream& in)
{
	Exam exam;
	in >> exam;
	addExam(exam);
}

void GradeBook::popExam(std::istream& in)
{
	size_t key = 0;
	std::cout << "������ ������: "; in >> key;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "����������� ���!" << std::endl;
		popExam(in);
		return;
	}
	try
	{
		return m_exams.popElement(key);
	}
	catch (std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
		popExam(in);
	}
}
Exam& GradeBook::getExam(std::istream& in)
{
	size_t key = 0;
	std::cout << "������ �����: "; in >> key;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "����������� ���!" << std::endl;
		getExam(in);
	}
	try
	{
		key--;
		return getExam(key);
	}
	catch (std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
		getExam(in);
	}
}

void GradeBook::changeElement(std::istream& in)
{
	Exam& exam = getExam(in);
	int answer = 0;
	std::cout << "�� ������ ������? " << std::endl;
	std::cout << "1. ���������. " << std::endl;
	std::cout << "2. ��������. " << std::endl;
	std::cout << "3. ���� ����������. " << std::endl;
	std::cout << "4. ���������. " << std::endl;
	std::cout << "5. ʳ������ �����. " << std::endl;
	std::cout << "6. ������. " << std::endl;
	std::cout << "0. �����. " << std::endl;
	in >> answer;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "����������� ���! ��������� �����! " << std::endl;
		answer = -1;
		changeElement(in);
		return;
	}
	in.clear();
	in.ignore(32767, '\n');
	switch (answer)
	{
	case 1: exam.setTeacher(in); break;
	case 2: exam.setStudent(in); break;
	case 3: exam.setDateExam(in); break;
	case 4: exam.setNameDiscipline(in); break;
	case 5: exam.setCountHours(in); break;
	case 6: exam.setRating(in); break;
	default:
		break;
	}
}

Exam& GradeBook::getExam(size_t key)
{
	try
	{
		return m_exams.getElement(key);
	}
	catch (std::out_of_range& ex) { 
		std::cout << ex.what() << std::endl;
		getExam(std::cin);
	}
}

size_t GradeBook::getSize()
{
	return m_exams.getSize();
}

Exam GradeBook::first_exam()
{
	return *(std::min_element(m_exams.begin(), m_exams.end()));
}

Exam GradeBook::last_exam()
{
	return *(std::max_element(m_exams.begin(), m_exams.end()));
}




std::ostream& operator<<(std::ostream& out, GradeBook& s)
{
	for (auto iter = s.m_exams.begin(); iter != s.m_exams.end(); iter++)
	{
		std::cout << "********   ������� " << (iter - s.m_exams.begin()) + 1 <<"   ********" << std::endl;
		out << *iter << std::endl;
	}
	return out;
}
