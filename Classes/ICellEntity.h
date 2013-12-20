#ifndef __ICELL_ENTITY_H__
#define __ICELL_ENTITY_H__

#include "cocos2d.h"
#include "SnakeConstants.h"

USING_NS_CC;

class ICellEntity : public CCSprite
{
public:
	ICellEntity() : CCSprite()
	{

	}

	virtual const int GetCellX() const;
	virtual const int GetCellY() const;

	virtual void SetCell(const ICellEntity& cell);
	virtual void SetCell(const int cellX,const int cellY);

	virtual bool IsInSameCell(const ICellEntity& cell) const;

protected:
	int m_CellX;
	int m_CellY;
};

#endif