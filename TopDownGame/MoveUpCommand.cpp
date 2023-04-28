//
// Created by Daniel on 16.03.2023.
//

#include "MoveUpCommand.h"

MoveUpCommand::MoveUpCommand(sf::Keyboard::Key key) : KeyCommand(key)
{
}

void MoveUpCommand::execute(Tank* t, float dt)
{
	t->moveUp(dt);

}
