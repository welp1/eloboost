#ifndef __WELCOME_TO_SAINT__
#define __WELCOME_TO_SAINT__

#include "cocos2d.h"

class WelcomeToSaint : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void goToSaintBegin(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(WelcomeToSaint);
};

#endif // __WELCOME_TO_SAINT__
