#pragma once
#include <iostream>


class Date {
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int d = 1, int m = 1, int y = 1);
	Date(const Date& date);
	~Date();

	int getDay() const { return m_day; }
	int getMonth() const { return m_month; }
	int getYear() const { return m_year; }

	
	void setYear(std::istream& in);
	void setDay(std::istream& in);
	void setMonth(std::istream& in);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int day, int month, int year);

	
};

std::istream& operator>>(std::istream& in, Date& note);
std::ostream& operator<<(std::ostream& out, const Date& note);
bool operator==(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator<(const Date&, const Date&);