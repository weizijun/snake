#ifndef __SNAKE_TAIL_PART_H__
#define __SNAKE_TAIL_PART_H__

#include "CellEntity.h"
#include "SnakeHead.h"

USING_NS_CC;

class SnakeTailPart : public CellEntity
{
public:
	SnakeTailPart(const SnakeHead* head);
};

#endif