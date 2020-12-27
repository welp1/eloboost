#ifndef __STREAM_SCENE__
#define __STREAM_SCENE__

#include "cocos2d.h"

class streamScene : public cocos2d::Scene
{
private:
    void play(float displayTime);
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(streamScene);
};

#endif // __STREAM_SCENE__
