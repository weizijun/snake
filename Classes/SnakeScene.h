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

	void GameCircle(float dt);
	void GameResetCallback(CCObject* pSender);

	CREATE_FUNC(SnakeScene);

	bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void registerWithTouchDispatcher();
private:
	void SetFrogToRandomCell();

	void OnGameOver();
	void HandleNewSnakePosition();


private:
	int m_CellsHorizon;
	int m_CellsVertical;

	int m_nScore;
	bool m_IsGameRunning;

	CCLabelTTF* m_ScoreText;
	CCLabelTTF* m_GameOverText;
	CCLabelTTF* m_BeginText;

	Snake *m_Snake;
	Frog *m_Frog;
};

#endif