#include "Jump_Player.h"

bool Jump_Player::init()
{
	if(!Node::init())
		return false;

	Animation *personAnimation=Animation::create();
	for(int i=1;i<=12;i++)
		personAnimation->addSpriteFrameWithFile("animation"+std::to_string(i)+".png");
	personAnimation->setDelayPerUnit(0.1f);

	std::string playerTextureName;
	std::string playerJumpTexureName;
	std::string playerSlideTextureName;
	Animation *playerAnimation;

	playerTextureName="animation1.png";
	playerJumpTexureName="animation_jump.png";
	playerSlideTextureName="animation_slide.png";
	playerAnimation= personAnimation;

	playerSprite=Sprite::create(playerTextureName); 
	
	jumpTexture=Sprite::create(playerJumpTexureName)->getTexture();
	slideTexture=Sprite::create(playerSlideTextureName)->getTexture();

	playerAnim=Animate::create(playerAnimation);
	this->addChild(playerSprite);

	auto playerBody=PhysicsBody::createBox(playerSprite->getContentSize());
	playerBody->setDynamic(true);
	playerBody->setContactTestBitmask(1);
	playerBody->setGravityEnable(true);
	playerBody->getShape(0)->setRestitution(0.0f);
	this->setPhysicsBody(playerBody);

	playerSprite->runAction(RepeatForever::create(playerAnim));
	playerState=RUN;

	return true;
}

void Jump_Player::run()
{
	playerState=RUN;
	playerSprite->resume();
}

void Jump_Player::jump()
{
	playerState=JUMP;
	
	playerSprite->pause();
	playerSprite->setTexture(jumpTexture);
	this->getPhysicsBody()->setVelocity(Vec2(0,PLAYER_SPEED));

}

void Jump_Player::slide()
{
	playerState=SLIDE;
	playerSprite->pause();
	playerSprite->setTexture(slideTexture);
}