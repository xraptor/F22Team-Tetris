#include "essential.hpp"

Scene::Scene(sf::RenderWindow& window) :
_sceneView(window.getDefaultView()),
_window(window),
_grille(20, 20, 200, 400)
{
}

Grille& Scene::getGrille() {
    return _grille;
}

void Scene::draw()
{
    _grille.draw(_window);
}

sf::Vector2f Scene::getCenter()
{
	return _sceneView.getCenter();
}

void Scene::handleEvent(const sf::Event& evt)
{
    _grille.handleEvent(evt);
}

void Scene::update(sf::Time& tau)
{
    _grille.update();
}
