#include "ToIrkutsk.h"
#include "FlyToIrkutsk.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* ToIrkutsk::createScene()
{
    return ToIrkutsk::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool ToIrkutsk::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto FlyToIrkutsk = static_cast<cocos2d::SEL_SCHEDULE>(&ToIrkutsk::flyToIrkutsk);
    this->schedule(FlyToIrkutsk, 3);

    //add label "Ооо так быстро! Там уже Иркутск!"
    label = Label::createWithTTF("Jjj nfr ,scnhj@ Nfv e;t Bhrencr@", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    label->setColor(Color3B::WHITE);
    addChild(label);

    return true;
}

void ToIrkutsk::flyToIrkutsk(float displayTime)
{
    auto flyToIrkutsk = FlyToIrkutsk::createScene();
    Director::getInstance()->replaceScene(flyToIrkutsk);
}