#include "SnakeScene.h"
#include "SnakeConstants.h"
#include "SmartRes.h"

using namespace cocos2d;

CCScene* SnakeScene::scene()
{
	CCScene *t_Scene = NULL;
	do 
	{
		t_Scene = CCScene::create();
		CC_BREAK_IF(!t_Scene);

		SnakeScene *layer = SnakeScene::create();
		CC_BREAK_IF(!layer);

		layer->setTouchEnabled(true);

		t_Scene->addChild(layer);
	} while (false);

	return t_Scene;
}

bool SnakeScene::init()
{
	bool t_Ret = false;
	do 
	{
		srand(time(NULL));
		m_nScore = 0;
		float t_CellsHorizon = SmartRes::sharedRes()->getRight() / SnakeGolbal::CELL_WIDTH;
		m_CellsHorizon =  t_CellsHorizon > static_cast<int>(t_CellsHorizon)+0.1 ? t_CellsHorizon + 1 : t_CellsHorizon ;

		float t_CellVertical = SmartRes::sharedRes()->getTop() / SnakeGolbal::CELL_HEIGHT;
		m_CellsVertical = t_CellVertical > static_cast<int>(t_CellVertical)+0.1 ? t_CellVertical + 1 : t_CellVertical ;



		for (int i = 0; i < SnakeGolbal::LAYER_COUNT; ++i)
		{
			this->addChild(CCLayer::create());
		}

		CCLayer* layer = (CCLayer*)this->getChildren()->objectAtIndex(SnakeGolbal::LAYER_BACKGROUND);
		CCSprite* pSprite = CCSprite::create(SnakeGolbal::BACKGROUND_IMAGE);
		layer->setTouchEnabled(true);
		CC_BREAK_IF(!pSprite);

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		pSprite->setPosition(ccp(size.width/2,size.height/2));
		layer->addChild(pSprite);

		layer = (CCLayer*)this->getChildren()->objectAtIndex(SnakeGolbal::LAYER_UI);
		CCMenuItemImage *pResetItem = CCMenuItemImage::create(
			SnakeGolbal::RESET_IMAGE,
			SnakeGolbal::RESET_IMAGE,
			this,
			menu_selector(SnakeScene::GameResetCallback));

		CC_BREAK_IF(!pResetItem);		
		pResetItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-20,20));

		CCMenu* pMenu = CCMenu::create(pResetItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);
		layer->addChild(pMenu);
			
		m_ScoreText = CCLabelTTF::create("Score:0",SnakeGolbal::SCORE_TTF,SnakeGolbal::SCORE_SIZE);
		m_ScoreText->setPosition(ccp(30,size.height - 30));
		m_ScoreText->setAnchorPoint(ccp(0,0.5));
		layer->addChild(m_ScoreText);

		m_BeginText = CCLabelTTF::create("Snake On Phone!",SnakeGolbal::BEGIN_TTF,SnakeGolbal::BEGIN_SIZE);
		m_BeginText->setPosition(ccp(size.width/2,size.height/2));
		layer->addChild(m_BeginText);
		m_BeginText->setScale(0.0f);

		m_GameOverText = new CCLabelTTF();
		m_GameOverText->initWithString("Game Over!",SnakeGolbal::GAMEOVER_TTF,SnakeGolbal::GAMEOVER_SIZE);
		m_GameOverText->setPosition(ccp(size.width/2,size.height/2));
		m_GameOverText->retain();
		m_GameOverText->autorelease();
		
		//schedule(schedule_selector(SnakeScene::ScheduleTick1),0.075f);
		schedule(schedule_selector(SnakeScene::GameCircle),0.5f);


		m_Snake = new Snake(RIGHT,0,m_CellsVertical/2);
		m_Snake->autorelease();
		m_Snake->GetHead()->Animate(0.5f);
		m_Snake->Grow();
		layer = (CCLayer*)this->getChildren()->objectAtIndex(SnakeGolbal::LAYER_SNAKE);
		layer->addChild(m_Snake);

		m_Frog = new Frog(0,0);
		m_Frog->autorelease();
		m_Frog->Animate(0.5f);
		this->SetFrogToRandomCell();
		layer = (CCLayer*)this->getChildren()->objectAtIndex(SnakeGolbal::LAYER_FOOD);
		layer->addChild(m_Frog);

		m_IsGameRunning = true;


		t_Ret = true;
	} while (false);
	return t_Ret;
}

void SnakeScene::SetFrogToRandomCell()
{
	int t_RandCellX = 1 + CCRANDOM_0_1() * (m_CellsHorizon-2-1);
	int t_RandCellY = 1 + CCRANDOM_0_1() * (m_CellsVertical-2-1);
	m_Frog->SetCell(t_RandCellX,t_RandCellY);
}

void SnakeScene::GameCircle(float dt)
{
	//CCLOG("circle:%f,time:%d",dt,time(NULL));
	if (m_IsGameRunning)
	{
		if (!m_Snake->Move())
		{
			OnGameOver();
		}

		HandleNewSnakePosition();		
	}
}

void SnakeScene::OnGameOver()
{
	CCLayer *layer = (CCLayer*)this->getChildren()->objectAtIndex(SnakeGolbal::LAYER_UI);
	layer->addChild(m_GameOverText);
	m_GameOverText->setScale(0);
	m_GameOverText->runAction(CCScaleTo::create(1.0,1.0));
	m_GameOverText->runAction(CCRotateBy::create(1.0,360));

	m_IsGameRunning = false;
}

void SnakeScene::GameResetCallback(CCObject* pSender)
{
	m_Snake->Reset(RIGHT,0,m_CellsVertical/2);
	m_nScore = 0;
	m_IsGameRunning = true;
}

void SnakeScene::HandleNewSnakePosition()
{
	const SnakeHead *t_SnakeHead = m_Snake->GetHead();
	if (t_SnakeHead->GetCellX() <= 0 || t_SnakeHead->GetCellX() >= m_CellsHorizon
		|| t_SnakeHead->GetCellY() <= 0 || t_SnakeHead->GetCellY() >= m_CellsVertical)
	{
		CCLOG("x:%d,y:%d",t_SnakeHead->GetCellX(),t_SnakeHead->GetCellY());
		OnGameOver();
	}
	else if(t_SnakeHead->IsInSameCell(*m_Frog))
	{
		m_nScore += 50;
		char score[128] = {0};
		sprintf(score, "Score: %d", m_nScore);
		m_ScoreText->setString(score);

		m_Snake->Grow();	

		this->SetFrogToRandomCell();
	}
}


bool SnakeScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void SnakeScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}

void SnakeScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("ccTouchEnded");
	CCPoint t_BeginPos = pTouch->getStartLocation();
	CCPoint t_EndPos = pTouch->getLocation();
	
	CCLOG("start x:%f,y%f",t_BeginPos.x,t_BeginPos.y);
	CCLOG("end x:%f,y%f",t_EndPos.x,t_EndPos.y);

	switch(m_Snake->GetDirection())
	{
	case UP:
	case DOWN:
		if (t_EndPos.x > t_BeginPos.x)
		{
			m_Snake->SetDirection(RIGHT);
		}
		else
		{
			m_Snake->SetDirection(LEFT);
		}
		break;
	case LEFT:
	case RIGHT:
		if (t_EndPos.y > t_BeginPos.y)
		{
			m_Snake->SetDirection(UP);
		}
		else
		{
			m_Snake->SetDirection(DOWN);
		}
		break;
	}

}
void SnakeScene::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("ccTouchCancelled");
}

void SnakeScene::registerWithTouchDispatcher() 
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}