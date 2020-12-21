#pragma once
enum PlayerState
{
	RUN,
	SLIDE,
	JUMP
};
enum BlockType
{
	LAND,
	PUMPKIN,
	GOLD,
	TOOL,
	NONE
};

const float BLOCK_SIZE=80.0f; 
const float PICKUP_SIZE=40.0f;
const float PLAYER_RADIUS=50.0f;
const float GRAVITY=-1500.0f;
const float PLAYER_SPEED=700.0f;

