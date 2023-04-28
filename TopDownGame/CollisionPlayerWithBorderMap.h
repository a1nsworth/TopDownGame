#ifndef _COLLISIONPLAYERWITHBORDERMAP_H_
#define _COLLISIONPLAYERWITHBORDERMAP_H_


#include "Tank.h"

class CollisionPlayerWithBorderMap
{
public:
	Tank* player;
	sf::FloatRect floatRect;

	CollisionPlayerWithBorderMap(Tank* player, const sf::FloatRect& floatRect)
	{
		this->player = player;
		this->floatRect = floatRect;
	}

	CollisionPlayerWithBorderMap() = default;

	bool areIntersects() const
	{
		return player->getGlobalBounds().intersects(floatRect);
	}

	void update()
	{
		// Collision Left
		if (const auto x = player->getPositionSprite().x - player->getOrigin().x; x < floatRect.top)
		{
			player->setPositionSprite(floatRect.top + player->getOrigin().x, player->getPositionSprite().y);
		}
		// Collision Left Top
		if (const auto y = player->getPositionSprite().y - player->getOrigin().y; y < floatRect.left)
		{
			player->setPositionSprite(player->getPositionSprite().x, floatRect.left + player->getOrigin().y);
		}

		// Collision Right
		if (const auto x = player->getPositionSprite().x + player->getOrigin().x; x > floatRect.width + floatRect.left)
		{
			player->setPositionSprite(floatRect.width + floatRect.left - player->getOrigin().x,
			                          player->getPositionSprite().y);
		}
		// Collision Right Bottom
		if (const auto y = player->getPositionSprite().y + player->getOrigin().y; y > floatRect.height + floatRect.top)
		{
			player->setPositionSprite(player->getPositionSprite().x,
			                          floatRect.height + floatRect.top - player->getOrigin().y);
		}
	}
};

#endif // _COLLISIONPLAYERWITHBORDERMAP_H_
