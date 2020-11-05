#pragma once
#include <cocos2d.h>
#include <GamePikachu/PikachuBoard.h>

USING_NS_CC;

class PikachuBoardView : public Layer
{
	PikachuBoard* board;

	float squareSize, width, height;

	std::vector<std::vector<Sprite*>> pokemons;

public:

	static Layer* createBoardView(PikachuBoard* board);

	void showBoard();

	Sprite* addPokemon(int row, int column, int type);

	bool onTouchPokemon(Touch* touch, Event* event);

	void connectPokemons(int x, int y, int _x, int _y);

	FiniteTimeAction* getConnectEffect(int x, int y, int _x, int _y);

	Vec2 positionOf(int row, int column);

	std::pair<int, int> findRowAndColumnOfSprite(Node* pokemon);

	void removePokemon(int row, int column);

	void createChoosePokemonEffect(Node* pokemon);

	void removeChoosePokemonEffect();

	void createRemovePokemonEffect(Node* pokemon);

	CREATE_FUNC(PikachuBoardView);
};