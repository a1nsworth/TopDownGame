//
// Created by Daniel on 16.03.2023.
//

#include "MoveDownCommand.h"
MoveDownCommand::MoveDownCommand(sf::Keyboard::Key key) : KeyCommand(key)
{
}
void MoveDownCommand::execute(Tank* t, float dt)
{
	t->moveDown(dt);

}
