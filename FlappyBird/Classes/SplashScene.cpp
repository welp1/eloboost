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

    /* Create background sprite */
    auto backgroundSprite = Sprite::create("logo.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 1.6 + origin.y));
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

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bird.plist", "bird.png");
    const int numberSprite = 9;
    //bird 1
    auto gameSprite_1 = Sprite::createWithSpriteFrameName("bird-0.png");
    gameSprite_1->setPosition(visibleSize.width / 1.72, visibleSize.height / 3);
    this->addChild(gameSprite_1);

    Vector<SpriteFrame*> animFrames_1;
    animFrames_1.reserve(numberSprite);
    animFrames_1.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-1.png"));
    animFrames_1.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-2.png"));
    animFrames_1.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-3.png"));
    animFrames_1.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-4.png"));
    animFrames_1.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-5.png"));
    animFrames_1.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-6.png"));
    animFrames_1.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-7.png"));
    animFrames_1.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-8.png"));

    Animation* animation_1 = Animation::createWithSpriteFrames(animFrames_1, 0.156f);
    Animate* animate_1 = Animate::create(animation_1);
    gameSprite_1->runAction(RepeatForever::create(animate_1));


    // bird 2
    auto gameSprite_2 = Sprite::createWithSpriteFrameName("bird-0.png");
    gameSprite_2->setPosition(visibleSize.width / 2.4, visibleSize.height / 3);
    this->addChild(gameSprite_2);

    Vector<SpriteFrame*> animFrames_2;
    animFrames_2.reserve(numberSprite);
    animFrames_2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-1.png"));
    animFrames_2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-2.png"));
    animFrames_2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-3.png"));
    animFrames_2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-4.png"));
    animFrames_2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-5.png"));
    animFrames_2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-6.png"));
    animFrames_2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-7.png"));
    animFrames_2.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-8.png"));

    Animation* animation_2 = Animation::createWithSpriteFrames(animFrames_2, 0.156f);
    Animate* animate_2 = Animate::create(animation_2);
    gameSprite_2->runAction(RepeatForever::create(animate_2));


    //// bird 3
    //auto gameSprite_3 = Sprite::createWithSpriteFrameName("bird-0.png");
    //gameSprite_3->setPosition(visibleSize.width / 3.5, visibleSize.height / 1.15);
    //this->addChild(gameSprite_3);

    //Vector<SpriteFrame*> animFrames_3;
    //animFrames_3.reserve(numberSprite);
    //animFrames_3.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-1.png"));
    //animFrames_3.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-2.png"));
    //animFrames_3.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-3.png"));
    //animFrames_3.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-4.png"));
    //animFrames_3.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-5.png"));
    //animFrames_3.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-6.png"));
    //animFrames_3.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-7.png"));
    //animFrames_3.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-8.png"));

    //Animation* animation_3 = Animation::createWithSpriteFrames(animFrames_3, 0.156f);
    //Animate* animate_3 = Animate::create(animation_3);
    //gameSprite_3->runAction(RepeatForever::create(animate_3));


    //// bird 4
    //auto gameSprite_4 = Sprite::createWithSpriteFrameName("bird-0.png");
    //gameSprite_4->setPosition(visibleSize.width / 1.4, visibleSize.height / 1.15);
    //this->addChild(gameSprite_4);

    //Vector<SpriteFrame*> animFrames_4;
    //animFrames_4.reserve(numberSprite);
    //animFrames_4.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-1.png"));
    //animFrames_4.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-2.png"));
    //animFrames_4.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-3.png"));
    //animFrames_4.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-4.png"));
    //animFrames_4.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-5.png"));
    //animFrames_4.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-6.png"));
    //animFrames_4.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-7.png"));
    //animFrames_4.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird-8.png"));

    //Animation* animation_4 = Animation::createWithSpriteFrames(animFrames_4, 0.156f);
    //Animate* animate_4 = Animate::create(animation_4);
    //gameSprite_4->runAction(RepeatForever::create(animate_4));

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