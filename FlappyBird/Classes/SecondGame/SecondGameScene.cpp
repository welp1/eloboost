#include "SecondGameScene.h"
#include "AudioEngine.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* SecondGameScene::createScene()
{
	auto scene = Scene::createWithPhysics();	
	scene->getPhysicsWorld()->setGravity(Vect(0,0));
    auto layer = SecondGameScene::create();
	#if COCOS2D_DEBUG
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	#endif
    scene->addChild(layer);
    return scene;
}


void SecondGameScene::setPhysicsBody(cocos2d::Sprite* sprite)
{
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 1.8);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	sprite->setPhysicsBody(body);
}

void SecondGameScene::setPhysicsBodyBrick(cocos2d::Sprite* sprite)
{
	auto body = PhysicsBody::createBox(sprite->getContentSize() / 2);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	sprite->setPhysicsBody(body);
}

bool SecondGameScene::explodeBombs(cocos2d::Touch* touch, cocos2d::Event* event)
{
	Vec2 touchLocation = touch->getLocation();
	cocos2d::Vector<cocos2d::Sprite*> toErase;

	for (auto bomb : _bombs)
	{
		if (bomb->getBoundingBox().containsPoint(touchLocation)) {
			//AudioEngine::play2d("bomb.mp3");
			//auto explosion = ParticleExplosion::create();
			auto explosion = ParticleSystemQuad::create("explosion.plist");
			explosion->setPosition(bomb->getPosition());
			this->addChild(explosion);
			bomb->setVisible(false);
			this->removeChild(bomb);
			toErase.pushBack(bomb);
		}
	}

	for (auto bomb : toErase)
	{
		_bombs.eraseObject(bomb);
	}

	return true;
}

void SecondGameScene::initTouch()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(SecondGameScene::explodeBombs, this);
	listener->onTouchMoved = CC_CALLBACK_2(SecondGameScene::movePlayerByTouch, this);
	listener->onTouchEnded = [=](Touch* touch, Event* event) {};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void SecondGameScene::movePlayerByTouch(Touch* touch, Event* event) {
	Vec2 touchLocation = touch->getLocation();
	if (_sprPlayer->getBoundingBox().containsPoint(touchLocation)) {
		movePlayerIfPossible(touchLocation.x);
	}
}

void SecondGameScene::movePlayerIfPossible(float newX) {
	float sprHalfWidth = _sprPlayer->getBoundingBox().size.width / 2;
	if (newX >= sprHalfWidth && newX < _visibleSize.width - sprHalfWidth) {
		_sprPlayer->setPositionX(newX);
	}
}

bool SecondGameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	_score = 0;
	_director = Director::getInstance();
	_visibleSize = _director->getVisibleSize();
	auto origin = _director->getVisibleOrigin();

	///////////////////////////// BOMB
	_sprBomb = Sprite::create("SecondGame/brick.png");
	_sprBomb->setPosition(_visibleSize.width / 2, _visibleSize.height + _sprBomb->getContentSize().height / 2);
	setPhysicsBodyBrick(_sprBomb);
	this->addChild(_sprBomb, 1);

	///////////////////////////// ÁÃ ט Ïכוונ
	auto bg = Sprite::create("SecondGame/bg.jpg");
	bg->setAnchorPoint(Vec2());
	bg->setPosition(0, 0);
	this->addChild(bg, -1);
	_sprPlayer = Sprite::create("SecondGame/player.png");
	_sprPlayer->setPosition(_visibleSize.width / 2, _visibleSize.height * 0.1);
	setPhysicsBody(_sprPlayer);
	this->addChild(_sprPlayer, 0);

	///////////////////////////// player
	Vector<SpriteFrame*> frames;
	Size playerSize = _sprPlayer->getContentSize();
	frames.pushBack(SpriteFrame::create("SecondGame/player.png", Rect(0, 0, playerSize.width, playerSize.height)));
	frames.pushBack(SpriteFrame::create("SecondGame/player2.png", Rect(0, 0, playerSize.width, playerSize.height)));
	auto animation = Animation::createWithSpriteFrames(frames, 0.5f);
	auto animate = Animate::create(animation);
	_sprPlayer->runAction(RepeatForever::create(animate));
	

	initPhysics();
	_sprBomb->getPhysicsBody()->setVelocity(Vect(0, -100));
	initTouch();

	//initBackButtonListener();
	schedule(CC_SCHEDULE_SELECTOR(SecondGameScene::updateScore), 3.0f);
	schedule(CC_SCHEDULE_SELECTOR(SecondGameScene::addBombs), 7.0f);
	_bombs.pushBack(_sprBomb);

    return true;
}

void SecondGameScene::addBombs(float dt)
{
	Sprite* bomb = nullptr;
	for (int i = 0; i < 3; i++)
	{
		bomb = Sprite::create("SecondGame/brick.png");
		bomb->setPosition(CCRANDOM_0_1() * _visibleSize.width, _visibleSize.height + bomb->getContentSize().height / 2);
		this->addChild(bomb, 1);
		setPhysicsBodyBrick(bomb);
		bomb->getPhysicsBody()->setVelocity(Vect(0, ((CCRANDOM_0_1() + 0.2f) * -250)));
		_bombs.pushBack(bomb);
	}
}

void SecondGameScene::updateScore(float dt)
{
	_score += 10;
	if (_score > 50) {
		_director->replaceScene(TransitionFlipX::create(1.0, SecondGameScene::createScene()));
	}
}

void SecondGameScene::initPhysics()
{
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(SecondGameScene::onCollision, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

}

bool SecondGameScene::onCollision(PhysicsContact& contact)
{
	CCLOG("Collision detected");
	auto playerShape = _sprPlayer->getPhysicsBody()->getFirstShape();
	if (playerShape != contact.getShapeA() && playerShape != contact.getShapeB())
	{
		return false;
	}
	AudioEngine::play2d("SecondGame/death.mp3");
	_director->replaceScene(TransitionFlipX::create(1.0, SecondGameScene::createScene()));

	/*if (_muteItem->isVisible())
	{
		AudioEngine::stopAll();
		AudioEngine::play2d("death.mp3");
	}*/

	UserDefault::getInstance()->setIntegerForKey("score", _score);
	//_director->replaceScene(TransitionFlipX::create(1.0, GameOver::createScene()));
	auto body = _sprBomb->getPhysicsBody();
	body->setVelocity(Vect());
	body->applyTorque(100900.5f);
	return false;
}