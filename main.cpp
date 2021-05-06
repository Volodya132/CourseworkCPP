#include <Windows.h>
#include <iostream>
#include <fstream>
#include "gradebook.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "=====================================================" << std::endl;
	std::cout << " Курсова робота ст.гр. КН-21 Ольшанського Володимира " << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << std::endl;
	std::cout << "********   ЗАЛІКОВА КНИЖКА   ********" << std::endl;
	std::cout << std::endl;

	GradeBook *gradebook = new GradeBook();
	int answer = 0;
	do
	{
		std::cout << "1. Вивести дані про результати складання екзаменів. " << std::endl;
		std::cout << "2. Добавити екзамен. " << std::endl;
		std::cout << "3. Видалити екзамен. " << std::endl;
		std::cout << "4. Змінити дані екзамена. " << std::endl;
		std::cout << "5. Перший екзамен. " << std::endl;
		std::cout << "6. Останній екзамен. " << std::endl;
		std::cout << "0. Вихід. " << std::endl;
		std::cin >> answer;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Некоректний ввід! Очікується число! " << std::endl;
			answer = -1;
		}
		switch (answer)
		{
		case 1: std::cout << *gradebook << std::endl; break;
		case 2: gradebook->addExam(std::cin); break;
		case 3: if (gradebook->getSize() > 0)
					gradebook->popExam(std::cin);
				else
					std::cout << "Пустий масив!" << std::endl;
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