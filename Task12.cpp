#include <iostream>

int main()
{
	setlocale(LC_ALL,"RUS");
	int a, i;
	std::cin >> a;

	if(a>0)
	{ 

		if (a == 1)
		{
			std::cout << "не простое и не составное";
			return 0;
		}

	
		for (i = 2; i < a; i++)
		{
			if (a % i == 0)
			{
				std::cout << "составное";
				return 0;
			}
		}
		std::cout << "простое";

	}
	else
	{
		std::cout << "Введено не положительное число";
	}
}