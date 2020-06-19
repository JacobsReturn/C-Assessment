#pragma once
#include "Commands.h"
#include "Table.h"

class Add : public Commands
{
	private:
		
	public:
		Add();
		Add(int cmd);
		virtual ~Add();

		virtual void Run(Table* scoreboard) override;
};