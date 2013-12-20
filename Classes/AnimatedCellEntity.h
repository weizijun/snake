#ifndef __ANIMATED_CELL_ENTITY_H__
#define __ANIMATED_CELL_ENTITY_H__

#include "ICellEntity.h"

USING_NS_CC;

class AnimatedCellEntity : public ICellEntity
{
public:
	virtual ~AnimatedCellEntity();
	AnimatedCellEntity(int cellX,int cellY,int col,const char* fileName);
	void Animate(const float interval);

	//virtual const int GetCellX() const;
	//virtual const int GetCellY() const;

	//virtual void SetCell(const ICellEntity& cell);
	//virtual void SetCell(const int cellX,const int cellY);
	//virtual bool IsInSameCell(const ICellEntity& cell) const;
private:
	//int m_CellX;
	//int m_CellY;

	int m_TileW;
	int m_TileH;

	CCRepeatForever *m_Ani;
	CCAnimation *m_Animation;
};

#endif