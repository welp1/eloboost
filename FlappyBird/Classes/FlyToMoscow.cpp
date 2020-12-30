#include "FlyToMoscow.h"
#include "WelcomeToMoscow.h"
#include "AudioEngine.h"
#include <WelcomeToMoscow.h>


USING_NS_CC;

Scene* FlyToMoscow::createScene()
{
    return FlyToMoscow::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool FlyToMoscow::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto WelcomeSaint = static_cast<cocos2d::SEL_SCHEDULE>(&FlyToMoscow::welcomeMoscow);
    this->schedule(WelcomeSaint, 3);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Fly.plist", "Fly.png");
    const int numberSprite = 4;
    auto gameSprite = Sprite::createWithSpriteFrameName("Fly-0.png");
    gameSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    this->addChild(gameSprite);

    Vector<SpriteFrame*> animFrames;
    animFrames.reserve(numberSprite);
    animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("Fly-1.png"));
    animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("Fly-2.png"));
    animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("Fly-3.png"));

    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.16f);
    Animate* animate = Animate::create(animation);
    gameSprite->runAction(RepeatForever::create(animate));
    return true;
}

void FlyToMoscow::welcomeMoscow(float displayTime)
{
    auto welcomeToMoscow = WelcomeToMoscow::createScene();
    Director::getInstance()->replaceScene(welcomeToMoscow);
}