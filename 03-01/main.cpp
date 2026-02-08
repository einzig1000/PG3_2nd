#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <algorithm>
#include "Enemy.h"

int main()
{
	srand((unsigned int)time(NULL));
	bool loop = true;

	printf("03-01\n\n");

	Enemy* enemy = new Enemy();

	for (int i = 0; i < 10; ++i)
	{
		enemy->Update();
	}


	return 0;
}
