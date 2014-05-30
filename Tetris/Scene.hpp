#ifndef _SCENE_H_
#define _SCENE_H_

#include "essential.hpp"

class Scene{
private:
	// Graphique
	sf::View				_sceneView;
	sf::RenderWindow&		_window;

	// Logique
	MotifPiece              _mp;
	vector<Piece>           _tPiece;
	vector<sf::Color>       _couleurs;
	unsigned int            _current;
	sf::Vector2f            _taille_block;
	//Block                   *_bb;

	//sf::Vector2f            _size;
	//Color                   _c;
	//Observer				_observer;

public:
	// Constructeur & destructeur
	Scene(sf::RenderWindow& window);
	~Scene(){};

	// Requêtes graphiques
	sf::Vector2f getCenter();

	// Gestion des événements
	void handleEvent(const sf::Event& evt);

	// Mise à jour
	void update(sf::Time& tau);

	// Rendu
	void draw();

    sf::Color& rndColor();
	void genColors();
	unsigned int getCurrent() const;
	vector<Piece>& getTPiece();
	void defBlockSize();
	float getMiddleHPiece();
};

#endif
