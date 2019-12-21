#include <iostream>

void sort(double* arr, int size)
{
	double k = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
		}
	}
}

int main()
{
	int size, k = -1;
	std::cin >> size;

	double* signals = new double[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> signals[i];
	}

	std::cout << "\n";


	for (int i = 1; i <= size; i++)
	{
		sort(signals, i);

		if (k < 4) k++;

		for (int j = k; j >= 0; j--)
		{
			std::cout << signals[j] << "\t";
		}
		std::cout << "\n";
	}
	delete[] signals;
}