#pragma once

#include "cocos2d.h"
#include "common.h"
using namespace cocos2d;

class Jump_Player:public Node
{
public:
	virtual bool init() override;
	CREATE_FUNC(Jump_Player);
public:
	void run();
	void jump();
	void slide();
	PlayerState playerState;
private:
	Sprite *playerSprite;
	Sprite *playerSpriteSlideJump;
	Animate *playerAnim;
	Texture2D *jumpTexture;
	Texture2D *slideTexture;
	
};
