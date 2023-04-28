//
// Created by Daniel on 16.03.2023.
//

#include "TwoPlayerInputController.h"


void TwoPlayerInputController::resetMoving()
{
	_isMovingUp = false;
	_isMovingDown = false;
	_isMovingLeft = false;
	_isMovingRight = false;
}

TwoPlayerInputController::TwoPlayerInputController(Tank* player1, Tank* player2)
{
	this->player1 = player1;
	this->player2 = player2;
}

void TwoPlayerInputController::keyProcess(Tank* playerToMove, Tank* playerCanBeCollision, const float dt)
{
	auto isCollision = playerToMove->getGlobalBounds().intersects(playerCanBeCollision->getGlobalBounds());

	resetMoving();

	if (sf::Keyboard::isKeyPressed(playerToMove->keysAssignment.moveUpCommand->getKey()))
	{
		_isMovingUp = true;

		//playerToMove->keysAssignment.moveUpCommand->execute(playerToMove, dt);
	}
	if (sf::Keyboard::isKeyPressed(playerToMove->keysAssignment.moveDownCommand->getKey()))
	{
		_isMovingDown = true;
		///playerToMove->keysAssignment.moveDownCommand->execute(playerToMove, dt);
	}
	if (sf::Keyboard::isKeyPressed(playerToMove->keysAssignment.moveLeftCommand->getKey()))
	{
		_isMovingLeft = true;
		//playerToMove->keysAssignment.moveLeftCommand->execute(playerToMove, dt);
	}
	if (sf::Keyboard::isKeyPressed(playerToMove->keysAssignment.moveRightCommand->getKey()))
	{
		_isMovingRight = true;
		//playerToMove->keysAssignment.moveRightCommand->execute(playerToMove, dt);
	}

	if (isCollision)
	{
		if (_isMovingUp)
		{
			if (_isMovingDown)
			{
				playerToMove->keysAssignment.moveUpCommand->execute(playerToMove, dt);
			}
			else
			{
				playerToMove->keysAssignment.moveDownCommand->execute(playerToMove, dt);
			}
		}
		if (_isMovingDown)
		{
			if (_isMovingUp)
			{
				playerToMove->keysAssignment.moveDownCommand->execute(playerToMove, dt);
			}
			else
			{
				playerToMove->keysAssignment.moveUpCommand->execute(playerToMove, dt);
			}
		}
		if (_isMovingLeft)
		{
			playerToMove->keysAssignment.moveRightCommand->execute(playerToMove, dt);
		}
		if (_isMovingRight)
		{
			playerToMove->keysAssignment.moveLeftCommand->execute(playerToMove, dt);
		}
	
		_isCollised = true;
	}
	else
	{
		if (_isMovingUp)
		{
			playerToMove->keysAssignment.moveUpCommand->execute(playerToMove, dt);
		}
		if (_isMovingDown)
		{
			playerToMove->keysAssignment.moveDownCommand->execute(playerToMove, dt);
		}
		if (_isMovingLeft)
		{
			playerToMove->keysAssignment.moveLeftCommand->execute(playerToMove, dt);
		}
		if (_isMovingRight)
		{
			playerToMove->keysAssignment.moveRightCommand->execute(playerToMove, dt);
		}
	
		_isCollised = false;
	}
}

void TwoPlayerInputController::keysProcessing(const float dt)
{
	keyProcess(player1, player2, dt);
	keyProcess(player2, player1, dt);
}
