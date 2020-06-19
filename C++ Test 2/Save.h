#pragma once
#include "Commands.h"
#include "Table.h"

class Save : public Commands
{
private:

public:
	Save();
	Save(int cmd);
	virtual ~Save();

	virtual void Run(Table* scoreboard) override;
};