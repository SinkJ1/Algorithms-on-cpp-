#if 0

	Окружность с центром в точке(x, y) проходит через точку(x1, y1).
	Определите, принадлежит ли точка(x2, y2) данной окружности.

#endif

#include <iostream>
#include <math.h>
#include <ostream>

struct v2
{
	float x, y;
	
	float len() 
	{
		return sqrt(x * x + y * y);
	}
};

v2 operator -(const v2& left, const v2& right)
{
	v2 result = { };
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	return result;
}

std::ostream& operator << (std::ostream& stream, const v2& v) 
{
	return stream << "[" << v.x << ", " << v.y << "]";
}

float getRadius(const v2& o, const v2& x)
{
	return (o - x).len();
}

bool isPointInCircle(const v2& o, float r, const v2& point)
{
	float lenFromOToPoint = (o - point).len();
	return r > lenFromOToPoint;
}

void TestCase(const v2& o, const v2& v1, const v2& v2, bool expected)
{
	std::cout << "Test case\n";

	std::cout << "\tFor o: " << o << std::endl;
	std::cout << "\tFor v1: " << v1 << std::endl;
	std::cout << "\tFor v2: " << v2 << std::endl;
	std::cout << "\tExpected: " << (expected ? "True" : "False") << std::endl;

	float r = getRadius(o, v1);
	
	if (isPointInCircle(o, r, v2))
	{
		std::cout << "The point in circle." << std::endl;
	}
	else 
	{
		std::cout << "The point doesn't in circle." << std::endl;
	}
	std::cout << "End\n";
}

int main(void) 
{
	TestCase({ 5.0f, 5.0f }, { 6.0f, 5.0f }, { 5.5f, 5.5f }, true);
	TestCase({ 5.0f, 5.0f }, { 6.0f, 5.0f }, { 4.5f, 4.5f }, true);

	TestCase({ 5.0f, 5.0f }, { 6.0f, 6.0f }, { 2.5f, 2.5f }, false);
	TestCase({ 5.0f, 5.0f }, { 6.0f, 6.0f }, { 7.5f, 7.5f }, false);

	TestCase({ 5.0f, 5.0f }, { 5.0f, 6.0f }, { 5.5f, 5.5f }, true);
	TestCase({ 5.0f, 5.0f }, { 5.0f, 6.0f }, { 4.5f, 4.5f }, true);

	return 0;
}
