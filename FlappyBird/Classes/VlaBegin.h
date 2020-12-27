#ifndef __VLA_BEGIN__
#define __VLA_BEGIN__

#include "cocos2d.h"

class VlaBegin : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void goToSecondGameScene(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(VlaBegin);
};

#endif // __VLA_BEGIN__
