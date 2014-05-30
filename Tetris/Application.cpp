#include "essential.hpp"

Application::Application() :
_scene(_window),
_window(sf::VideoMode(400, 800), "Tetris Raptor")
{
}

void Application::run()
{
	sf::Clock clock;
	while (_window.isOpen())
	{
		sf::Time tau = clock.restart();
		processEvents(); // quand on appui sur une touche etc...
		update(tau);
		render();
	}
}


void Application::processEvents()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		_scene.handleEvent(event);

		if (event.type == sf::Event::Closed)
			_window.close();
	}

}

void Application::update(sf::Time& tau)
{
	_scene.update(tau);
}

void Application::render()
{
	_window.clear();
	_scene.draw();
	_window.display();
}
