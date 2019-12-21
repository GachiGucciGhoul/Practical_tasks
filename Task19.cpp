#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int* arr = new int[n];
	int num[10]{0};

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		num[arr[i]]++;		
	}
	

	for (int i = 0; i < 10; i++)
	{
		if (num[i] != 0) std::cout << i << ": " << num[i] << "\n";
	}

	delete[] arr;
}

