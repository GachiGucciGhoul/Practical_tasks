#include <iostream>

int main()
{
	double a,b;
	int c,i,z;
	std::cin >> a >> c;

	z = c;
	c = abs(c);
	b = 1;



	for (i = 0; i < c; i++)
	{
		b = b * a;
	}

	if (z < 0)
	{
		if (a == 0)
		{
			std::cout << "err";
			return 1;
		}
		std::cout << 1/b;
		return 0;
	}

	std::cout << b;
}

