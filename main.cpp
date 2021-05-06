#include <Windows.h>
#include <iostream>
#include <fstream>
#include "gradebook.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "=====================================================" << std::endl;
	std::cout << " ������� ������ ��.��. ��-21 ������������ ���������� " << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << std::endl;
	std::cout << "********   ��˲���� ������   ********" << std::endl;
	std::cout << std::endl;

	GradeBook *gradebook = new GradeBook();
	int answer = 0;
	do
	{
		std::cout << "1. ������� ��� ��� ���������� ��������� ��������. " << std::endl;
		std::cout << "2. �������� �������. " << std::endl;
		std::cout << "3. �������� �������. " << std::endl;
		std::cout << "4. ������ ��� ��������. " << std::endl;
		std::cout << "5. ������ �������. " << std::endl;
		std::cout << "6. ������� �������. " << std::endl;
		std::cout << "0. �����. " << std::endl;
		std::cin >> answer;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "����������� ���! ��������� �����! " << std::endl;
			answer = -1;
		}
		switch (answer)
		{
		case 1: std::cout << *gradebook << std::endl; break;
		case 2: gradebook->addExam(std::cin); break;
		case 3: if (gradebook->getSize() > 0)
					gradebook->popExam(std::cin);
				else
					std::cout << "������ �����!" << std::endl;
			break;
		case 4: gradebook->changeElement(std::cin); break;
		case 5: std::cout <<  gradebook->first_exam() << std::endl; break;
		case 6: std::cout << gradebook->last_exam() << std::endl; break;
		default:
			break;
		}
	} while (answer != 0);

	delete gradebook;
	
	return 0;
}