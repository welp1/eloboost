#ifndef __TO_IRKUTSK__
#define __TO_IRKUTSK__

#include "cocos2d.h"

class ToIrkutsk : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void flyToIrkutsk(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(ToIrkutsk);
};

#endif // __TO_IRKUTSK__
