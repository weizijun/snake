#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "SnakeHead.h"

USING_NS_CC;

class Snake : public CCNode
{
public:
	~Snake();
	Snake(int cellx, int celly);

	const Direction GetDirection() const { return m_Direction; }
	void SetDirection(const Direction direction);
	void InitDirection();

	SnakeHead *GetHead() { return m_SnakeHead; } 
	int GetTailLength() { return m_ArrTail.count(); }
	void Grow() { m_isGrow = true; }

	int GetNextX();
	int GetNextY();

	bool Move();

	void Reset(int cellx, int celly);


private:
	SnakeHead *m_SnakeHead;
	Direction m_Direction;
	bool m_isGrow;
	Direction m_LastMoveDirection;
	CCArray m_ArrTail;
};

#endif