#include "Hori.h"
#include "Miyazi.h"

int main()
{
	Student* student1 = new Hori();
	Student* student2 = new Miyazi();
	student1->print();
	student2->print();
	delete student1;
	delete student2;
	return 0;
}