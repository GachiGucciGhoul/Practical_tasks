#include <iostream>
#include <vector>
#include <ctime>

//const int SIZE = 5;

enum Order
{
	ASC, 
	DESC 
};

int correct(int* arr, int size)
{
	for (int i = 0; i < size-1 ; i++)
	{
		if (arr[i] > arr[i+1])
			return 0;
	}
	return 1;
}

int correct(std::vector<int> vec, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (vec[i] > vec[i + 1])
			return 0;
	}
	return 1;
}

int UNcorrect(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] < arr[i + 1])
			return 0;
	}
	return 1;
}

int UNcorrect(std::vector<int> vec, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (vec[i] < vec[i + 1])
			return 0;
	}
	return 1;
}

void BozoSort(int* arr, int size, Order C = ASC)  // Для массива
{
	int a, b;

	if (C == ASC)
		while (!correct(arr, size))
		{
			a = rand() % size;
			do
			{
				b = rand() % size;;
			} while (b==a);
			std::swap(arr[a], arr[b]);
		}
	else 
		while (!UNcorrect(arr, size))
		{
			a = rand() % size;
			do
			{
				b = rand() % size;;
			} while (b == a);
			std::swap(arr[a], arr[b]);
		}
	
} 

void swap(int* a, int* b) {
	*a += *b;

	*b = *a - *b;
	*a = *a - *b;
}

void BozoSort(int *a, int *b, int *c, Order C = ASC)
{
	int r;
	if (C == ASC)
		while ((*a>*b)||(*b>*c))
		{
			r = rand() % 3;
			switch (r)
			{
			case 0:
				swap(a, b);
				break;

			case 1:
				swap(c, b);
				break;
			case 2:
				swap(a, c);
				break;
			}
		}
	else
		while ((*a < * b) || (*b < * c))
		{
			r = rand() % 3;
			switch (r)
			{
			case 0:
				swap(a, b);
				break;

			case 1:
				swap(c, b);
				break;
			case 2:
				swap(a, c);
				break;
			}
		}

	
}

int main()
{	
	srand(time(NULL));
	int SIZE;
	int a, b, c;
	std::cin >> SIZE;
	int* arr = new int[SIZE];
	//int arr[SIZE];
	std::vector<int> vec(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		std::cin >> arr[i];
		vec[i] = arr[i];
	}
	a = arr[0];
	b = arr[1];
	c = arr[2];

	std::cout << "arry1: ";
	BozoSort(arr, SIZE);    // сортирую массив
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	
	std::cout << "arry2: ";
	BozoSort(arr, SIZE, DESC);  // массив в обратном порядке
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	std::cout << "vec1: ";
	BozoSort(&vec[0], SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";

	std::cout << "vec2: ";
    BozoSort(&vec[0], SIZE, DESC);
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";

	std::cout << "abc1: ";
	BozoSort(&a, &b, &c);  //три переменные 
	std::cout << a << " " << b << " " << c <<"\n";

	std::cout << "abc2: ";
	BozoSort(&a, &b, &c, DESC);  // три переменные в обратном порядке
	std::cout << a << " " << b << " " << c << " ";
}