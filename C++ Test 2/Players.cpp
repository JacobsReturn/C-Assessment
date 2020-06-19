#include <string.h>
#include "Players.h"

Players::Players() 
{
	score = 0;
	strcpy_s(name, "");
}

Players::~Players()
{
}
