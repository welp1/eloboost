#ifndef __WELCOME_TO_VLA__
#define __WELCOME_TO_VLA__

#include "cocos2d.h"

class WelcomeToVla : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void goToVlaBegin(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(WelcomeToVla);
};

#endif // __WELCOME_TO_VLA__
