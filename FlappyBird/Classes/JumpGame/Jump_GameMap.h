#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Jump_GameMap:public Node
{
public:
	virtual bool init() override;
	CREATE_FUNC(Jump_GameMap);

public:
	void moveNode(Node *child);
private:
	void mapUpdate(float dt);
};