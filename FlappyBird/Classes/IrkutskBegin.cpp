#include "IrkutskBegin.h"
#include "JumpGame/Jump_LoadingScene.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* IrkutskBegin::createScene()
{
    return IrkutskBegin::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool IrkutskBegin::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto GoToJumpGame = static_cast<cocos2d::SEL_SCHEDULE>(&IrkutskBegin::goToJumpGame);
    this->schedule(GoToJumpGame, 3);

    //add label "О черт! Там опасный лес. Мне надо преодолевать препятствия!"
    label = Label::createWithTTF("J xthn@ Nfv jgfcysq ktc= Vyt yflj ghtjljktdfnm ghtgzncndbz@", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    label->setColor(Color3B::WHITE);
    addChild(label);

    return true;
}

void IrkutskBegin::goToJumpGame(float displayTime)
{
    auto scene = Jump_LoadingScene::createScene();
    Director::getInstance()->replaceScene(scene);
}