#include "AudioEngine.h"
#include "common.h"
#include "Jump_MainMenu.h"
#include "Jump_GameScene.h"
#include "Jump_GameMap.h"
#include "WelcomeToSaint.h"


int jumpTimes=0;
int jumpTotal=2;

Scene * Jump_GameScene::createScene()
{
	auto *scene=Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0,GRAVITY));
	auto *layer= Jump_GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool Jump_GameScene::init()
{
	if(!Layer::init())
		return false;
	visibleSize=Director::getInstance()->getVisibleSize();
	visibleOrigin=Director::getInstance()->getVisibleOrigin();

	std::string backGroundFile = "forest.png";
	backGround1=Sprite::create(backGroundFile);
	backGround1->setAnchorPoint(Point::ZERO);
	backGround1->setPosition(Point::ZERO);
	this->addChild(backGround1,0);
	backGround2=Sprite::create(backGroundFile);
	backGround2->setAnchorPoint(Point::ZERO);
	backGround2->setPosition(Point::ZERO);
	this->addChild(backGround2,0);

	gameMap= Jump_GameMap::create();
	gameMap->setPosition(visibleOrigin.x,visibleOrigin.y);
	this->addChild(gameMap,1);

	player=Jump_Player::create();
	player->setPosition(Point(visibleOrigin.x+2*BLOCK_SIZE,visibleOrigin.y+2*BLOCK_SIZE));
	this->addChild(player,1);

	score=0;

	slideBtn=Sprite::create("slide_button.png");
	auto slideBtnTexture1=Sprite::create("slide_button.png")->getTexture();
	auto slideBtnTexture2=Sprite::create("slide_button_press.png")->getTexture();
	slideBtnTextures.pushBack(slideBtnTexture1);
	slideBtnTextures.pushBack(slideBtnTexture2);
	slideBtn->setScale(0.4);
	slideBtn->setPosition(Point(visibleOrigin.x+500,visibleOrigin.y+40));
	this->addChild(slideBtn,2);

	jumpBtn=Sprite::create("jump_button.png");
	auto jumpBtnTexture1=Sprite::create("jump_button.png")->getTexture();
	auto jumpBtnTexture2=Sprite::create("jump_button_press.png")->getTexture();
	jumpBtnTextures.pushBack(jumpBtnTexture1);
	jumpBtnTextures.pushBack(jumpBtnTexture2);
	jumpBtn->setScale(0.4);
	jumpBtn->setPosition(Point(visibleOrigin.x+visibleSize.width-500,visibleOrigin.y+40));
	this->addChild(jumpBtn,2);

	std::string tempScore = cocos2d::StringUtils::format("%i", score);
	label = Label::createWithTTF(tempScore, "fonts/Marker Felt.ttf", visibleSize.height * 0.1);

	label->setPosition(visibleOrigin.x+visibleSize.width-200,visibleOrigin.y+visibleSize.height-40);
	addChild(label);


	this->scheduleUpdate();

	auto contactListener=EventListenerPhysicsContact::create();
	contactListener->onContactBegin=CC_CALLBACK_1(Jump_GameScene::onContactBegin,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,this);

	auto touchListener=EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan=CC_CALLBACK_2(Jump_GameScene::onTouchBegan,this);
	touchListener->onTouchEnded=CC_CALLBACK_2(Jump_GameScene::onTouchEnded,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);

	return true;
}

bool Jump_GameScene::onTouchBegan(Touch *touch,Event *event)
{
	auto touchPoint=touch->getLocation();
	if(slideBtn->getBoundingBox().containsPoint(touchPoint))
	{
		slideBtn->setTexture(slideBtnTextures.at(1));
		player->slide();
	}

	if(jumpTimes<jumpTotal&&jumpBtn->getBoundingBox().containsPoint(touchPoint))
	{
		jumpBtn->setTexture(jumpBtnTextures.at(1));
		player->jump();
		jumpTimes++;
	}
		
	return true;
}

