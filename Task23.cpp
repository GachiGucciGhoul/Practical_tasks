#include <iostream>

int CharToInt(char R)
{
	int r = (int)R;
	if ((r >= 65) && (r <= 90))
		r += 32;
	if (((r >= 97) && (r <= 122)) || ((r >= 48) && (r <= 57)))
		return r;
	else return 1;
}

bool is_it_a_palindrome(char* str, int size2)
{
	int l, r, a, b;
	l = 0;
	r = size2 - 1;

	while (l < r)
	{
		a = 1;
		b = 1;

		while (a == 1)
		{
			a = CharToInt(str[l]);
			if (a == 1)
				l++;
		}

		while (b == 1)
		{
			b = CharToInt(str[r]);
			if (b == 1)
				r--;
		}
	
		if (a != b)
		{
			return false;
		}
		l++;
		r--;
	}

		return true;
}

int main()
{
	setlocale(LC_ALL, "rus");
	bool check = true;
	const short SIZE = 21;
	char str[SIZE];

	std::cin.getline(str, SIZE, '\n');
	
	if (is_it_a_palindrome(str, strlen(str)))
		std::cout << "Палиндром\n";
	else 
		std::cout << "Не палиндром\n";
}