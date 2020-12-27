#include "StoryLine_2.h"
#include "streamScene.h"
#include "AudioEngine.h"


USING_NS_CC;

Scene* StoryLine_2::createScene()
{
    return StoryLine_2::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StoryLine_2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto GoToStoryLine_2 = static_cast<cocos2d::SEL_SCHEDULE>(&StoryLine_2::goToStreamScene);
    this->schedule(GoToStoryLine_2, 4);

    //add label "Дядя Фёдор решил полететь в Москву за подарками внукам на своём новом ранце"
    label1 = Label::createWithTTF("Lzlz Atljh htibk gjktntnm d Vjcrde", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 1.8));
    label1->setColor(Color3B::WHITE);
    addChild(label1);

    label2 = Label::createWithTTF("pf gjlfhrfvb dyerfv yf cdjtv yjdjv hfywt", "fonts/CYRIL1.TTF", visibleSize.height * 0.05);
    label2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2.2));
    label2->setColor(Color3B::WHITE);
    addChild(label2);

    return true;
}

void StoryLine_2::goToStreamScene(float displayTime)
{
    auto StreamScene = streamScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(1, StreamScene, Color3B(40, 47, 60)));
}