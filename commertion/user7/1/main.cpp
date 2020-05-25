/*
	Билет с шестизначным номером является “счастливым”, если сумма трех
	первых цифр равна сумме трех его последних цифр.

	Составьте алгоритм для определения по номеру билета “счастливый” он или нет.
*/

#include <iostream>
#include <string>

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

/*
	Why not just take the base-10 log of the absolute value of the number, 
	round it down, and add one? This works for positive and negative numbers 
	that aren't 0, and avoids having to use any string conversion functions.
*/
bool IsLucky(int value, int rule)
{
	if (value < 10 || -10 > value) return false;

	int nDigits = floor(log10(value)) + 1;
	if (nDigits % 2 != 0) return false;

	int delimeter = pow(10, nDigits/2);

	int sumFirstPart = sumOfLast(value, rule);
	int sumSecondPart = sumOfLast(value / delimeter, rule);

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
	IsLuckyTestCase(666666, 3);
	IsLuckyTestCase(123321, 3);
	IsLuckyTestCase(550055, 3);
	IsLuckyTestCase(111000, 3);
	IsLuckyTestCase(100111, 3);

	return 0;
}