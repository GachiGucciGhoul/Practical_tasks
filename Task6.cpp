#include <iostream>
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

	if ((b == 0) && (c == 0)||((a==0)&&(c==0)))
	{
		std::cout << "X=0\n";
		return 0;
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
			x = ((-b + c) / (2 * a));
			a = ((-b - c) / (2 * a));
			
			if (x==a)
			{
				std::cout << "X = " << x;
			}
			else
			{
				std::cout << "X1 = " << x << "\n";
				std::cout << "X1 = " << a << "\n";
			}

		}
		else
			std::cout << "нет вещественных решений";
	}
	std::cout << "\n";
	cout << 228;
}   
    

