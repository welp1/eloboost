#include "SplashScene.h"
#include "HelloWorldScene.h"
#include "Definitions.h"
#include "AudioEngine.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

Scene* Splash::createScene()
{
    return Splash::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Splash::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto goToMainMenu = static_cast<cocos2d::SEL_SCHEDULE>(&Splash::goToMainMenu);
    this->schedule(goToMainMenu, DISPLAY_TIME_SPLASH_SCENE);
    //this->scheduleOnce(schedule_selector(Splash::goToMainMenu), DISPLAY_TIME_SPLASH_SCENE);

    /* Create background sprite */
    auto backgroundSprite = Sprite::create("logo.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.8 + origin.y));
    this->addChild(backgroundSprite);

    //add label  "Loading..."
    label = Label::createWithTTF("Loading...", "fonts/Marker Felt.ttf", visibleSize.height * 0.05);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4.9));
    label->setColor(Color3B::WHITE);
    addChild(label);

    auto LoadingBar = ui::LoadingBar::create("loader-bar.png");
    LoadingBar->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 7 + origin.y));
    LoadingBar->setPercent(0);
    this->addChild(LoadingBar, 3);
    LoadingBar->setTag(100);

    auto moveCloud = static_cast<cocos2d::SEL_SCHEDULE>(&Splash::MoveCloud);
    this->schedule(moveCloud, 0.03);
    return true;
}

void Splash::MoveCloud(float dt)
{
    auto ma = (ui::LoadingBar*)this->getChildByTag(100);
    ma->setPercent(ma->getPercent() + 1);
    if (ma->getPercent() >= 100)
    {
        return;
    }
}

void Splash::goToMainMenu(float displayTime)
{
    auto scene = HelloWorld::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene, Color3B(40, 47, 60)));
}