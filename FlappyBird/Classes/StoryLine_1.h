#ifndef __STORY_LINE_1_H__
#define __STORY_LINE_1_H__

#include "cocos2d.h"

class StoryLine_1 : public cocos2d::Scene
{
private:
    cocos2d::Label* label;

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(StoryLine_1);
};

#endif // __STORY_LINE_1_H__
