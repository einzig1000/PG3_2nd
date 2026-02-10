#include "Circle.h"
#include <iostream>

void Circle::Size()
{
	size_ = radius_ * radius_ * 3.14159f;
}

void Circle::Draw()
{
	std::cout << "Circle size: " << size_ << std::endl;
}
