#ifndef __SAINT_BEGIN__
#define __SAINT_BEGIN__

#include "cocos2d.h"

class SaintBegin : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void goToGamePikachu(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(SaintBegin);
};

#endif // __SAINT_BEGIN__
