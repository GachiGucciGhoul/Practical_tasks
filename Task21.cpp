#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	const int size1 = 10, size2 = 8;
	int arr[size1][size2]{ {} };
	int i, j, k=0, iTry, jTry;
	i = rand() % 10;		
	j = rand() % 8;
	arr[i][j] = 6;

	while (k!=5)
	{
		std::cout << "Введите координаты: ";
		std::cin >> iTry >> jTry;

		if ((iTry > size1-1) || (jTry > size2-1) || (iTry < 0) || (jTry < 0))
		{
			std::cout << "Выход за границу массива\n";
			continue;
		}

		if (arr[iTry][jTry] == 1)
		{
			std::cout << "Эту уже проверяли\n";
			continue;
		}

		if (arr[iTry][jTry] == 0)
		{
			arr[iTry][jTry] = 1;
			k++;
			std::cout << "Нет\n";
		}

		if (arr[iTry][jTry] == 6)
		{
			std::cout << "Вы угадали\n";
			return 0;
		}

	}

	std::cout << "GAME OVER\n"<<i<<"\t"<<j;
	
}
