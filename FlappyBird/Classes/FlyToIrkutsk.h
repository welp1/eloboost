#ifndef __FLY_TO_IRKUTSK__
#define __FLY_TO_IRKUTSK__

#include "cocos2d.h"

class FlyToIrkutsk : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void welcomeToIrkutsk(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(FlyToIrkutsk);
};

#endif // __FLY_TO_IRKUTSK__
