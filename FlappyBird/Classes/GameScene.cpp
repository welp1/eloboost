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

#include "GameScene.h"
#include "HelloWorldScene.h"
#include "GameOver.h"
#include "GamePikachu/PikachuGameMenu.h"
#include "SecondGame/SecondGameScene.h"
#include "JumpGame/Jump_MainMenu.h"
#include "JumpGame/Jump_LoadingScene.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    // add layer as a child to scene
    layer->setPhysicWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    // return the scene
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //stopEffect(AudioEngine::play2d("sounds/Flappy_Bird/GameMenu.mp3"));

    // add "background" splash screen"

	auto spriteDown = Sprite::create("flappyBird/paralax/down1.png");
	auto spriteUp = Sprite::create("flappyBird/paralax/up1.png");
	if (spriteDown == nullptr)
	{
		problemLoading("'flappyBird/paralax/down1.png");
	}
	else
	{
		spriteUp->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		// position the sprite on the center of the screen
		spriteDown->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		this->addChild(spriteUp, 0);
		auto actionMoveTo1 = MoveTo::create(10, Vec2(-visibleSize.width / 2 - origin.x, visibleSize.height / 2 + origin.y));
		spriteUp->runAction(actionMoveTo1);
		// add the sprite as a child to this layer
		this->addChild(spriteDown, 0);
		auto actionMoveTo = MoveTo::create(3.5, Vec2(-visibleSize.width / 2 - origin.x, visibleSize.height / 2 + origin.y));
		spriteDown->runAction(actionMoveTo);
	}

	for (int i = 1; i <= 10; i++)
	{
		auto spriteUp1 = Sprite::create("flappyBird/paralax/up1.png");
		auto spriteDown1 = Sprite::create("flappyBird/paralax/down1.png");
		if (spriteDown1 == nullptr)
		{
			problemLoading("'flappyBird/paralax/down1.png");
		}
		else
		{
			spriteUp1->setPosition(Vec2(visibleSize.width / 2 + visibleSize.width * 0.98 * i + origin.x, visibleSize.height / 2 + origin.y));
			// position the sprite on the center of the screen
			spriteDown1->setPosition(Vec2(visibleSize.width / 2 + visibleSize.width * 0.98 * i + origin.x, visibleSize.height / 2 + origin.y));

			this->addChild(spriteUp1, 0);
			auto actionMoveTo1 = MoveTo::create(10 * (i + 1), Vec2(-visibleSize.width / 2 - origin.x, visibleSize.height / 2 + origin.y));
			spriteUp1->runAction(actionMoveTo1);
			// add the sprite as a child to this layer
			this->addChild(spriteDown1, 0);
			auto actionMoveTo = MoveTo::create(3.5 * (i + 1), Vec2(-visibleSize.width / 2 - origin.x, visibleSize.height / 2 + origin.y));
			spriteDown1->runAction(actionMoveTo);
		}
	}


    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5);
    edgeBody->setCollisionBitmask(2);
    edgeBody->setContactTestBitmask(true);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    edgeNode->setPhysicsBody(edgeBody);
    addChild(edgeNode);


	bird = Sprite::create("flappyBird/2.png");
	bird->setPosition(Vec2(visibleSize.width / 5, visibleSize.height / 2));
	bird->setScale(0.5);
	auto birdPhysic = PhysicsBody::createBox(bird->getContentSize());
	birdPhysic->setCollisionBitmask(4);
	birdPhysic->setContactTestBitmask(true);
	bird->setPhysicsBody(birdPhysic);
	addChild(bird, 2);

	Vector<SpriteFrame*> frames;
	Size playerSize = bird->getContentSize();
	frames.pushBack(SpriteFrame::create("flappyBird/2.png", Rect(0, 0, playerSize.width, playerSize.height)));
	frames.pushBack(SpriteFrame::create("flappyBird/1.png", Rect(0, 0, playerSize.width, playerSize.height)));
	auto animation = Animation::createWithSpriteFrames(frames, 0.6f);
	auto animate = Animate::create(animation);
	bird->runAction(RepeatForever::create(animate));

    std::string tempScore = cocos2d::StringUtils::format("%i", score);

    label = Label::createWithTTF(tempScore, "fonts/Marker Felt.ttf", visibleSize.height * 0.1);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.8));
    label->setColor(Color3B::WHITE);
    addChild(label);

    this->scheduleUpdate();
    auto createPipe = static_cast<cocos2d::SEL_SCHEDULE>(&GameScene::CreatePipe);
    this->schedule(createPipe, 0.003 * visibleSize.width);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::OnTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::OnContactBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    //Create a keyboard event listener
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    return true;
}

bool GameScene::onKeyBegin(EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
    {
        isFalling = false;
        auto volumeDie = AudioEngine::play2d("sounds/Flappy_Bird/wing.mp3");
        auto birdStopFly = static_cast<cocos2d::SEL_SCHEDULE>(&GameScene::stopFly);
        this->schedule(birdStopFly, 0.2);
        return true;
    }
    else
    {
        isFalling = true;
    }

    return true;
}

