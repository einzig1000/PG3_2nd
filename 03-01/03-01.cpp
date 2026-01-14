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

	while (loop)
	{
		enemy->Update();

		// なんでもいいからキーを押すと次の状態へ
		_getch();
	}


	return 0;
}
