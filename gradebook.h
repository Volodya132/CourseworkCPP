#pragma once

#include "exam.h"
#include "MyVector.h"

#include <iostream>
#include <string>


class GradeBook {
public:
	GradeBook() = default;
	GradeBook(const MyVector<Exam>& exams);
	~GradeBook();
	
	void addExam(Exam exam);
	void addExam(std::istream& in);
	void popExam(std::istream& in);
	Exam& getExam(size_t key);
	Exam& getExam(std::istream& in);
	void changeElement(std::istream& in);
	size_t getSize();

	Exam first_exam();
	Exam last_exam();
	
	friend std::ostream& operator <<(std::ostream& out, GradeBook& s);
private:
	MyVector<Exam> m_exams;
};