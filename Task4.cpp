#include <iostream>

int main()
{
	double a, b, c;
	std::cin >> a >> b;
	c = a;
	a = b;
	b = c;
	std::cout << a << "\t" << b << "\n";
	b = b + a;
	a = b - a;
	b = b - a;
	std::cout << a << "\t" << b << "\n";
}