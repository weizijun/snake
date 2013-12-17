#include "cocos2d.h"
#include "Direction.h"
#include "Snake.h"
#include "SnakeTailPart.h"

Snake::Snake(const Direction dir, int cellx, int celly)
{
	m_SnakeHead = new SnakeHead(cellx,celly);
	m_SnakeHead->autorelease();

	this->addChild(m_SnakeHead);
	this->SetDirection(dir);
}

void Snake::SetDirection(const Direction direction)
{
	if (m_LastMoveDirection != Opposite(direction))
	{
		m_Direction = direction;
		m_SnakeHead->SetRotation(direction);
	}
}

Snake::~Snake()
{

}

int Snake::GetNextX()
{
	return AddtoX(m_Direction,m_SnakeHead->GetCellX());
}

int Snake::GetNextY()
{
	return AddtoY(m_Direction,m_SnakeHead->GetCellY());
}

bool Snake::Move()
{
	m_LastMoveDirection = m_Direction;
	if (m_isGrow)
	{
		m_isGrow = false;
		SnakeTailPart *t_NewTailPart = new SnakeTailPart(m_SnakeHead);
		this->addChild(t_NewTailPart);
		m_ArrTail.insertObject(t_NewTailPart,0);
	}
	else
	{
		if (m_ArrTail.count() > 0)
		{
			SnakeTailPart *t_TailEnd = (SnakeTailPart *)m_ArrTail.lastObject();
			m_ArrTail.removeLastObject(false);
			t_TailEnd->SetCell(*m_SnakeHead);

			m_ArrTail.insertObject(t_TailEnd,0);
		}
	}

	m_SnakeHead->SetCell(GetNextX(),GetNextY());

	for (int i = m_ArrTail.count() - 1; i >= 0; --i)
	{
		if (m_SnakeHead->IsInSameCell(*(SnakeTailPart*)m_ArrTail.objectAtIndex(i)))
		{
			return false;
		}
	}

	return true;
}

void Snake::Reset()
{
	m_SnakeHead->SetCell(0,SnakeGolbal::CELLS_VERTICAL/2);
	m_Direction = RIGHT;

	Grow();
}