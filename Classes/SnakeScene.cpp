#include "SnakeScene.h"
#include "SnakeConstants.h"

using namespace cocos2d;

CCScene* SnakeScene::scene()
{
	CCScene *scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		SnakeScene *layer = SnakeScene::create();
		CC_BREAK_IF(!layer);

		scene->addChild(layer);
	} while (false);

	return scene;
}

bool SnakeScene::init()
{
	bool t_Ret = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		for (int i = 0; i < SnakeGolbal::LAYER_COUNT; ++i)
		{
			this->addChild(CCLayer::create());
		}

		CCLayer* layer = (CCLayer*)this->getChildren()->objectAtIndex(SnakeGolbal::LAYER_BACKGROUND);
		layer->setTouchEnabled(true);
		CCSprite* pSprite = CCSprite::create(SnakeGolbal::BACKGROUND_IMAGE);
		CC_BREAK_IF(!pSprite);

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		pSprite->setPosition(ccp(size.width/2,size.height/2));
		layer->addChild(pSprite);

		m_ScoreText = CCLabelTTF::create("Score:0",SnakeGolbal::SCORE_TTF,SnakeGolbal::SCORE_SIZE);
		m_ScoreText->setPosition(ccp(30,size.height - 30));
		m_ScoreText->setAnchorPoint(ccp(0,0.5));
		layer->addChild(m_ScoreText);

		m_BeginText = CCLabelTTF::create("Snake On Phone!",SnakeGolbal::BEGIN_TTF,SnakeGolbal::BEGIN_SIZE);
		m_BeginText->setPosition(ccp(size.width/2,size.height/2));
		layer->addChild(m_BeginText);
		//m_BeginText->setScale(0.5f);

		m_GameOverText = new CCLabelTTF();
		m_GameOverText->initWithString("Game Over!",SnakeGolbal::GAMEOVER_TTF,SnakeGolbal::GAMEOVER_SIZE);
		m_GameOverText->setPosition(ccp(size.width/2,size.height/2));
		m_GameOverText->retain();
		m_GameOverText->autorelease();
		
		//schedule(schedule_selector(SnakeScene::ScheduleTick1),0.075f);
		//schedule(schedule_selector(SnakeScene::GameCircle),0.5f);

		m_Frog = new Frog(0,0);
		m_Frog->autorelease();
		m_Frog->Animate(0.5f);
		this->SetFrogToRandomCell();
		layer = (CCLayer*)this->getChildren()->objectAtIndex(SnakeGolbal::LAYER_FOOD);
		layer->addChild(m_Frog);

		t_Ret = true;
	} while (false);
	return t_Ret;
}

void SnakeScene::SetFrogToRandomCell()
{
	int t_RandCellX = 1 + CCRANDOM_0_1() * (SnakeGolbal::CELLS_HORIZON-2-1);
	int t_RandCellY = 1 + CCRANDOM_0_1() * (SnakeGolbal::CELLS_VERTICAL-2-1);
	m_Frog->SetCell(t_RandCellX,t_RandCellY);
}