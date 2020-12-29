#ifndef __IRKUTSK_END__
#define __IRKUTSK_END__

#include "cocos2d.h"

class IrkutskEnd : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void flyToSaint(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(IrkutskEnd);
};

#endif // __IRKUTSK_END__
