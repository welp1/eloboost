#include "WelcomeToIrkutsk.h"
#include "IrkutskBegin.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* WelcomeToIrkutsk::createScene()
{
    return WelcomeToIrkutsk::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool WelcomeToIrkutsk::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto IrkutskBegin = static_cast<cocos2d::SEL_SCHEDULE>(&WelcomeToIrkutsk::irkutskBegin);
    this->schedule(IrkutskBegin, 3);

    //add label "Добро пожаловать в Иркутск!"
    label = Label::createWithTTF("Lj,hj gj;fkjdfnm d Bhrencr@", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    label->setColor(Color3B::WHITE);
    addChild(label);

    return true;
}

void WelcomeToIrkutsk::irkutskBegin(float displayTime)
{
    auto irkutskBegin = IrkutskBegin::createScene();
    Director::getInstance()->replaceScene(irkutskBegin);
}