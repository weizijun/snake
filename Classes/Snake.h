#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "SnakeHead.h"

USING_NS_CC;

class Snake : public CCNode
{
	~Snake();
	Snake();

	const Direction GetDirection() const { return m_Direction; }
	void SetDirection(const Direction direction);

	SnakeHead *GetHead() { return m_SnakeHead; } 
	int GetTailLength() { return m_ArrTail.count(); }
	void Grow() { m_isGrow = true; }

	int GetNextX();
	int GetNextY();

	bool Move();

private:
	SnakeHead *m_SnakeHead;
	Direction m_Direction;
	bool m_isGrow;
	Direction m_LastMoveDirection;
	CCArray m_ArrTail;
};

#endif