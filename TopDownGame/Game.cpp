//
// Created by Daniel on 09.03.2023.
//

#include "Game.h"

Game* Game::_instance = nullptr;

Game::Game()
{
	_window = new sf::RenderWindow(_videoMode, TITLE, sf::Style::Close);
	_window->setFramerateLimit(FPS);
	_window->setVerticalSyncEnabled(true);

	_bg = new BackGround();
	_t1 = new Tank(YellowBlack, sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::W, sf::Keyboard::Key::S);

	_t2 = new Tank(RedBlack, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Up,
	               sf::Keyboard::Key::Down);

	_t1->setPositionSprite(_videoMode.width / 2.f, _videoMode.height / 2.f);
	_t2->setPositionSprite(_videoMode.width / 4.f, _videoMode.height / 4.f);

	collisionPlayer1AndBorderMap = CollisionPlayerWithBorderMap(
		_t1, sf::FloatRect(79, 79, _videoMode.width - 79 * 2, _videoMode.height - 79 * 2));
	collisionPlayer2AndBorderMap = CollisionPlayerWithBorderMap(
		_t2, sf::FloatRect(79, 79, _videoMode.width - 79 * 2, _videoMode.height - 79 * 2));

	inputController_ = new TwoPlayerInputController(_t1, _t2);
}

void Game::run()
{
	while (_window->isOpen())
	{
		updateDeltaTime();
		update();
		render();
	}
}

void Game::update()
{
	_t1->update();
	_t2->update();
	collisionPlayer1AndBorderMap.update();
	collisionPlayer2AndBorderMap.update();
	updateEvents();

	if (!_states.empty())
	{
		_states.top()->update();

		if (!_window->hasFocus())
		{
			if (_states.top()->isQuit())
			{
				_states.top()->end();
				delete _states.top();
				_states.pop();
			}
		}
	}
}


void Game::updateEvents()
{
	sf::Event ev;
	while (_window->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			_window->close();
		}
	}

	// Движение персонажей
	inputController_->keysProcessing(_deltaTime);
}

void Game::updateDeltaTime()
{
	_deltaTime = _deltaClock.restart().asSeconds() / 700;
}

void Game::render()
{
	_window->clear();
	_bg->render(_window);
	_t1->render(_window);
	_t2->render(_window);

	if (!_states.empty())
	{
		_states.top()->render();
	}

	_window->display();
}

Game* Game::instance()
{
	if (_instance == nullptr)
		_instance = new Game();
	return _instance;
}

Game::~Game()
{
	delete _instance;
	delete _t1;
	delete _t2;
	delete _bg;
}
