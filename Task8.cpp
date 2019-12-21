#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b;
	char x;
	std::cout << "a (+,-,/,*) b\n";
	std::cin >> a >> x >> b;
	std::cout << "=";
	switch (x)
  {
	case('+'):
	{
		std::cout << a + b;
		break;
	}
	case('-'):
	{
		std::cout << a - b;
		break;
	}
	case('*'):
	{
		std::cout << a * b;
		break;
	}
	case('/'):
	{
		std::cout << a / b;
		break;
	}
	default:
	{
		std::cout << "\bНеверный знак операции\n";
		break;
	}
  }

}
