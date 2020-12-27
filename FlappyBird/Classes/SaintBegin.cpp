#include "SaintBegin.h"
#include "GamePikachu/PikachuGameMenu.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* SaintBegin::createScene()
{
    return SaintBegin::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SaintBegin::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto GoToStoryLine_2 = static_cast<cocos2d::SEL_SCHEDULE>(&SaintBegin::goToGamePikachu);
    this->schedule(GoToStoryLine_2, 3);

    //add label "О мне тут надо половить покемонов!"
    label = Label::createWithTTF("J vyt nen yflj gjkjdbnm gjrtvjyjd@", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    label->setColor(Color3B::WHITE);
    addChild(label);

    return true;
}

void SaintBegin::goToGamePikachu(float displayTime)
{
    auto scene = PikachuGameMenu::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B(40, 47, 60)));
}