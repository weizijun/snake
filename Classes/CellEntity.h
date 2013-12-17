#ifndef __CELL_ENTITY_H__
#define __CELL_ENTITY_H__

#include "ICellEntity.h"

USING_NS_CC;

class CellEntity : public ICellEntity,public CCSprite
{
public:
	CellEntity(int cellX,int cellY,const char* fileName);
	virtual ~CellEntity();

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