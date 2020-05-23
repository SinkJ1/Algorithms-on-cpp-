/*
    �������� �������.
    ���� ����������� ����� N � M. ����� ���������� �����.


    ��� �������� ���� ��������....
*/

#include <math.h>
#include <iostream>

int gcd(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }

    while (b) {
        a %= b;
        std::swap(a, b);
    }

    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;   //��������� ����� a * b / gcd(a, b),
                                //����� �������� ������������ �� ����� a * b,
                                //������� ������� ��������� ������� �� ���������
}

void TestCase(int n, int m)
{
    std::cout << "For N: " << n << " M: " << m << std::endl;

    std::cout << "\t" << "GCD: " << gcd(n, m) << std::endl;
    std::cout << "\t" << "LCM: " << lcm(n, m) << std::endl;
}

int main()
{
    TestCase(15, 20); // gcd: 5,
    TestCase(12, 30); // gcd: 6,

    return 0;
}
