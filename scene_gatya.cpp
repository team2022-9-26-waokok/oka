#include"all.h"

int gatya_state;












void gatya_init()
{
    gatya_state = 0;
	srand((unsigned int)time(NULL));
}

void gatya_deinit()
{

}

void gatya_update()
{
	switch (game_state)
	{
	case 0:

		game_state++;

	case 1:

		game_state++;

	case 2:

		game_state++;
		break;
	}
}

void gatya_render()
{
	GameLib::clear(0.4549f, 0.3569f, 0.1020f);
}