#include <iostream>
#include <math.h>


int main()
{

	setlocale(LC_ALL, "Rus");
	short tipe;
	double a, b, c, Ax, Ay,Bx, By, Cx, Cy, Sp;
	std::cout << "Для указания длинн сторон введите \"1\"\nДля указания координат вершин введите \"2\"\n";
	std::cin >> tipe;

	switch (tipe)
	{
	case (1):
	 {
		std::cin >> a >> b >> c;

		if ((a + b <= c) || (a + c <= b) || (b + c <= a))
		{
			std::cout << "Треугольника с введенными параметрами не существует.";
			return 0;
		}

		Sp = (a + b + c) / 2;
		Sp = sqrt(Sp * (Sp - a) * (Sp - b) * (Sp - c));
		std::cout << "S = " << Sp << "\n";
		break;
	 }

	case (2):
	 {
		std::cout << "Введите координаты точки A:";
		std::cin >> Ax >> Ay;
		std::cout << "Введите координаты точки B:";
		std::cin >> Bx >> By;
		std::cout << "Введите координаты точки C:";
		std::cin >> Cx >> Cy;

		a = sqrt((Cx - Bx) * (Cx - Bx) + (Cy - By) * (Cy - By));
		b = sqrt((Cx - Ax) * (Cx - Ax) + (Cy - Ay) * (Cy - Ay));
		c = sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));

		if ((a + b <= c) || (a + c <= b) || (b + c <= a))
		{
			std::cout << "Треугольника с введенными параметрами не существует.";
			return 0;
		}

		Sp = (a + b + c) / 2;
		Sp = sqrt(Sp * (Sp - a) * (Sp - b) * (Sp - c));
		std::cout << "S = " << Sp << "\n";

		break;
	 }

	default:
		std::cout << "Неверно указан способ ввода параметров треугольника\n";
		break;
	}

}
