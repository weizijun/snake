#include "cocos2d.h"
#include "AnimatedCellEntity.h"
#include "SnakeConstants.h"

AnimatedCellEntity::~AnimatedCellEntity()
{

}

AnimatedCellEntity::AnimatedCellEntity(int cellX,int cellY,int col,const char* fileName)
{
	m_CellX = cellX;
	m_CellY = cellY;

	m_Animation = CCAnimation::create();
	CCImage *image = new CCImage();
	image->autorelease();
	image->initWithImageFile(fileName);
	CCTexture2D *texture = new CCTexture2D();
    texture->initWithImage(image);
    m_TileW = texture->getPixelsWide() / col;
    m_TileH = texture->getPixelsHigh();
    
    for (int i = 0; i < col; ++i)
    {
        m_Animation->addSpriteFrameWithTexture(texture, CCRectMake(i*m_TileW, 0, m_TileW, m_TileH));
    }

    CCSpriteFrame *frm = ((CCAnimationFrame*)(m_Animation->getFrames()->objectAtIndex(0)))->getSpriteFrame();

	this->initWithSpriteFrame(frm);
    
    this->SetCell(cellX,cellY);
}


void AnimatedCellEntity::Animate(const float interval)
{
	m_Animation->setDelayPerUnit(interval);
	m_Ani = CCRepeatForever::create(CCAnimate::create(m_Animation));
	this->runAction(m_Ani);
}

//const int AnimatedCellEntity::GetCellX() const
//{
//	return m_CellX;
//}
//
//const int AnimatedCellEntity::GetCellY() const
//{
//	return m_CellY;
//}
//
//void AnimatedCellEntity::SetCell(const ICellEntity& cell)
//{
//	this->SetCell(cell.GetCellX(),cell.GetCellY());
//}
//
//void AnimatedCellEntity::SetCell(const int cellX,const int cellY)
//{
//	m_CellX = cellX;
//	m_CellY = cellY;
//
//	this->setPosition(ccp(m_CellX*SnakeGolbal::CELL_WIDTH+16,m_CellY*SnakeGolbal::CELL_HEIGHT+16));
//}
//
//bool AnimatedCellEntity::IsInSameCell(const ICellEntity& cell) const
//{
//	return m_CellX == cell.GetCellX() && m_CellY == cell.GetCellY();
//}