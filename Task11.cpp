#include <iostream>

int main()
{
	int Factorial, factor, a;
	Factorial = 1;
	factor = 0;
	std::cin >> a;

	if (a == 0)
	{
		std::cout << 1;
		return 0;
	}

	do
	{
		factor++;
		Factorial *= factor;
		
	} while (factor != a);
	std::cout << Factorial << "\n";
}