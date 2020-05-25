#include <iostream>

/*
	2. Найти сумму первого и последнего простых чисел на [a,b].
*/

bool isSimple(int val)
{
	if (val < 2 || ( val != 2 && val % 2 == 0)) return false;

	for (int i = 2; i < val / 2; ++i)
	{
		if (val % i == 0) return false;
	}

	return true;
}

int getFirstSimpleByDir(int start, int end, int dir)
{
	if (start == 1)
		start++;

	if (isSimple(start)) return start;

	for (int i = start;
		start < end ? i < end : i > end;
		i += dir) 
	{
		if (isSimple(i)) 
			return i;
	}

	return 0;
}

int sumOfFirstAndLastSimple(int a, int b)
{
	int first = getFirstSimpleByDir(a, b, 1);
	int second = getFirstSimpleByDir(b, a, -1);
	return first + second;
}

void TestIsSimple(int val)
{
	printf("val: %d, result: %d: \n", val, isSimple(val));
}

void TestSumOfSimple(int a, int b)
{
	printf("a:[%d], b:[%d], result:[%d]\n", a, b, sumOfFirstAndLastSimple(a, b));
}

int main()
{
	TestSumOfSimple(1, 10);
	TestSumOfSimple(1, 15);
	TestSumOfSimple(1, 20);

	return (0);
}