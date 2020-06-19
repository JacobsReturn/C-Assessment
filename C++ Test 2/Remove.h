#pragma once
#include "Commands.h"
#include "Table.h"

class Remove : public Commands
{
private:

public:
	Remove();
	Remove(int cmd);
	virtual ~Remove();

	virtual void Run(Table* scoreboard) override;
};
