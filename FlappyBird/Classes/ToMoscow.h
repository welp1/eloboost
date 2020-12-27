#ifndef __TO_MOSCOW__
#define __TO_MOSCOW__

#include "cocos2d.h"

class ToMoscow : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void goTojumpGame(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(ToMoscow);
};

#endif // __TO_MOSCOW__
