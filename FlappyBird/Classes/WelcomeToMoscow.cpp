#include "WelcomeToMoscow.h"
#include "AudioEngine.h"
#include <Moscow.h>


USING_NS_CC;

Scene* WelcomeToMoscow::createScene()
{
    return WelcomeToMoscow::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool WelcomeToMoscow::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto GoToVlaBegin = static_cast<cocos2d::SEL_SCHEDULE>(&WelcomeToMoscow::inMoscow);
    this->schedule(GoToVlaBegin, 3);

    //add label "Добро пожаловать в Москву!"
    label = Label::createWithTTF("Lj,hj gj;fkjdfnm d Vjcrde@", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    label->setColor(Color3B::WHITE);
    addChild(label);

    return true;
}

void WelcomeToMoscow::inMoscow(float displayTime)
{
    auto scene = Moscow::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1, scene, Color3B(40, 47, 60)));
}