
#include <iostream>

int main()
{
	int c=0;
	long long a, x=1;
	std::cin >> a;
	while (x<=a)
	{
		c++;
		x *= 2;
	}
	std::cout << c;
}
