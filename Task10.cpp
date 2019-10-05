#include <iostream>

int main()
{
	double a,b;
	int c,i;
	std::cin >> a >> c;
	
	b = a;
	for (i = 0; i < c-1; i++)
	{
		b = b * a;
	}
	std::cout << b;
}

