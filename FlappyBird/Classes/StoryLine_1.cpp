#include "StoryLine_1.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* StoryLine_1::createScene()
{
    return StoryLine_1::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StoryLine_1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //add label  "Loading..."
    label = Label::createWithTTF("√де-то в –оссии Е. 2077 год", "fonts/Marker Felt.ttf", visibleSize.height * 0.1);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    label->setColor(Color3B::WHITE);
    addChild(label);

    return true;
}