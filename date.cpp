#include "date.h"
#include <stdexcept>

void Date::setDate(int day, int month, int year) {
	setDay(day);
	setMonth(month);
	setYear(year);
}



Date::Date(int d, int m, int y)
{
	setDate(d, m, y);
}

Date::Date(const Date& date)
{
	setDate(date.m_day, date.m_month, date.m_year);
}

Date::~Date()
{
	m_day = 1;
	m_month = 1;
	m_year = 1;
}

void Date::setDay(int day)
{
	if ((day > 31) || (day < 1))
	{
		throw std::invalid_argument("Некоректний ввід!");
	}
	this->m_day = day;
}

void Date::setMonth(int month)
{
	if ((month > 12) || (month < 1))
	{
		throw std::invalid_argument("Некоректний ввід!");
	}
	this->m_month = month;
}

void Date::setYear(int year) {
	this->m_year = year;
}


void Date::setDay(std::istream& in)
{
	int day;
	std::cout << "Введіть день: "; in >> day;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "Некоректний ввід!" << std::endl;
		setDay(in);
		return;
	}
	try
	{
		setDay(day);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		setDay(in);
	}
}

void Date::setMonth(std::istream& in)
{
	int month;
	std::cout << "Введіть місяць: "; in >> month;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "Некоректний ввід!" << std::endl;
		setMonth(in);
		return;
	}
	try
	{
		setMonth(month);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		setMonth(in);
	}

}

void Date::setYear(std::istream& in)
{
	int year;
	std::cout << "Введіть рік: "; in >> year;
	if (in.fail())
	{
		in.clear();
		in.ignore(32767, '\n');
		std::cout << "Некоректний ввід!" << std::endl;
		setYear(in);
		return;
	}
	setYear(year);
}

std::istream& operator>>(std::istream& in, Date& date) {
	date.setDay(in);
	date.setMonth(in);
	date.setYear(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
	out << date.getDay() << '.'
		<< date.getMonth() << '.'
		<< date.getYear();
	return out;
}

bool operator==(const Date& date1, const Date& date2) {
	return date1.getDay() == date2.getDay() && date1.getMonth() == date2.getMonth() && date1.getYear() == date2.getYear();
}

bool operator>(const Date& date1, const Date& date2) {
	if (date1.getYear() > date2.getYear())
		return true;
	else if (date1.getYear() == date2.getYear()) {
		if (date1.getMonth() > date2.getMonth())
			return true;
		else if (date1.getMonth() == date2.getMonth()) {
			if (date1.getDay() > date2.getDay())
				return true;
		}
	}
	return false;

}

bool operator<(const Date& date1, const Date& date2)
{
	if (date1.getYear() < date2.getYear())
		return true;
	else if (date1.getYear() == date2.getYear()) {
		if (date1.getMonth() < date2.getMonth())
			return true;
		else if (date1.getMonth() == date2.getMonth()) {
			if (date1.getDay() < date2.getDay())
				return true;
		}
	}
	return false;
}
