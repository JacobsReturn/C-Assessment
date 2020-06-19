#include <iostream>
#include <string.h>
#include "Save.h"
#include "Players.h"

Save::Save()
{
	name = "Save the scores";
}

Save::Save(int cmd)
{
	name = "Save user scores";

	command = cmd;
}

Save::~Save()
{
}

void Save::Run(Table* scoreboard)
{
	std::cout << "Scoredboard has been saved!" << std::endl;

	scoreboard->SaveFile();
}
