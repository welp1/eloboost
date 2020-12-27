#include "streamScene.h"
#include "AudioEngine.h"
#include "GameScene.h"

USING_NS_CC;

Scene* streamScene::createScene()
{
    return streamScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool streamScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto GoToStoryLine_2 = static_cast<cocos2d::SEL_SCHEDULE>(&streamScene::play);
    this->schedule(GoToStoryLine_2, 1);

    auto streamG304 = Sprite::create("stream.png");
    streamG304->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.8 + origin.y));
    this->addChild(streamG304);

    return true;
}

void streamScene::play(float displayTime)
{
    auto scene = GameScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B(40, 47, 60)));
}