#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include "SnakeConstants.h"

enum Direction
{
	DIR_NULL,
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

static int AddtoX(const Direction direction, const int dx)
{
	switch(direction)
	{
	case UP:
	case DOWN:
		return dx;
	case LEFT:
		return dx - 1;
	case RIGHT:
		return dx + 1;
	}

	return dx;
}

static int AddtoY(const Direction direction, const int dy)
{
	switch(direction) 
	{
	case LEFT:
	case RIGHT:
		return dy;
	case UP:
		return dy + 1;
	case DOWN:
		return dy - 1;
	}

	return dy;
}


static Direction Opposite(const Direction direction)
{
	switch(direction) {
	case UP:
		return DOWN;
	case DOWN:
		return UP;
	case LEFT:
		return RIGHT;
	case RIGHT:
		return LEFT;
	default:
		return DIR_NULL;
	}
}

#endif