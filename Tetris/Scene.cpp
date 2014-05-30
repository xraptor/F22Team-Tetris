#include "essential.hpp"

Scene::Scene(sf::RenderWindow& window) :
_sceneView(window.getDefaultView()),
_window(window),
_mp(MotifPiece()),
_taille_block(Vector2f(0,0))
{
    defBlockSize();
    genColors();

    _tPiece.push_back(Piece(getMiddleHPiece(), 0, _mp.getPiece(), rndColor(), _taille_block, *this));
    _tPiece[_tPiece.size()-1].hcenter();
    _current = _tPiece.size()-1;
}

float Scene::getMiddleHPiece() {
    float mxblock = _taille_block.x + Config::PAS_BLOCK_X + Config::TAILLE_BORDURE*2;
    return ((int)getCenter().x/(int)mxblock) * mxblock;
}

void Scene::defBlockSize() {

    _taille_block.x = _window.getSize().x / Config::NB_COL_GAME -
                          (2*Config::TAILLE_BORDURE + Config::PAS_BLOCK_X
                           - Config::PAS_BLOCK_X / Config::NB_COL_GAME);

    _taille_block.y = _window.getSize().y / Config::NB_ROW_GAME -
                          (2*Config::TAILLE_BORDURE + Config::PAS_BLOCK_Y
                           - Config::PAS_BLOCK_Y / Config::NB_ROW_GAME);
}

sf::Color& Scene::rndColor() {
    return _couleurs[Utils::rndInt(_couleurs.size())];
}

void Scene::genColors() {
    _couleurs.push_back(sf::Color::Blue);
    _couleurs.push_back(sf::Color::Green);
    _couleurs.push_back(sf::Color::Red);
    _couleurs.push_back(sf::Color::Yellow);
    _couleurs.push_back(sf::Color(128,0,0)); //Marron
    _couleurs.push_back(sf::Color(102,0,204)); //Violet
}

void Scene::draw()
{
    for(int i = 0; i < _tPiece.size(); ++i) {
        _tPiece[i].draw(_window);
    }
}

sf::Vector2f Scene::getCenter()
{
	return _sceneView.getCenter();
}

void Scene::handleEvent(const sf::Event& evt)
{
    _tPiece[_current].handleEvent(evt);
}

void Scene::update(sf::Time& tau)
{
    for(int i = 0; i < _tPiece.size(); ++i) {
        _tPiece[i].update(tau);
    }
}

unsigned int Scene::getCurrent() const
{
    return _current;
}

vector<Piece>& Scene::getTPiece()
{
    return _tPiece;
}
