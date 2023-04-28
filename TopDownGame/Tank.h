//
// Created by Daniel on 16.03.2023.
//

#ifndef _TANK_H_
#define _TANK_H_

#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>

#include "EntityProperties.h"
#include "PlayerKeysAssignment.h"
#include "SFML/Graphics.hpp"

//TODO битовые флаги

enum TypeTank
{
	RedWhite,
	RedBlack,
	BlueWhite,
	BlueBlack,
	GreenWhite,
	GreenBlack,
	YellowWhite,
	YellowBlack,
};

class Tank : public EntityProperties
{
private:
	int _health;
	int _lives;
	int _damage;
	bool _isDead;
	TypeTank _type;

	double _baseMovementSpeed = 100000;
	double _baseAngle = 200000;
	double _movementSpeed = 100000;
	double _angle = 200000;


	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	PlayerKeysAssignment keysAssignment;

	bool isDead() const;

	int getLives() const;

	int getDamage() const;

	int getHealth() const;

	sf::Vector2f getOrigin() const;

	double getBaseAngle() const;

	double getBaseMovementSpeed() const;

	sf::FloatRect getGlobalBounds() const;

	TypeTank getType() const;

	double getMovementSpeed() const;

	void setMovementSpeed(double speed);

	double getAngle() const;

	void setAngle(double angle);

	sf::Texture getTexture() const;

	void setTexture(sf::Texture texture);

	sf::Sprite getSprite() const;

	void setSprite(sf::Sprite sprite);

	sf::Vector2f getPositionSprite() const;

	void setPositionSprite(float x, float y);

	void onDamage(int damage);

	Tank(TypeTank type, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key up, sf::Keyboard::Key down);

	~Tank();

	void initializeTexture();

	void initializeSprite();

	void render(sf::RenderWindow* window) const;

	void updateDirect();

	void update();

	void move(double x, double y, float dt);

	void turn(float angle, float dt);

	void turnLeft(float dt);

	void turnRight(float dt);

	void moveUp(float dt);

	void moveDown(float dt);
};

#endif //_TANK_H_
