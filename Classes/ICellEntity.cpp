#include "ICellEntity.h"

const int ICellEntity::GetCellX() const
{
	return m_CellX;
}

const int ICellEntity::GetCellY() const
{
	return m_CellY;
}

void ICellEntity::SetCell(const ICellEntity& cell)
{
	return this->SetCell(cell.GetCellX(),cell.GetCellY());
}

void ICellEntity::SetCell(const int cellX,const int cellY)
{
	this->m_CellX = cellX;
	this->m_CellY = cellY;

	this->setPosition(ccp(m_CellX*SnakeGolbal::CELL_WIDTH+SnakeGolbal::CELL_WIDTH/2+SnakeGolbal::g_CellsWidthBegin,m_CellY*SnakeGolbal::CELL_HEIGHT+SnakeGolbal::CELL_HEIGHT/2+SnakeGolbal::g_CellsHeightBegin));
}

bool ICellEntity::IsInSameCell(const ICellEntity& cell) const
{
	return m_CellX == cell.GetCellX() && m_CellY == cell.GetCellY();
}