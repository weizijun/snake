#ifndef __SNAKE_CONSTANTS_H__
#define __SNAKE_CONSTANTS_H__

#include <string>

namespace SnakeGolbal
{
	static const int LAYER_COUNT = 4; 
	static const int LAYER_BACKGROUND = 0;
	static const int LAYER_FOOD = 1;
	static const int LAYER_SNAKE = 2;
	static const int LAYER_UI = 3;

	static const char *SCORE_TTF = "Plok.ttf";
	static const int SCORE_SIZE = 24;

	static const char *BEGIN_TTF = "Plok.ttf";
	static const int BEGIN_SIZE = 30;

	static const char *GAMEOVER_TTF = "Plok.ttf";
	static const int GAMEOVER_SIZE = 30;

	static const char *BACKGROUND_IMAGE = "background.png";

	static const char *SNAKE_BODY_IMAGE = "snake_tailpart.png";
	static const char *SNAKE_HEAD_IMAGE = "snake_head.png";

	static const char *FROG_IMAGE = "frog.png";

	static const int CELLS_HORIZON = 20;
	static const int CELLS_VERTICAL = 12;
	static const int CELL_WIDTH = 32;
	static const int CELL_HEIGHT = CELL_WIDTH;
	static const int CAMERA_WIDTH = CELLS_HORIZON * CELL_WIDTH; 
	static const int CAMERA_HEIGHT = CELLS_VERTICAL * CELL_HEIGHT;
}

#endif