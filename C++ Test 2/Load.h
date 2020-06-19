#pragma once
#include "Commands.h"
#include "Table.h"

class Load : public Commands
{
private:

public:
	Load();
	Load(int cmd);
	virtual ~Load();

	virtual void Run(Table* scoreboard) override;
};