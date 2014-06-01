#ifndef _SCENE_H_
#define _SCENE_H_

#include "essential.hpp"

class Scene{
private:
	// Graphique
	sf::View                _sceneView;
	sf::RenderWindow&		_window;

	Grille                  _grille;

	// Logique

public:
	// Constructeur & destructeur
	Scene(sf::RenderWindow& window);
	~Scene(){};

    // Retourne la grille du tetris.
    Grille& getGrille();

	// Requ�tes graphiques
	sf::Vector2f getCenter();

	// Gestion des �v�nements
	void handleEvent(const sf::Event& evt);

	// Mise � jour
	void update(sf::Time& tau);

	// Rendu
    void draw();
};

#endif
