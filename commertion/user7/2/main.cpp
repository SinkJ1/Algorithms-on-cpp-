/*
	Имеются контейнеры двух видов: по 130кг и 160кг. 
	Можно ли полностью загрузить ими грузовик грузоподъёмностью А т.
*/

#include <iostream>

bool canBeLoad(int containerA, int containerB, int weight)
{
	if (weight % containerA == 0) return true;
	if (weight % containerB == 0) return true;



}

int main()
{
	return (0);
}
