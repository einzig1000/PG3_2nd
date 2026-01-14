#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <algorithm>

/// <param name="fn">呼び出したい関数へのポインタ</param>
/// <param name="delayMs">待機時間(ミリ秒)</param>
/// <param name="roll">サイコロの出目</param>
/// <param name="userGuess">ユーザーの入力</param>
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess)
{
	clock_t start = clock();
	while ((clock() - start) < delayMs)
	{
	}

	fn(roll, userGuess);
}

int main()
{
	srand((unsigned int)time(NULL));
	int dice = (rand() % 6) + 1;
	char command;

	printf("02-04\n\n");
	printf("丁：０　半：１\n");

	scanf_s("%c", &command, 1);

	auto showResult = [](int roll, int userGuess)
		{
			printf("\nサイコロの目は %d でした。\n", roll);
			if (roll % 2 == userGuess)
			{
				printf("当たり！\n");
			}
			else
			{
				printf("はずれ！\n");
			}
		};

	DelayReveal(showResult, 3000, dice, command - '0');

	return 0;
}
