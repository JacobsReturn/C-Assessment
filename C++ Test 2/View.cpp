#include <iostream>
#include <string.h>
#include "View.h"
#include "Players.h"

View::View()
{
	name = "View the scoreboard";
}

View::View(int cmd)
{
	name = "View the scoreboard";

	command = cmd;
}

View::~View()
{
}

void View::Run(Table* scoreboard)
{
	scoreboard->DisplayScores();
}
