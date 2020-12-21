#ifndef __JUMP_GAMEMENU_SCENE_H__
#define __JUMP_GAMEMENU_SCENE_H__

#pragma once
#include "cocos2d.h"

class Jump_LoadingScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(Jump_LoadingScene);
private:
	virtual void onEnter() override;
	void loadingCallBack(cocos2d::Texture2D* texture);
};
#endif // __JUMP_GAMEMENU_SCENE_H__