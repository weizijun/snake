#include "cocos2d.h"
#include "SnakeTailPart.h"
#include "SnakeConstants.h"

SnakeTailPart::SnakeTailPart(const SnakeHead* head)
	: CellEntity(head->GetCellX(),head->GetCellY(),SNAKE_BODY_IMAGE)
{

}