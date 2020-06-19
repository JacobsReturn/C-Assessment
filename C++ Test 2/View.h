#pragma once
#include "Commands.h"
#include "Table.h"

class View : public Commands
{
private:

public:
	View();
	View(int cmd);
	virtual ~View();

	virtual void Run(Table* scoreboard) override;
};
