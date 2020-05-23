/*
	Билет с шестизначным номером является “счастливым”, если сумма трех
	первых цифр равна сумме трех его последних цифр.

	Составьте алгоритм для определения по номеру билета “счастливый” он или нет.
*/

#include <iostream>

int sumOfLast(int value, int n) 
{
	int result = 0;

	for (int i = 0; i < n; ++i) 
	{
		int l = value % 10;
		result += l;
		value /= 10;
	}

	return result;
}

bool IsLucky(int value, int rule)
{
	int sumFirstPart = sumOfLast(value, rule);
	int sumSecondPart = sumOfLast(value / 1000, rule);

	return (sumFirstPart == sumSecondPart);
}

void IsLuckyTestCase(int value, int rule)
{
	std::cout << value << " : ";
	
	if (IsLucky(value, rule))
	{
		std::cout << "Is lucky number\n";
	}
	else
	{
		std::cout << "Is not lucky number\n";
	}
}

int main(void) 
{
	int value;
	value = 666666;

	IsLuckyTestCase(666666, 3);
	IsLuckyTestCase(123321, 3);
	IsLuckyTestCase(550055, 3);
	IsLuckyTestCase(111000, 3);
	IsLuckyTestCase(100111, 3);

	return 0;
}