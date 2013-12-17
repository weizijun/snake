#include "cocos2d.h"
#include "SnakeHead.h"
#include "SnakeConstants.h"

SnakeHead::SnakeHead(int cellX,int cellY)
	: AnimatedCellEntity(cellX,cellY,3,SnakeGolbal::SNAKE_HEAD_IMAGE)
{
	//this->setAnchorPoint(ccp(0.5f,0.75f));
	//this->setScale(2.0f);
}

void SnakeHead::SetRotation(const Direction dirction)
{
	switch(dirction)
	{
	case UP :
		this->setRotation(180);
		break;
	case DOWN:
		this->setRotation(0);
		break;
	case LEFT:
		this->setRotation(90);
		break;
	case RIGHT:
		this->setRotation(270);
		break;
	}
}