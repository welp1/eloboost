#include "Jump_MainMenu.h"
#include "Jump_GameScene.h"

Scene* Jump_MainMenu::createScene()
{
	auto* scene = Scene::create();
	auto* layer = Jump_MainMenu::create();
	scene->addChild(layer);
	return scene;
}

bool Jump_MainMenu::init()
{
	if (!Layer::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto visibleOrigin = Director::getInstance()->getVisibleOrigin();

	auto menuBackGround = Sprite::create("main_menu.png");
	menuBackGround->setPosition(Point(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height / 2));
	this->addChild(menuBackGround, 0);

	auto personSprite = Sprite::create();
	personSprite->setPosition(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height / 2 + 260);
	this->addChild(personSprite, 0);
	auto personAnim = Animate::create(AnimationCache::getInstance()->getAnimation("personAnimation"));
	personSprite->runAction(RepeatForever::create(personAnim));

	auto newGameItem = MenuItemImage::create("jump_start.png", "jump_start_press.png", CC_CALLBACK_1(Jump_MainMenu::menuStartCallback, this));
	newGameItem->setPosition(Point(visibleOrigin.x + visibleSize.width / 2 + 15, visibleOrigin.y + visibleSize.height / 2 + 120));

	auto menu = Menu::create(newGameItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);

}

void Jump_MainMenu::onEnter()
{
	Layer::onEnter();
}

void Jump_MainMenu::onExit()
{
	Layer::onExit();
}

void Jump_MainMenu::menuStartCallback(Ref* sender)
{
	auto gameScene = Jump_GameScene::createScene();
	TransitionScene* transition = TransitionPageTurn::create(0.5f, gameScene, false);
	Director::getInstance()->replaceScene(transition);
}