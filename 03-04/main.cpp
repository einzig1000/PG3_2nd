#include "Circle.h"
#include "Triangle.h"

int main()
{
	Circle circle;
	circle.SetRadius(5.0f);
	circle.Size();
	circle.Draw();
	Triangle triangle;
	triangle.SetBase(4.0f);
	triangle.SetHeight(3.0f);
	triangle.Size();
	triangle.Draw();

	return 0;
}
