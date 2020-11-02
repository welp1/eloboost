#pragma once
#include "cocos2d.h"
#include "PikachuBoard.h"
#include "PikachuBoardView.h"

USING_NS_CC;

class PikachuGameScene : public Scene
{
	Layer* boardView;

public:

	static Scene* createScene();

	virtual bool init();

	Layer* showBoard();

	void PikachuGameScene::showProgressTimer();

	void back(Ref* pSender);

	


	CREATE_FUNC(PikachuGameScene);
};