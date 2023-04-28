//
// Created by Daniel on 16.03.2023.
//

#ifndef _PLAYERINPUTCONTROLLER_H_
#define _PLAYERINPUTCONTROLLER_H_

#include <vector>
#include <ppl.h>


#include "Tank.h"
#include "MoveDownCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MoveUpCommand.h"

#include "SFML/Window.hpp"

class TwoPlayerInputController
{
private:
	bool _isMovingUp = false;
	bool _isMovingDown = false;
	bool _isMovingLeft = false;
	bool _isMovingRight = false;

	bool _isCollised = false;

	void resetMoving();

public:
	Tank* player1;
	Tank* player2;

	TwoPlayerInputController(Tank* player1, Tank* player2);

	void keyProcess(Tank* playerToMove, Tank* playerCanBeCollision, float dt);

	void keysProcessing(float dt);
};

#endif //_PLAYERINPUTCONTROLLER_H_
