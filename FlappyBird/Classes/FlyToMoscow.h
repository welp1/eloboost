#ifndef __FLY_TO_MOSCOW__
#define __FLY_TO_MOSCOW__

#include "cocos2d.h"

class FlyToMoscow : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void welcomeMoscow(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(FlyToMoscow);
};

#endif // __FLY_TO_MOSCOW__
