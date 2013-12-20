#include "cocos2d.h"
#include "SnakeTailPart.h"
#include "SnakeConstants.h"

SnakeTailPart::SnakeTailPart(const SnakeHead* head)
{
	this->SetCell(head->GetCellX(),head->GetCellY());
	this->initWithFile(SnakeGolbal::SNAKE_BODY_IMAGE);
}