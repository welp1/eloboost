#pragma once

#include "cocos2d.h"
#include "Jump_Player.h"
#include "Jump_GameMap.h"
USING_NS_CC;

class Jump_GameScene: public Layer
{
public:
	static Scene *createScene();

	CREATE_FUNC(Jump_GameScene);
private:
	virtual bool init() override;
	virtual void onEnter() override;
	virtual void onExit() override;

	virtual bool onTouchBegan(Touch *touch,Event *event) override;
	virtual void onTouchEnded(Touch *touch,Event *event) override;

	bool onContactBegin(const PhysicsContact &contact);

	virtual void update(float dt) override;
private:
	void backGroundUpdate(float dt);
	void addScore(float number);
	void gameOver();
private:
	Size visibleSize;
	Point visibleOrigin;

	Jump_Player *player;

	Sprite *slideBtn;
	Vector<Texture2D *> slideBtnTextures;
	Sprite *jumpBtn;
	Vector<Texture2D *> jumpBtnTextures;

	Sprite *backGround1,*backGround2;
	Jump_GameMap *gameMap;
	cocos2d::Label* label;
	int score;
};