//
// Created by Daniel on 16.03.2023.
//

#include "Tank.h"

bool Tank::isDead() const
{
	return _isDead;
}

int Tank::getLives() const
{
	return _lives;
}

int Tank::getDamage() const
{
	return _damage;
}

int Tank::getHealth() const
{
	return _health;
}

sf::Vector2f Tank::getOrigin() const
{
	return _sprite.getOrigin();
}

double Tank::getBaseAngle() const
{
	return _baseAngle;
}

double Tank::getBaseMovementSpeed() const
{
	return _baseMovementSpeed;
}

sf::FloatRect Tank::getGlobalBounds() const
{
	return _sprite.getGlobalBounds();
}

Tank::Tank(const TypeTank type,
           sf::Keyboard::Key left,
           sf::Keyboard::Key right,
           sf::Keyboard::Key up,
           sf::Keyboard::Key down) : _health(5), _lives(5), _damage(1), _isDead(false), _type(type),
                                     keysAssignment(left, right, up, down)
{
	initializeTexture();
	initializeSprite();
}

Tank::~Tank()
{
	keysAssignment.~PlayerKeysAssignment();
}

void Tank::onDamage(int damage)
{
	if (_health - damage <= 0)
	{
		if (_lives > 1)
		{
			_health = 5;
		}
		_lives--;
	}
	else
	{
		_health -= damage;
	}

	_isDead = _lives <= 0;
}

TypeTank Tank::getType() const
{
	return _type;
}

void Tank::initializeTexture()
{
	switch (_type)
	{
	case YellowWhite:
		_texture.loadFromFile("../Textures/Tiles.png", sf::IntRect(10, 600, 54, 79));
		break;
	case YellowBlack:
		_texture.loadFromFile("../Textures/Tiles.png", sf::IntRect(250, 600, 54, 79));
		break;
	case RedWhite:
		_texture.loadFromFile("../Textures/Tiles.png", sf::IntRect(10, 705, 54, 79));
		break;
	case RedBlack:
		_texture.loadFromFile("../Textures/Tiles.png", sf::IntRect(250, 705, 54, 79));
		break;
	case BlueWhite:
		_texture.loadFromFile("../Textures/Tiles.png", sf::IntRect(250, 805, 54, 79));
		break;
	case BlueBlack:
		_texture.loadFromFile("../Textures/Tiles.png", sf::IntRect(10, 805, 54, 79));
		break;
	case GreenWhite:
		_texture.loadFromFile("../Textures/Tiles.png", sf::IntRect(10, 905, 54, 79));
		break;
	case GreenBlack:
		_texture.loadFromFile("../Textures/Tiles.png", sf::IntRect(250, 905, 54, 79));
		break;
	}
}

void Tank::initializeSprite()
{
	_sprite.setTexture(_texture);
	_sprite.scale(sf::Vector2f(1.1f, 1.1f));
	_sprite.setOrigin(27, 39.5);
}

void Tank::render(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}

void Tank::updateDirect()
{
	const auto angel = (_sprite.getRotation()) * M_PI / 180;
	setDirect(sf::Vector2f(sin(angel), cos(angel)));
}

void Tank::update()
{
	updateDirect();
}

double Tank::getMovementSpeed() const
{
	return _movementSpeed;
}

void Tank::setMovementSpeed(const double speed)
{
	_movementSpeed = speed;
}

double Tank::getAngle() const
{
	return _angle;
}

void Tank::setAngle(const double angle)
{
	_angle = angle;
}

sf::Texture Tank::getTexture() const
{
	return _texture;
}

void Tank::setTexture(sf::Texture texture)
{
	_texture = texture;
}

sf::Sprite Tank::getSprite() const
{
	return _sprite;
}

void Tank::setSprite(sf::Sprite sprite)
{
	_sprite = sprite;
}

sf::Vector2f Tank::getPositionSprite() const
{
	return _sprite.getPosition();
}

void Tank::setPositionSprite(const float x, const float y)
{
	_sprite.setPosition(x, y);
}

void Tank::move(const double x, const double y, float dt)
{
	_sprite.move(_movementSpeed * x * dt, _movementSpeed * y * dt);
}

void Tank::turn(float angle, float dt)
{
	_sprite.rotate(angle * dt);
}

void Tank::turnLeft(const float dt)
{
	turn(_angle, dt);
}

void Tank::turnRight(const float dt)
{
	turn(-_angle, dt);
}

void Tank::moveUp(const float dt)
{
	move(direct_.x, -direct_.y, dt);
}

void Tank::moveDown(const float dt)
{
	move(-direct_.x, direct_.y, dt);
}
