#include <iostream>
#include <ctime>

int main()
{
	const int SIZE = 20;
	srand(time(0));
	int arr[SIZE], min=101, max=-101;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i]= (rand() % 201) - 100;

		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];

		std::cout << arr[i] << " ";
	}
	std::cout << "\nmin "<<min<<" max="<<max<<"\n";
}