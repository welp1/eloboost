#ifndef __END_GAME_H__
#define __END_GAME_H__

#include "cocos2d.h"

class EndGame: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
private:
    void play(Ref *pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(EndGame);
};

#endif // __END_GAME_H__
