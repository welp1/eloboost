#ifndef __STORY_LINE_2_H__
#define __STORY_LINE_2_H__

#include "cocos2d.h"

class StoryLine_2 : public cocos2d::Scene
{
private:
    cocos2d::Label* label1;
    cocos2d::Label* label2;
    void goToStreamScene(float displayTime);
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(StoryLine_2);
};

#endif // __STORY_LINE_2_H__
