#include "cocos2d.h"
#include "Frog.h"
#include "SnakeConstants.h"

Frog::Frog(int cellX,int cellY)
	: AnimatedCellEntity(cellX,cellY,3,SnakeGolbal::FROG_IMAGE)
{

}