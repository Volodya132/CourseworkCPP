#pragma once

#include "student.h"
#include "teacher.h"
#include "date.h"

#include <string>

class Exam : public Student, public Teacher
{
public:
	
	Exam(Student student, Teacher teacher, std::string nameDiscipline, unsigned int countHours, Date dateExam, unsigned int rating);
	virtual ~Exam();

	void setStudent(Student& student);
	void setTeacher(Teacher& teacher);
	void setStudent(std::istream& in);
	void setTeacher(std::istream& in);
	void setNameDiscipline(std::string nameDiscipline);
	void setCountHours(unsigned int countHours);
	void setDateExam(Date dateExam);
	void setRating(unsigned int rating);
	void setNameDiscipline(std::istream& in);
	void setCountHours(std::istream& in);
	void setDateExam(std::istream& in);
	void setRating(std::istream& in);

	std::string getNameDiscipline()const { return m_nameDiscipline; }
	unsigned int getCountHours()const { return m_countHours; }
	Date getDateExam()const { return m_dateExam; }
	unsigned int getRating()const { return m_rating; }
	virtual std::string getLastName()const;

private:
	std::string m_nameDiscipline;
	unsigned int m_countHours;
	Date m_dateExam;
	unsigned int m_rating;
};

std::istream& operator >>(std::istream& in, Exam& exam);
std::ostream& operator <<(std::ostream& out, const Exam& exam);
bool operator<(const Exam&, const Exam&);
bool operator>(const Exam&, const Exam&);