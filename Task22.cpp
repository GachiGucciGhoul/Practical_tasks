#include <iostream>

void swap(int*, int*);
int msort(int*, int*, int*);
void info(const int*);
int* add(int*, const int*);

int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, c;
	std::cin >> a >> b >> c;
	info(&a);
	info(&b);
	info(&c);
	std::cout<<"Максимум: "<<msort(&a, &b, &c)<<"\n";
	info(add(add(&a, &b), &c));
}

void info(const int *p)
{
	std::cout << "Адрес:" << p << " Значение:" << *p << "\n";
}

void swap(int* swap1, int* swap2)
{
	*swap1 += *swap2;
	*swap2 = *swap1 - *swap2;
	*swap1 -= *swap2;
}

int msort(int* s1, int* s2, int* s3)
{
	if (*s1 > *s2) swap(s1, s2); 
	if (*s2 > *s3) swap(s2, s3); 
	if (*s1 > *s2) swap(s1, s2); 
	return *s3;
}

int* add(int* add1, const int* add2)
{
	*add1 += *add2;
	return add1;
}