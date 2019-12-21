#include <iostream>

double BMI(double weight, double height)
{
	return weight / height / height;
}

void printBMI(double BMI)
{
	if (BMI < 18.5) std::cout << "Underweight";
	
	else if ((18.5 <= BMI) &&  (BMI< 25.0)) std::cout << "Normal weight";
	
	else if ((25.0 <= BMI) && (BMI < 30.0)) std::cout << "Overweight";
	
	else if (30.0 <= BMI) std::cout << "Obesity";
}

int main()
{
	setlocale(LC_ALL, "");
	double wight, height;
	std::cout << "Введите вес в кг и рост в метрах: ";
	std::cin >> wight >> height;
	height /= 100;
	printBMI(BMI(wight, height));
}
