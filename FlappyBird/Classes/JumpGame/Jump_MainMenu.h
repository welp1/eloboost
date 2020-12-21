#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Jump_MainMenu : public Layer
{
public:
	static Scene* createScene();

	CREATE_FUNC(Jump_MainMenu);
private:
	void menuStartCallback(Ref* sender);

	virtual bool init() override;
	virtual void onEnter() override;
	virtual void onExit();
};