#include <iostream>
#include <ctime>

int main()
{ 
	
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int b,c,i,a;
	c = 1;
    

	while (c == 1)
	{
		i = 0;
		a = rand() % 101;
		std::cout << a;
		std::cout << "Игра угадай число:\n";
		while (i < 5)
		{
			std::cin >> b;
			if (b > a)
			{
				std::cout << "Загаданное число меньше " << b << "\n";

			}
			else if (b < a)
			{
				std::cout << "Загаданное число больше " << b << "\n";
			}
			else if (b = a)
			{
				std::cout << "Поздравляю! Вы угадали!\n";
				break;
			}
			i++;

		
		}
		if (i == 5)
		{
			std::cout << "Вы проиграли. Было загадано: " << a;
		}
		std::cout << "\nХотите начать сначала? (1-ДА)\n";
		std::cin >> c;

	}
	


 
}