bool GameScene::OnContactBegan(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();

    if (a->getCollisionBitmask() == 4 && b->getCollisionBitmask() == 3 ||
        a->getCollisionBitmask() == 3 && b->getCollisionBitmask() == 4)
    {
        auto volumePoint = AudioEngine::play2d("sounds/Flappy_Bird/point.mp3");
        score++;
        std::string tempScore = cocos2d::StringUtils::format("%i", score);
        label->setString(tempScore);
    }
    else
    {
        if (a->getCollisionBitmask() == 4 && b->getCollisionBitmask() == 2 ||
            a->getCollisionBitmask() == 2 && b->getCollisionBitmask() == 4)
        {
            auto volumeDie = AudioEngine::play2d("sounds/Flappy_Bird/hit.mp3");
            auto sqe = GameOver::createScene(score);
            Director::getInstance()->replaceScene(sqe);
        }
    }

    if (score == 0)
    {
        auto secondGameScene = SecondGameScene::createScene();
        Director::getInstance()->replaceScene(
            TransitionFade::create(0.5, secondGameScene, Color3B(0, 255, 255)));

        /*auto pikachuGameMenu = PikachuGameMenu::createScene();
        Director::getInstance()->replaceScene(
            TransitionFade::create(0.5, pikachuGameMenu, Color3B(0, 255, 255)));*/

        /*auto jumpGameMenu = Jump_LoadingScene::createScene();
        Director::getInstance()->replaceScene(jumpGameMenu);*/
    }
    return true;
}

bool GameScene::OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    isFalling = false;
    auto volumeDie = AudioEngine::play2d("sounds/Flappy_Bird/wing.mp3");
    auto birdStopFly = static_cast<cocos2d::SEL_SCHEDULE>(&GameScene::stopFly);
    this->schedule(birdStopFly, 0.2);
    return true;
}

void GameScene::stopFly(float dt)
{
    isFalling = true;
}
void GameScene::update(float dt)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if (isFalling == true)
    {
        bird->setPositionX(visibleSize.width / 5);
        bird->setPositionY(bird->getPositionY() - visibleSize.height * 0.0030);
    }
    else
    {
        bird->setPositionX(visibleSize.width / 5);
        bird->setPositionY(bird->getPositionY() + visibleSize.height * 0.0030);
    }
}

void GameScene::CreatePipe(float dt)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto topPipe = Sprite::create("flappyBird/pipeDown.png");
    auto bottomPipe = Sprite::create("flappyBird/pipeUp.png");

    auto topPhysic = PhysicsBody::createBox(topPipe->getContentSize());
    topPhysic->setCollisionBitmask(2);
    topPhysic->setContactTestBitmask(true);
    topPipe->setPhysicsBody(topPhysic);

    auto bottomPhysic = PhysicsBody::createBox(bottomPipe->getContentSize());
    bottomPhysic->setCollisionBitmask(2);
    bottomPhysic->setContactTestBitmask(true);
    bottomPipe->setPhysicsBody(bottomPhysic);

    topPhysic->setDynamic(false);
    bottomPhysic->setDynamic(false);

    auto random = CCRANDOM_0_1();
    if (random < 0.25)
    {
        random = 0.25;
    }
    else
    {
        if (random > 0.75)
        {
            random = 0.75;
        }
    }

    auto topPipePosition = random * visibleSize.height + topPipe->getContentSize().height / 2;
    topPipe->setPosition(Vec2(visibleSize.width + topPipe->getContentSize().width / 2, topPipePosition));

    bottomPipe->setPosition(Vec2(topPipe->getPositionX(), topPipePosition - (Sprite::create("flappyBird/bird0_1.png")->getContentSize().height) * 5
        - topPipe->getContentSize().height));
    addChild(topPipe);
    addChild(bottomPipe);

    auto topMove = MoveBy::create(0.004 * visibleSize.width, Vec2(-visibleSize.width * 1.05, 0));
    auto bottomMove = MoveBy::create(0.004 * visibleSize.width, Vec2(-visibleSize.width * 1.05, 0));
    topPipe->runAction(topMove);
    bottomPipe->runAction(bottomMove);

    auto pointNode = Node::create();
    pointNode->setPosition(Vec2(topPipe->getPositionX(), topPipe->getPositionY() - topPipe->getContentSize().height / 2 -
        (Sprite::create("flappyBird/bird0_1.png")->getContentSize().height * 5) / 2));
    auto nodePhysic = PhysicsBody::createBox(Size(1, Sprite::create("flappyBird/bird0_1.png")->getContentSize().height * 5));

    nodePhysic->setCollisionBitmask(3);
    nodePhysic->setContactTestBitmask(true);
    nodePhysic->setDynamic(false);
    pointNode->setPhysicsBody(nodePhysic);

    auto nodeMove = MoveBy::create(0.004 * visibleSize.width, Vec2(-visibleSize.width * 1.05, 0));
    pointNode->runAction(nodeMove);
    addChild(pointNode);
}

