#include "Commands.h"
#include "Table.h"
#include <iostream>

Commands::Commands()
{
	command = 1;
	name = "";
}

Commands::Commands(int cmd, const char* str)
{
	command = cmd;
	name = str;
}

Commands::~Commands()
{
	//delete[] name;
}

void Commands::Run(Table* scoreboard)
{
	std::cout << command << std::endl;
}