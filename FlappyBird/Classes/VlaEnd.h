#ifndef __VLA_END__
#define __VLA_END__

#include "cocos2d.h"

class VlaEnd : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void goToSceneToMoscow(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(VlaEnd);
};

#endif // __VLA_END__
