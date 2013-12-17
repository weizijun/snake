#ifndef __SNAKE_SCENE_H__
#define __SNAKE_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Direction.h"
#include "Snake.h"
#include "Frog.h"

using namespace cocos2d;

class SnakeScene : public cocos2d::CCLayer
{
public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(SnakeScene);


private:
	void SetFrogToRandomCell();


private:
	int m_Store;
	bool m_IsGameRunning;

	CCLabelTTF* m_ScoreText;
	CCLabelTTF* m_GameOverText;
	CCLabelTTF* m_BeginText;

	Frog *m_Frog;
};

#endif