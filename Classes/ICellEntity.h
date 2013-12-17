#ifndef __ICELL_ENTITY_H__
#define __ICELL_ENTITY_H__

class ICellEntity
{
public:
	virtual const int GetCellX() const = 0;
	virtual const int GetCellY() const = 0;

	virtual void SetCell(const ICellEntity& cell) = 0;
	virtual void SetCell(const int cellX,const int cellY) = 0;

	virtual bool IsInSameCell(const ICellEntity& cell) const = 0;
};

#endif