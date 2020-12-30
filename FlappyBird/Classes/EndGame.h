#ifndef __END_GAME__
#define __END_GAME__

#include "cocos2d.h"

class EndGame : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void flyToMoscow(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(EndGame);
};

#endif // __END_GAME__
