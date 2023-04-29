#ifndef _COLLISIONSBEHAVIORTWOPLAYER_H_
#define _COLLISIONSBEHAVIORTWOPLAYER_H_


#include "Tank.h"

class CollisionsBehaviorTwoPlayers
{
public:
	Tank* player1;
	Tank* player2;

	CollisionsBehaviorTwoPlayers(Tank* player1, Tank* player2)
	{
		this->player1 = player1;
		this->player2 = player2;
	}

	bool areIntersects() const
	{
		return player1->getGlobalBounds().intersects(player2->getGlobalBounds());
	}

	void update()
	{
		if (areIntersects())
		{

		}
	}
};


#endif //_COLLISIONSBEHAVIORTWOPLAYER_H_
