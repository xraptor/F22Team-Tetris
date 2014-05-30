#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

#include "essential.hpp"

class Application
{
	// Graphique
	sf::RenderWindow		_window;

	// Logique
	Scene					_scene;

public:
	Application();
	void run();

protected:
	// Boucle événementielle
	void processEvents();
	void update(sf::Time& delta);
	void render();
};

#endif
