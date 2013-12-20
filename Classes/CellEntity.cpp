#include "cocos2d.h"
#include "CellEntity.h"
#include "SnakeConstants.h"

CellEntity::CellEntity(int cellX,int cellY,const char* fileName)
	
{
	this->SetCell(cellX,cellY);
	this->initWithFile(fileName);
}

CellEntity::~CellEntity()
{

}

//const int CellEntity::GetCellX() const
//{
//	return m_CellX;
//}
//
//const int CellEntity::GetCellY() const
//{
//	return m_CellY;
//}
//
//void CellEntity::SetCell(const ICellEntity& cell)
//{
//	return this->SetCell(cell.GetCellX(),cell.GetCellY());
//}
//
//void CellEntity::SetCell(const int cellX,const int cellY)
//{
//	this->m_CellX = cellX;
//	this->m_CellY = cellY;
//
//	this->setPosition(ccp(m_CellX*SnakeGolbal::CELL_WIDTH+16,m_CellY*SnakeGolbal::CELL_HEIGHT+16));
//}
//
//bool CellEntity::IsInSameCell(const ICellEntity& cell) const
//{
//	return m_CellX == cell.GetCellX() && m_CellY == cell.GetCellY();
//}