#include "Compare.h"
#include <iostream>

int main()
{
	Compare<int, double> comp1(10, 20.5);
	std::cout << "Compare<int, double>(10, 20.5)        : Min = " << comp1.Min() << ", Max = " << comp1.Max() << std::endl;

	Compare<int, float> comp2(15, 12.3f);
	std::cout << "Compare<int, float>(15, 12.3f)        : Min = " << comp2.Min() << ", Max = " << comp2.Max() << std::endl;

	Compare<float, double> comp3(5.5f, 7.7);
	std::cout << "Compare<float, double>(5.5f, 7.7)     : Min = " << comp3.Min() << ", Max = " << comp3.Max() << std::endl;

	Compare<int, int> comp4(15, 12);
	std::cout << "Compare<int, int>(15, 12)             : Min = " << comp4.Min() << ", Max = " << comp4.Max() << std::endl;

	Compare<float, float> comp5(13.0f, 8.0f);
	std::cout << "Compare<float, float>(13.0f, 8.0f)    : Min = " << comp5.Min() << ", Max = " << comp5.Max() << std::endl;

	Compare<double, double> comp6(11.0, 7.0);
	std::cout << "Compare<float, float>(11.0, 7.0)	    : Min = " << comp6.Min() << ", Max = " << comp6.Max() << std::endl;


	return 0;
}