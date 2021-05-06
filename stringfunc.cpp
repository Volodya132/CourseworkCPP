#include "stringfunc.h"

#include <locale>

bool isUA(std::string str)
{
	//std::locale cp1251_locale("uk_UA");
	std::string ua("��������賿�����������������������å�����Ȳ���������������������");
	for (char ch : str)
	{
		if (ua.find(ch) == std::string::npos)
			return false;
	}
	return true;
}

bool isENG(std::string str)
{
	std::string eng("abcdefghijklmnopqrstuvwxyz ");
	for (char ch : str)
	{
		if (eng.find(std::tolower(ch)) == std::string::npos)
			return false;
	}
	return true;
}

bool isENGandUA(std::string str)
{
	std::string ua("��������賿�����������������������å�����Ȳ��������������������� ");
	std::string eng("abcdefghijklmnopqrstuvwxyz ");
	for (char ch : str)
	{
		if ((eng.find(std::tolower(ch)) != std::string::npos) && (ua.find(ch) != std::string::npos))
			return false;
	}
	return true;
}