//
// Created by Daniel on 16.03.2023.
//

#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <vector>

#include "SFML/Graphics.hpp"

enum Ground
{
	Earth1,
	Earth2,
	Earth3,
	Earth4,
	Water1,
	Water2,
	Water3,
	Water4,
	Water5,
	Water6,
	Water7,
	Water8,
	Send,
};

enum Wall
{
	Red,
	Green,
	Yellow,
	Blue
};

class BackGround
{
private:
	std::vector<std::vector<char>> MAP = {
		{Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Ground::Earth1,Ground::Earth1, Wall::Blue},
		{Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue,Wall::Blue, Wall::Blue},


	};

	sf::Image _mapImage;
	sf::Texture _mapTexture;
	sf::Sprite _mapSprite;

public:
	BackGround();

	void render(sf::RenderWindow* target);
};

#endif //_BACKGROUND_H_
