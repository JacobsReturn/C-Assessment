#include <iostream>
#include <string.h>
#include "Load.h"
#include "Players.h"

Load::Load()
{
	name = "Load the scores";
}

Load::Load(int cmd)
{
	name = "Load user scores";

	command = cmd;
}

Load::~Load()
{
}

void Load::Run(Table* scoreboard)
{
	std::cout << "Scoredboard has been Loaded!" << std::endl;

	scoreboard->LoadFile();
}