void Jump_GameScene::onTouchEnded(Touch *touch,Event *event)
{
	auto touchPoint=touch->getLocation();
	if(slideBtn->getBoundingBox().containsPoint(touchPoint))
	{
		slideBtn->setTexture(slideBtnTextures.at(0));
		player->run();
	}

	if(jumpBtn->getBoundingBox().containsPoint(touchPoint))
	{
		jumpBtn->setTexture(jumpBtnTextures.at(0));
	}

}

void Jump_GameScene::update(float dt)
{
	player->setRotation(0.0f); 
		
	float step=2.0f;
	if(player->getPositionX()<2*BLOCK_SIZE)
		player->setPositionX(player->getPositionX()+step);
	if(player->getPositionX()>2*BLOCK_SIZE)
		player->setPositionX(player->getPositionX()-step);
	if(player->getPositionY()<=0.0f)
		gameOver();
}

bool Jump_GameScene::onContactBegin(const PhysicsContact &contact)
{
	jumpTimes=0;

	auto target=contact.getShapeA()->getBody()->getNode();
	if(target->getTag() == GOLD)
	{
		gameMap->moveNode(target);
		addScore(100);
	}
	else if(target->getTag()== PUMPKIN && target->getPositionY()+target->getContentSize().height/2<player->getPositionY())
	{
		gameMap->moveNode(target);
		addScore(150);
	}
	else if(target->getTag()== PUMPKIN && target->getPositionY()+target->getContentSize().height/2>=player->getPositionY())
		gameOver();
	if(player->playerState==JUMP)
		player->run();
	return true;
}

void Jump_GameScene::onEnter()
{
	Layer::onEnter();
}

void Jump_GameScene::onExit()
{
	Layer::onExit();
}

void Jump_GameScene::backGroundUpdate(float dt)
{
	backGround1->setPositionX(backGround1->getPositionX()-1.0f);
	backGround2->setPositionX(backGround1->getPositionX()+backGround1->getContentSize().width);
	if(backGround2->getPositionX()<=0.0f)
		backGround1->setPositionX(0.0f);
}

void Jump_GameScene::addScore(float number)
{
	score+=number;
	std::string tempScore = cocos2d::StringUtils::format("%i", score);
	label->setString(tempScore);

	if (score > 1000)
	{
		auto welcomeToSaint = WelcomeToSaint::createScene();
		Director::getInstance()->replaceScene(
			TransitionFade::create(0.5, welcomeToSaint, Color3B(0, 255, 255)));
	}
}

void Jump_GameScene::gameOver()
{
	gameMap->unscheduleAllCallbacks();
	this->unscheduleAllCallbacks();

	visibleSize=Director::getInstance()->getVisibleSize();
	visibleOrigin=Director::getInstance()->getVisibleOrigin();
	
	auto gameOverPanel=Node::create();
	auto overLabel=Sprite::create("so_sad.png");
	overLabel->setPosition(visibleOrigin.x+visibleSize.width/2,visibleOrigin.y+visibleSize.height/2+100);
	gameOverPanel->addChild(overLabel);

	auto backItem=MenuItemImage::create("back_to_menu.png","back_to_menu_press.png",[](cocos2d::Ref *sender)
	{
		auto mainMenu= Jump_MainMenu::createScene();
		TransitionScene *transition=TransitionFade::create(1.0f,mainMenu);
		Director::getInstance()->replaceScene(transition);
	});
	auto backMenu=Menu::createWithItem(backItem);
	backMenu->setPosition(visibleOrigin.x+visibleSize.width/2,visibleOrigin.y+visibleSize.height/2-50);

	gameOverPanel->addChild(backMenu);

	gameOverPanel->setPositionY(visibleOrigin.y+visibleSize.height);
	this->addChild(gameOverPanel,3);
	gameOverPanel->runAction(MoveTo::create(0.5f,Vec2(visibleOrigin.x,visibleOrigin.y)));

}