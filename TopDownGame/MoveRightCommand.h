//
// Created by Daniel on 16.03.2023.
//

#ifndef _MOVERIGHTCOMMAND_H_
#define _MOVERIGHTCOMMAND_H_

#include "Command.h"
#include "KeyCommand.h"

class MoveRightCommand : public KeyCommand, public Command
{
public:
	MoveRightCommand(sf::Keyboard::Key);

	void execute(Tank* t, float dt) override;
};

#endif //_MOVERIGHTCOMMAND_H_
