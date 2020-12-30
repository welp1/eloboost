#ifndef __MOSCOW_H__
#define __MOSCOW_H__

#include "cocos2d.h"

class Moscow : public cocos2d::Scene
{
private:
    cocos2d::Label* label;
    void goToMainMenu(float displayTime);

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Moscow);
};

#endif // __MOSCOW_H__
