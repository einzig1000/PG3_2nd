#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <list>
using namespace std;

char command;
int loop = 0;

int main()
{
	printf("01-01\n\n");
	srand((unsigned int)time(NULL));

	std::list<const char*> list{
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		//"Nishi-Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		//"Takanawa-Gateway",
		"Tamachi",
		"Hamamatsucho",
		"Shinbashi",
		"Yurakucho",
	};

	std::cout << "1970\n\n";
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it;
		auto next = std::next(it);
		if (next != list.end())
		{
			std::cout << " - ";
		}
	}
	std::cout << "\n\n";


	for (std::list<const char*>::iterator itr = list.begin(); itr != list.end(); ++itr)
	{
		if (*itr == "Tabata")
		{
			itr = list.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}


	std::cout << "2019\n\n";
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it;
		auto next = std::next(it);
		if (next != list.end())
		{
			std::cout << " - ";
		}
	}
	std::cout << "\n\n";


	for (std::list<const char*>::iterator itr = list.begin(); itr != list.end(); ++itr)
	{
		if (*itr == "Tamachi")
		{
			itr = list.insert(itr, "Takanawa-Gateway");
			++itr;
		}
	}

	std::cout << "2022\n\n";
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it;
		auto next = std::next(it);
		if (next != list.end())
		{
			std::cout << " - ";
		}
	}
	std::cout << "\n\n";

	return 0;
}