#include "all.h"

int money_state;
int money=1000;			//Š‹à

void money_init()
{
    money_state = 0;
}

void money_updata()
{
	switch (money_state)
	{
	case 0:
		money_state++;

	case 1:
		money_state++;

	case 2:

		break;
	}
}