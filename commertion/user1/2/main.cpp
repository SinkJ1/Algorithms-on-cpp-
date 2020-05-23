/*
	Сколько слагаемых должно быть в сумме 1+1/2+1/3+1/4+...+1/n, 
	чтобы эта сумма оказалась больше введенного числа К ?
*/

#include <iostream>

int foo(double k)
{
	double sum = 1;

	int i = 1;
	while(sum < k)
	{
		i++;
		sum += 1.0 / i;
	}
	return i;
}

void TestCase(double k)
{
	std::cout << "For k=" << k << "\n";
	std::cout << "Result: " << foo(k) << "\n";
}

int main() 
{
	TestCase(1);
	TestCase(1.51);
	TestCase(2);
	TestCase(4);
	TestCase(10);

	return (0);
}
