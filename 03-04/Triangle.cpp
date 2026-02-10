#include "Triangle.h"
#include <iostream>

void Triangle::Size()
{
	size_ = 0.5f * base_ * height_;
}

void Triangle::Draw()
{
	std::cout << "Triangle size: " << size_ << std::endl;
}
