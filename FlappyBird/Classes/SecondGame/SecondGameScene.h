#ifndef __SECONDGAME_SCENE_H__
#define __SECONDGAME_SCENE_H__

#include "cocos2d.h"

class SecondGameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SecondGameScene);
private:
	cocos2d::Director *_director;
	cocos2d::Size _visibleSize;
	cocos2d::Sprite* _sprBomb;
	cocos2d::Sprite* _sprPlayer;
	cocos2d::Sprite* _sprPlayerLeft;
	cocos2d::Label* label;
	int _score = 0;
	void setPhysicsBody(cocos2d::Sprite* sprite);
	void setPhysicsBodyBrick(cocos2d::Sprite* sprite);
	cocos2d::Vector<cocos2d::Sprite*> _bombs;
	bool explodeBombs(cocos2d::Touch* touch, cocos2d::Event* event);
	void initTouch();
	void movePlayerByTouch(cocos2d::Touch* touch, cocos2d::Event* event);
	void movePlayerIfPossible(float newX);
	
	////////////////////////////
	void initPhysics();
	bool onCollision(cocos2d::PhysicsContact& contact);
	void updateScore(float dt);
	void addBombs(float dt);
};

#endif // __SECONDGAME_SCENE_H__
