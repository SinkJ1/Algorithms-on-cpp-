/*
	Дан шаблон 7-значного числа, в котором одна цифра заменена символом X.
	Определить, при каком значении X, число кратно 11.
*/

#include <iostream>
#include <string>

#define DIGIT_CHAR_TO_INT(i) '0' + i

int checkPattern(const char* pattern, char goal, size_t size)
{
	const char* stream = pattern;
	int position;

	for (position = 0; pattern[position] != goal && position < size; ++position);

	if (position >= size) return -1;

	for (int i = 0; i < 10; ++i)
	{
		char* newStr = _strdup(pattern);
		newStr[position] = DIGIT_CHAR_TO_INT(i);

		int intNumber = std::stoi(newStr);

		if (intNumber % 11 == 0)
			return i;
	}

	return -1;
}

void TestCase(const char* pattern, char goal)
{
	printf("For [%s], result: [%d]\n", pattern, checkPattern(pattern, goal, strlen(pattern)));
}

int main()
{
	TestCase("X1", 'X');
	TestCase("X3", 'X');
	TestCase("1X1", 'X');
	TestCase("2X0", 'X');
	TestCase("22X", 'X');
	TestCase("1287X61", 'X');
	TestCase("12X7061", 'X');
	TestCase("128X642", 'X');
	TestCase("1287X11", 'X');
	return 0;
}