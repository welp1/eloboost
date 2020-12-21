#include "Jump_GameMap.h"
#include "common.h"

bool Jump_GameMap::init()
{
	if(!Node::init())
		return false;

	std::string grass_file;
	std::string pumpkin_file;

	grass_file ="green_grass.png";
	pumpkin_file ="pumpkin.png";

	std::string gold_file="gold.png";
	for(int i = 0;i < 10;i++)
	{
		if(i!=3&&i!=4&&i!=7&&i!=8)
		{
			auto block=Sprite::create(grass_file);
			block->setPosition(BLOCK_SIZE/2+i*BLOCK_SIZE,BLOCK_SIZE/2+0.5*BLOCK_SIZE);
			this->addChild(block);
			block->setTag(LAND);
			auto blockBody=PhysicsBody::createBox(block->getContentSize());
			blockBody->setDynamic(false);
			blockBody->setContactTestBitmask(1);
			blockBody->getShape(0)->setRestitution(0);
			block->setPhysicsBody(blockBody);
		}
	}
	for(int i = 0;i < 10;i++)
	{
		if(i==2||i==5||i==6)
		{
			auto npc=Sprite::create(pumpkin_file);
			npc->setTag(PUMPKIN);
			npc->setPosition(BLOCK_SIZE/2+i*BLOCK_SIZE,BLOCK_SIZE/2+1.4*BLOCK_SIZE);
			auto npcBody=PhysicsBody::createBox(npc->getContentSize());
			npcBody->setDynamic(false);
			npcBody->setContactTestBitmask(1);
			npcBody->getShape(0)->setRestitution(0);
			npc->setPhysicsBody(npcBody);
			this->addChild(npc);
		}
		if(i==3)
		{
			auto block=Sprite::create(grass_file);
			block->setPosition(BLOCK_SIZE/2+i*BLOCK_SIZE,BLOCK_SIZE/2+0.5*BLOCK_SIZE);
			this->addChild(block);
			block->setTag(LAND);
			auto blockBody=PhysicsBody::createBox(block->getContentSize());
			blockBody->setDynamic(false);
			blockBody->setContactTestBitmask(1);
			blockBody->getShape(0)->setRestitution(0);
			block->setPhysicsBody(blockBody);
		}
	}
	for(int i = 0;i < 10;i++)
	{
		if(i==1 || i==5 || i==7 || i==9)
		{
			auto gold1=Sprite::create(gold_file);
			gold1->setTag(GOLD);
			gold1->setPosition(PICKUP_SIZE/2+i*BLOCK_SIZE,BLOCK_SIZE/2+3*BLOCK_SIZE);
			auto goldBody1=PhysicsBody::createBox(gold1->getContentSize());
			goldBody1->setDynamic(false);
			goldBody1->setContactTestBitmask(1);
			goldBody1->getShape(0)->setRestitution(0.0f);
			gold1->setPhysicsBody(goldBody1);
			this->addChild(gold1);

			auto gold2=Sprite::create(gold_file);
			gold2->setTag(GOLD);
			gold2->setPosition(PICKUP_SIZE/2*3+i*BLOCK_SIZE,BLOCK_SIZE/2+3*BLOCK_SIZE);
			auto goldBody2=PhysicsBody::createBox(gold2->getContentSize());
			goldBody2->setDynamic(false);
			goldBody2->setContactTestBitmask(1);
			goldBody2->getShape(0)->setRestitution(0.0f);
			gold2->setPhysicsBody(goldBody2);
			this->addChild(gold2);
		}

	}

	for(int i=0;i<10;i++)
	{
		if(i==3||i==4)
		{
			auto block=Sprite::create(grass_file);
			block->setPosition(BLOCK_SIZE/2+i*BLOCK_SIZE,BLOCK_SIZE/2+3.5*BLOCK_SIZE);
			this->addChild(block);
			block->setTag(LAND);
			auto blockBody=PhysicsBody::createBox(block->getContentSize());
			blockBody->setDynamic(false);
			blockBody->setContactTestBitmask(1);
			blockBody->getShape(0)->setRestitution(0);
			block->setPhysicsBody(blockBody);
		}
		if(i==8)
		{
			auto gold1=Sprite::create(gold_file);
			gold1->setTag(GOLD);
			gold1->setPosition(PICKUP_SIZE/2+i*BLOCK_SIZE,BLOCK_SIZE/2+3*BLOCK_SIZE);
			auto goldBody1=PhysicsBody::createBox(gold1->getContentSize());
			goldBody1->setDynamic(false);
			goldBody1->setContactTestBitmask(1);
			goldBody1->getShape(0)->setRestitution(0.0f);
			gold1->setPhysicsBody(goldBody1);
			this->addChild(gold1);

			auto gold2=Sprite::create(gold_file);
			gold2->setTag(GOLD);
			gold2->setPosition(PICKUP_SIZE/2*3+i*BLOCK_SIZE,BLOCK_SIZE/2+3*BLOCK_SIZE);
			auto goldBody2=PhysicsBody::createBox(gold2->getContentSize());
			goldBody2->setDynamic(false);
			goldBody2->setContactTestBitmask(1);
			goldBody2->getShape(0)->setRestitution(0.0f);
			gold2->setPhysicsBody(goldBody2);
			this->addChild(gold2);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 2 || i == 4 || i == 9)
		{
			auto gold1 = Sprite::create(gold_file);
			gold1->setTag(GOLD);
			gold1->setPosition(PICKUP_SIZE / 2 + i * BLOCK_SIZE, BLOCK_SIZE / 2 + 5 * BLOCK_SIZE);
			auto goldBody1 = PhysicsBody::createBox(gold1->getContentSize());
			goldBody1->setDynamic(false);
			goldBody1->setContactTestBitmask(1);
			goldBody1->getShape(0)->setRestitution(0.0f);
			gold1->setPhysicsBody(goldBody1);
			this->addChild(gold1);
		}
		if (i == 1 || i == 5)
		{
			auto gold2 = Sprite::create(gold_file);
			gold2->setTag(GOLD);
			gold2->setPosition(PICKUP_SIZE / 2 + i * BLOCK_SIZE, BLOCK_SIZE / 2 + 8.5 * BLOCK_SIZE);
			auto goldBody2 = PhysicsBody::createBox(gold2->getContentSize());
			goldBody2->setDynamic(false);
			goldBody2->setContactTestBitmask(1);
			goldBody2->getShape(0)->setRestitution(0.0f);
			gold2->setPhysicsBody(goldBody2);
			this->addChild(gold2);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 5 || i == 7)
		{
			auto block = Sprite::create(grass_file);
			block->setPosition(BLOCK_SIZE / 2 + i * BLOCK_SIZE, BLOCK_SIZE / 2 + 5.5 * BLOCK_SIZE);
			this->addChild(block);
			block->setTag(LAND);
			auto blockBody = PhysicsBody::createBox(block->getContentSize());
			blockBody->setDynamic(false);
			blockBody->setContactTestBitmask(1);
			blockBody->getShape(0)->setRestitution(0);
			block->setPhysicsBody(blockBody);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 2 || i == 4 || i == 8)
		{
			auto block = Sprite::create(grass_file);
			block->setPosition(BLOCK_SIZE / 2 + i * BLOCK_SIZE, BLOCK_SIZE / 2 + 7.5 * BLOCK_SIZE);
			this->addChild(block);
			block->setTag(LAND);
			auto blockBody = PhysicsBody::createBox(block->getContentSize());
			blockBody->setDynamic(false);
			blockBody->setContactTestBitmask(1);
			blockBody->getShape(0)->setRestitution(0);
			block->setPhysicsBody(blockBody);
		}
	}

	auto MapUpdate = static_cast<cocos2d::SEL_SCHEDULE>(&Jump_GameMap::mapUpdate);
	this->schedule(MapUpdate, 0.01f);

	return true;
}

void Jump_GameMap::mapUpdate(float dt)
{
	for(auto &node:this->getChildren())
	{
		node->setPositionX(node->getPositionX()-3.0f);
		if(node->getPositionX()<=-node->getContentSize().width/2)
			node->setPositionX(node->getPositionX()+BLOCK_SIZE/2+10*BLOCK_SIZE);
	}

}

void Jump_GameMap::moveNode(Node *child)
{
	child->setPositionX(child->getPositionX()+BLOCK_SIZE/2+10*BLOCK_SIZE);
}