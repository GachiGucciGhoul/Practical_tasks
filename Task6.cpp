﻿#include <iostream>
#include <math.h>
int main()
{
	double a, b, c, x;
	setlocale(LC_ALL, "Rus");
	std::cin >> a >> b >> c;
	if ((a == 0) && (b == 0))
	{
		std::cout << "Уравнение введено неверно\n";
		return 1;
	}
	if (a == 0)
	{
		std::cout << "x= " << -c / b;
	}
	else
	{

		c = sqrt(b * b - 4 * a * c);
		if (c >= 0)
		{
			x = ((-b + c) / 2 * a);
			a = ((-b - c) / 2 * a);
			(x > a) ? (std::cout << "X1 = " << x << "\n", std::cout << "X2 = " << a) : (x = a) ? (std::cout << "X = " << x) : (std::cout << "X1 = " << a << "\n", std::cout << "X2 = " << x);
		}
		else
			std::cout << "нет вещественных решений";
	}
	std::cout << "\n";
}   
    

