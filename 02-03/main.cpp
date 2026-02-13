#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <windows.h>

template <typename T>
constexpr const T& my_min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

/// <param name="fn">呼び出したい関数へのポインタ</param>
/// <param name="delayMs">待機時間(ミリ秒)</param>
/// <param name="roll">サイコロの出目</param>
/// <param name="userGuess">ユーザーの入力</param>
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess)
{
	Sleep(delayMs);

	fn(roll, userGuess);
}

void ShowResult(int roll, int userGuess)
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
}

int main()
{
	srand((unsigned int)time(NULL));
	printf("02-03\n\n");

	int dice = (rand() % 6) + 1;

	printf("丁：０　半：１");

	char command;
	scanf_s("%c", &command, 1);

	DelayReveal(ShowResult, 3000, dice, command - '0');

	return 0;
}
