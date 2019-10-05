#include <iostream>

int main()
{
	double x0, u0, t, a;
	a = -9.8;
	std::cin >> x0 >> u0 >> t;
	std::cout << x0 + u0 * t + a * t * t/2 ;
}