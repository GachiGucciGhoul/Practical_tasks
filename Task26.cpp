#include <iostream>

struct IntArray
{
	int* data;
	int size;
};

void create( IntArray* arr, int size)
{
	arr->data = new int[size] {};
}

int get(IntArray* arr, int index)
{
	if (index >= arr->size)
	{
		std::cout << "ERR: index>=size";
	}
	else
	{
		return arr->data[index];
	}
}

void set(IntArray* arr, int index, int value)
{
	if (index >= arr->size)
	{
		std::cout << "ERR: index>=size";
	}
	else
	{
		arr->data[index] = value;
	}
}

void print(IntArray* arr)
{
	for (int i = 0; i < arr->size; i++)
	{
		std::cout << get(arr, i)<<" ";
	}
}

void resize(IntArray* arr, int newSize)
{
	int oldSize = arr->size;
	arr->size = newSize;
	if (oldSize < newSize)
	{
		for (int i = oldSize; i < newSize; i++) arr->data[i] = 0;
	}
}

void free(IntArray* arr)
{
	delete[] arr;
}

int main()
{
	int newSize, n = 1;
	IntArray arr;
	std::cout << "size = ";
	std::cin >> arr.size;
	create(&arr, arr.size);

	for (int i = 0; i < arr.size; i++)
	{
		set(&arr, i, n);
		n++;
		//std::cout << get(&arr, i)<<" ";
	}

	print(&arr);

	std::cout << "\nnew size = ";
	std::cin >> newSize;
	resize(&arr, newSize);
	print(&arr);

	std::cout << "\nnew size = ";
	std::cin >> newSize;
	resize(&arr, newSize);
	free(&arr);
}