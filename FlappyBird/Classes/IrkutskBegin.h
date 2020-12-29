#ifndef __IRKUTSK_BEGIN__
#define __IRKUTSK_BEGIN__

#include "cocos2d.h"

class IrkutskBegin : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void goToJumpGame(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(IrkutskBegin);
};

#endif // __IRKUTSK_BEGIN__
