#include "AudioEngine.h"
#include "Jump_LoadingScene.h"
#include "Jump_MainMenu.h"
using namespace cocos2d;

USING_NS_CC;

Scene* Jump_LoadingScene::createScene()
{
	return Jump_LoadingScene::create();
}

bool Jump_LoadingScene::init()
{
	if (!Scene::init())
		return false;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void Jump_LoadingScene::onEnter()
{
	Director::getInstance()->getTextureCache()->addImageAsync("animation.png", CC_CALLBACK_1(Jump_LoadingScene::loadingCallBack, this));
}

void Jump_LoadingScene::loadingCallBack(Texture2D* texture)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("animation.plist", texture);

	auto personAnimation = Animation::create();
	personAnimation->setDelayPerUnit(0.1f);
	for (int i = 1; i <= 12; i++)
	{
		char str[100] = { 0 };
		sprintf(str, "animation%d.png", i);
		personAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str));
	}

	AnimationCache::getInstance()->addAnimation(personAnimation, "personAnimation");

	auto mainMenu = Jump_MainMenu::createScene();
	TransitionScene* transition = TransitionFade::create(1.0f, mainMenu);
	Director::getInstance()->replaceScene(transition);
}