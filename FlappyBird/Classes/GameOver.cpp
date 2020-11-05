/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameOver.h"
#include "GameScene.h"
#include "Definitions.h"
#include "HelloWorldScene.h"
USING_NS_CC;

unsigned int finalScore;
Scene* GameOver::createScene(unsigned int score)
{
    finalScore = score;
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = GameOver::create();
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /* Create 'Game Over' sprite */
    auto gameOverSprite = Sprite::create("GameOver.png");
    gameOverSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + gameOverSprite->getContentSize().height * 1.4));

    this->addChild(gameOverSprite);

    UserDefault* userDef = UserDefault::getInstance();
    auto highScore = userDef->getIntegerForKey("HIGH_SCORE", 0);

    /* Create label with final score */
    std::string finalScoreStr = cocos2d::StringUtils::format("FINAL SCORE: %i", finalScore);
    //__String *finalScoreStr = __String::createWithFormat("Final score: %i", finalScore);
    auto finalScoreLabel = Label::createWithTTF(finalScoreStr, "fonts/britanic bold.ttf", 55);
    finalScoreLabel->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + finalScoreLabel->getContentSize().height));

    this->addChild(finalScoreLabel);

    /* Create label with high score */
   //__String *highScoreStr;
    std::string highScoreStr;
    if (highScore < finalScore)
    {
        /* New score is the highest score so far */
        highScore = finalScore;
        userDef->setIntegerForKey("HIGH_SCORE", highScore);
        highScoreStr = cocos2d::StringUtils::format("NEW HIGH SCORE: %i", highScore);
        //highScoreStr = __String::createWithFormat("New high score: %i", highScore);
    }
    else
    {
        /* High score remains the same */
        highScoreStr = cocos2d::StringUtils::format("HIGH SCORE: %i", highScore);
        //highScoreStr = __String::createWithFormat("High score: %i", highScore);
    }
    highScoreLabel = Label::createWithTTF(highScoreStr, "fonts/britanic bold.ttf", 55);
    highScoreLabel->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - finalScoreLabel->getContentSize().height));

    this->addChild(highScoreLabel);

    /* Create Retry menu item */
    auto retryItem = MenuItemImage::create("RetryButton.png", "RetryButtonClicked.png", CC_CALLBACK_0(GameOver::retryGame, this));
    retryItem->setPosition(Point(visibleSize.width / 2 + origin.x - retryItem->getContentSize().width * 0.65, visibleSize.height / 2 + origin.y - (finalScoreLabel->getContentSize().height + highScoreLabel->getContentSize().height) * 1.8));

    /* Create Main Menu menu item */
    auto mainMenuItem = MenuItemImage::create("MainMenuButton.png", "MainMenuButtonClicked.png", CC_CALLBACK_0(GameOver::goToMainMenu, this));
    mainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x + mainMenuItem->getContentSize().width * 0.65, visibleSize.height / 2 + origin.y - (finalScoreLabel->getContentSize().height + highScoreLabel->getContentSize().height) * 1.8));

    /* Create Menu */
    auto menu = Menu::create(retryItem, mainMenuItem, nullptr);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    /*
    // Add image "REPLAY" with callback GameOver::play
    auto replay = MenuItemImage::create("flappyBird/replay_1.png", "flappyBird/replay_2.png", CC_CALLBACK_1(GameOver::replay, this));
    CCASSERT(replay != nullptr, "Fail to load REPLAY images");
    // Add REPLAY to menu
    // create menu, it's an autorelease object
    auto menu = Menu::create(replay, NULL);
    menu->setPosition((Vec2(visibleSize) - origin) / 2);
    this->addChild(menu, 1);
    */
    return true;
}

void GameOver::retryGame() {
    auto gameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.5, gameScene, Color3B(0, 255, 255)));
}

void GameOver::goToMainMenu()
{
    auto scene = HelloWorld::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene, Color3B(40, 47, 60)));
}

void GameOver::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
