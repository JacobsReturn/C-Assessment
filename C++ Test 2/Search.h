#pragma once
#include "Commands.h"
#include "Table.h"

class Search : public Commands
{
private:

public:
	Search();
	Search(int cmd);
	virtual ~Search();

	virtual void Run(Table* scoreboard) override;
};
