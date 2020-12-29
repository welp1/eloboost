#ifndef __FLY_TO_SAINT__
#define __FLY_TO_SAINT__

#include "cocos2d.h"

class FlyToSaint : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void welcomeSaint(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(FlyToSaint);
};

#endif // __FLY_TO_SAINT__
