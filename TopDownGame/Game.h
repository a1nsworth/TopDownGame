//
// Created by Daniel on 09.03.2023.
//

#ifndef _GAME_H_
#define _GAME_H_

#include <stack>

#include "Tank.h"
#include "BackGround.h"
#include "TwoPlayerInputController.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "CollisionPlayerWithBorderMap.h"

#define FPS 144
#define TITLE "Tanks 1vs1"

class Game
{
private:
	sf::Clock _deltaClock;
	float _deltaTime;
	sf::RenderWindow* _window;
	sf::VideoMode _videoMode = sf::VideoMode(1738, 948);

	BackGround* _bg;
	Tank* _t1;
	Tank* _t2;


	std::stack<GameState*> _states;
	TwoPlayerInputController* inputController_;

	CollisionPlayerWithBorderMap collisionPlayer1AndBorderMap;
	CollisionPlayerWithBorderMap collisionPlayer2AndBorderMap;

	static Game* _instance;

	Game();

public:
	unsigned int getHeight() const;

	unsigned int getWidth() const;

	~Game();

	void run();

	// Update
	void update();

	void updateEvents();

	void updateDeltaTime();

	// Render
	void render();

	static Game* instance();
};

#endif //_GAME_H_
