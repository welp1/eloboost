#ifndef __WELCOME_TO_IRKUTSK__
#define __WELCOME_TO_IRKUTSK__

#include "cocos2d.h"

class WelcomeToIrkutsk : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void irkutskBegin(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(WelcomeToIrkutsk);
};

#endif // __WELCOME_TO_IRKUTSK__
