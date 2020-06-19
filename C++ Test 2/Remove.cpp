#include <iostream>
#include <string.h>
#include "Remove.h"
#include "Players.h"

Remove::Remove()
{
	name = "Remove a users score";
}

Remove::Remove(int cmd)
{
	name = "Remove a users score";

	command = cmd;
}

Remove::~Remove()
{
}

void Remove::Run(Table* scoreboard)
{
	int pos;

	std::cout << "// Removing a score //" << std::endl;

	std::cout << "Choose a score to remove 1 - " << scoreboard->length << ": ";
	std::cin >> pos;

	if (!std::cin)
	{
		std::cout << "Failed inputting an integer selection! (You have to restart the command now)" << std::endl;

		return;
	}
	else if (pos > scoreboard->length)
	{
		std::cout << "Invalid item number to remove! (You have to restart the command now)" << std::endl;

		return;
	}

	std::cout << "You just removed this from the scoreboard:" << std::endl << "- Name: " << scoreboard->Get(pos).name << std::endl << "- Score: " << scoreboard->Get(pos).score << std::endl;

	scoreboard->Remove(pos);
}
