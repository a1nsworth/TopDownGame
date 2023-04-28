//
// Created by Daniel on 16.03.2023.
//

#include "MoveRightCommand.h"
MoveRightCommand::MoveRightCommand(sf::Keyboard::Key key) : KeyCommand(key)
{
}
void MoveRightCommand::execute(Tank* t, float dt)
{
	t->turnRight(dt);

}
