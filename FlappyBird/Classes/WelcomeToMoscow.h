#ifndef __WELCOME_TO_MOSCOW__
#define __WELCOME_TO_MOSCOW__

#include "cocos2d.h"

class WelcomeToMoscow : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void inMoscow(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(WelcomeToMoscow);
};

#endif // __WELCOME_TO_MOSCOW__
