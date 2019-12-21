#include <iostream>
#include <cmath>

bool test (int a)
{
	int i = 2;

	for (; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return true;
		}
	}
	return false;
}

void factorization (int a)
{
	int i, d;
	d = a;

	while (a != 1)
	{
		i = 0;
		if (test(d))
		{
			d--;
			continue;
		}

		if (a % d != 0)
		{
			d--;
			continue;
		}

		while (a >= d)
		{

			if (a % d != 0)
			{
				break;
			}

			i++;
			a /= d;
		}

		std::cout << d;

		if (i != 1)
		{
			std::cout << "^" << i;
		}
		if (a != 1)
		{
			std::cout << "*";
		}
		d--;
	}
	std::cout << "\n";
}


int main()
{
	int a;
	std::cin >> a;
	factorization (a);
}
