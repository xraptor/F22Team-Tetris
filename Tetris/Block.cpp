#include "essential.hpp"

Block::Block(float x, float y, sf::Color &c, Vector2f &taille_block) :
_taille_block(taille_block)
{
    _block.setPosition(x, y);
    _block.setSize(Vector2f(_taille_block.x, _taille_block.y));
    _block.setFillColor(c);
    _block.setOutlineThickness(Config::TAILLE_BORDURE);
    _block.setOutlineColor(sf::Color::White);
}

float Block::getX() {
    return _block.getPosition().x;
}

float Block::getY() {
    return _block.getPosition().y;
}

RectangleShape& Block::getBlock() {
    return _block;
}

void Block::afficher() {
    cout << *this << endl;
}

ostream& operator <<(ostream& output, Block& b) {
    output << "(x : " << b.getX() << ", y : " << b.getY() << ")";
    return output;
}
