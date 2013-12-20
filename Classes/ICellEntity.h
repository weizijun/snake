#ifndef __ICELL_ENTITY_H__
#define __ICELL_ENTITY_H__

USING_NS_CC;
#include "SnakeConstants.h"

class ICellEntity : public CCSprite
{
public:
	ICellEntity() : CCSprite()
	{

	}

	virtual const int GetCellX() const
	{
		return m_CellX;
	}

	virtual const int GetCellY() const
	{
		return m_CellY;
	}

	virtual void SetCell(const ICellEntity& cell)
	{
		return this->SetCell(cell.GetCellX(),cell.GetCellY());
	}

	virtual void SetCell(const int cellX,const int cellY)
	{
		{
			this->m_CellX = cellX;
			this->m_CellY = cellY;

			this->setPosition(ccp(m_CellX*SnakeGolbal::CELL_WIDTH+16,m_CellY*SnakeGolbal::CELL_HEIGHT+16));
		}
	}

	virtual bool IsInSameCell(const ICellEntity& cell) const
	{
		return m_CellX == cell.GetCellX() && m_CellY == cell.GetCellY();
	}

protected:
	int m_CellX;
	int m_CellY;
};

#endif