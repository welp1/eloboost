#include "VlaBegin.h"
#include "SecondGame/SecondGameScene.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* VlaBegin::createScene()
{
    return VlaBegin::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool VlaBegin::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto GoToStoryLine_2 = static_cast<cocos2d::SEL_SCHEDULE>(&VlaBegin::goToSecondGameScene);
    this->schedule(GoToStoryLine_2, 2);

    //add label "О черт! Начинается град! Уворачивайся"
    label = Label::createWithTTF("J xthn@ Yfxbyftncz uhfl@ Edjhfxbdfqcz@", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    label->setColor(Color3B::WHITE);
    addChild(label);

    return true;
}

void VlaBegin::goToSecondGameScene(float displayTime)
{
    auto scene = SecondGameScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B(40, 47, 60)));
}