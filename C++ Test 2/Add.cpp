#include <iostream>
#include <string.h>
#include "Add.h"
#include "Players.h"

Add::Add()
{
	name = "Add a users score";
}

Add::Add(int cmd)
{
	name = "Add a users score";
	
	command = cmd;
}

Add::~Add()
{
}

void Add::Run(Table* scoreboard)
{
	Players* data = new Players();

	std::cout << "// Adding a score //" << std::endl;

	std::cout << "Input a score: ";
	std::cin >> data->score;

	if (!std::cin) 
	{
		std::cout << "Failed inputting an integer score! (You have to restart the command now)" << std::endl;

		return;
	}

	std::cout << "Input a name: ";

	std::string strtmp;
	std::cin >> strtmp;
	
	if (!std::cin)
	{
		std::cout << "Failed inputting a name! (You have to restart the command now)" << std::endl;

		return;
	}

	if (strtmp.size() > 9)
	{
		std::cout << "Failed inputting a name, the name is too big! (Max 10 characters)" << std::endl;

		return;
	}

	strcpy_s(data->name, strtmp.c_str());

	std::cout << "You just added this to the scoreboard:" << std::endl << "- Name: " << data->name << std::endl << "- Score: " << data->score << std::endl;

	scoreboard->AddTo(*data);

	delete data;
}
