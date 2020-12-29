#ifndef __PIKACHU_GAME_OVER_H__
#define __PIKACHU_GAME_OVER_H__

#include "cocos2d.h"

class PikachuGameOver: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
private:
    void play(Ref *pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(PikachuGameOver);
};

#endif // __PIKACHU_GAME_OVER_H__
