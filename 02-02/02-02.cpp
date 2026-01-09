#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <algorithm>

char command;
int loop = 0;

template <typename T>
constexpr const T& my_min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

int salary1(int hour)
{
	if (hour <= 0) return 0;
	return 1226 * hour;
}

int salary2(int hour)
{
	if (hour <= 0) return 0;
	if (hour == 1) return 100;
	return salary2(hour - 1) * 2 - 50;
}

int salary2Sum(int hour)
{
	if (hour <= 0) return 0;
	int salary = 0;
	for (int i = 0; i <= hour; ++i)
	{
		salary += salary2(i);
	}
	return salary;
}



int main()
{
	int hour = 5;
	printf("02-02\n\n");

	printf("hour:5");
	printf("\nStandard salary: %d  Recursive salary: %d\n\n", salary1(hour), salary2Sum(hour));

	while (1)
	{
		printf("hour:");
		command = _getch();

		hour = command - '0';
		printf("\nStandard salary: %d  Recursive salary: %d\n\n", salary1(hour), salary2Sum(hour));
	}

	return 0;
}
