#pragma once
#include "Table.h"

class Commands
{
private:

public:
	const char * name = "";
	int command;

	Commands();
	Commands(int cmd, const char* str);
	virtual ~Commands();

	virtual void Run(Table* scoreboard);
};