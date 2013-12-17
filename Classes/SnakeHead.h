#ifndef __snake_head_h__
#define __snake_head_h__

#include "Direction.h"
#include "AnimatedCellEntity.h"

USING_NS_CC;

class SnakeHead : public AnimatedCellEntity
{
public:
	SnakeHead(int cellx,int celly);
	void SetRotation(const Direction direction);
};

#endif