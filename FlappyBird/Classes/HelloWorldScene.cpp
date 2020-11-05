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

#include "HelloWorldScene.h"
#include "GameScene.h"
#include "AudioEngine.h"
#include "utils/AudioManager.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
   // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //auto volumeGameMenu = AudioEngine::play2d("sounds/Flappy_Bird/GameMenu.mp3", true);

    /* Create title sprite */
    auto titleSprite = Sprite::create("title.png");
    titleSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + titleSprite->getContentSize().height));

    this->addChild(titleSprite);

    // Add image "PLAY" with callback HelloWorld::play
    //auto play = MenuItemLabel::create(Label::createWithTTF("PLAY", "fonts/Marker Felt.ttf", 40),
        //CC_CALLBACK_1(HelloWorld::play, this));

    auto play = MenuItemImage::create("playButton.png", "playButtonClicked.png", CC_CALLBACK_1(HelloWorld::play, this));
    CCASSERT(play != nullptr, "Fail to load PLAY images");

    // Add PLAY to menu
    // create menu, it's an autorelease object
    auto menu = Menu::create(play, NULL);
    menu->setPosition((Vec2(visibleSize) - origin) / 2);
    this->addChild(menu, 1);

    /* Create Sound checkbox */
    auto soundCheckBox = ui::CheckBox::create("SoundButton.png", "SoundButtonChecked.png");
    soundCheckBox->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - play->getContentSize().height * 1.4));

    soundCheckBox->setSelected(!AudioManager::getSoundState());

    this->addChild(soundCheckBox);

    soundCheckBox->addEventListener([](Ref* sender, ui::CheckBox::EventType type) {
        switch (type)
        {
        case cocos2d::ui::CheckBox::EventType::SELECTED:
            AudioManager::muteSounds();
            break;
        case cocos2d::ui::CheckBox::EventType::UNSELECTED:
            AudioManager::unmuteSounds();
            break;
        default:
            break;
        }
        });
    return true;
}

void HelloWorld::stopEffect(float dt)
{
    AudioEngine::end();
}

void HelloWorld::play(Ref* pSender) {
    auto gameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(0.5, gameScene, Color3B(0, 255, 255)));
}

