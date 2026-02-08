#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
using namespace std;

template <typename T>
constexpr const T& my_min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}


int main()
{
	printf("02-01\n\n");

	int a = 10;
	int b = 20;
	int c = my_min(a, b);
	printf("min(%d, %d) = %d\n", a, b, c);

	float x = 1.5f;
	float y = 2.5f;
	float z = my_min(x, y);
	printf("min(%.2f, %.2f) = %.2f\n", x, y, z);

	double p = 3.14f;
	double q = 2.71f;
	double r = my_min(p, q);
	printf("min(%.2f, %.2f) = %.2f\n", p, q, r);


	return 0;
}
