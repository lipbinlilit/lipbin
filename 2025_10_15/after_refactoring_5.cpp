#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	int day, month, full_year;
	std::cout << "введите дату дня" << std::endl;
	std::cin >> day;
	std::cout << "введите число месяца" << std::endl;
	std::cin >> month;
	std::cout << "введите год" << std::endl;
	std::cin >> full_year;

	int year = full_year % 100;
	int centure = full_year / 100;
	int number_day_of_the_week = (
		day
		+ (13 * month - 1) / 5
		+ year / 4
		+ centure / 4
		- 2 * centure
		+ 777
		) % 7;
	
	switch (number_day_of_the_week) {
		case 0:
			std::cout << "воскресенье" << std::endl;
			break;
		case 1:
			std::cout << "понедельник" << std::endl;
			break;
		case 2:
			std::cout << "вторник" << std::endl;
			break;
		case 3:
			std::cout << "среда" << std::endl;
			break;
		case 4:
			std::cout << "четверг" << std::endl;
			break;
		case 5:
			std::cout << "пятница" << std::endl;
			break;
		case 6:
			std::cout << "суббота" << std::endl;
			break;
	}
	
	system("pause");
	return 0;
}
