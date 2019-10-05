#include <iostream>

int main()
{
	int Factorial, factor, a;
	Factorial = 1;
	factor = 0;
	std::cin >> a;

	do
	{
		factor++;
		Factorial = Factorial * factor;
		
	} while (factor != a);
	std::cout << Factorial << "\n";
}