/*
	Имеются контейнеры двух видов: по 130кг и 160кг. 
	Можно ли полностью загрузить ими грузовик грузоподъёмностью А т.
*/
#include <iostream>
#include <conio.h>

#define INT_TO_STBOOL(x) ((x) ? "True" : "False")

bool sollutionExists(int a, int b, int t)
{
    bool result = false;
    for (int i = 0; i <= t / a; i++)
    {
        for (int j = 0; j <= t / b; j++)
        {
            if (i * a + j * b == t)
            {
                result = true;
            }
        }
    }

    return result;
}

void TestCase(int a, int b, int t, int expected)
{
    printf("A:[%d], B:[%d], T:[%d], Expected:[%s], Result:[%s]\n",
        a, b, t, INT_TO_STBOOL(expected), INT_TO_STBOOL(sollutionExists(a, b, t)));
}

int main()
{
    TestCase(130, 160, 160, true);
    TestCase(130, 160, 130, true);
    TestCase(130, 160, 290, true);

    TestCase(130, 160, 280, false);
    TestCase(130, 160, 270, false);

    return 0;
}
