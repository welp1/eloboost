#include "ToMoscow.h"
#include "ToIrkutsk.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* ToMoscow::createScene()
{
    return ToMoscow::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool ToMoscow::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto GoToIrkutsk = static_cast<cocos2d::SEL_SCHEDULE>(&ToMoscow::goToIrkutsk);
    this->schedule(GoToIrkutsk, 3);

    //add label "Надо долететь до Москвы!"
    label = Label::createWithTTF("Yflj ljktntnm lj Vjcrds@", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    label->setColor(Color3B::WHITE);
    addChild(label);

    return true;
}

void ToMoscow::goToIrkutsk(float displayTime)
{
    auto jumpGameMenu = ToIrkutsk::createScene();
    Director::getInstance()->replaceScene(jumpGameMenu);
}