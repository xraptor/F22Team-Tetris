#include "essential.hpp"

Piece::Piece(unsigned int col, unsigned int row, vector<vector<bool> > &tBool, sf::Color &color) :
_col(col), _row(row), _motif(tBool), _color(color), _event(NONE)
{
}

void Piece::setCol(unsigned int col) {
    _col = col;
}

void Piece::setRow(unsigned int row) {
    _row = row;
}

unsigned int Piece::getCol() {
    return _col;
}

unsigned int Piece::getRow() {
    return _row;
}

vector<vector<bool> >& Piece::getMotif() {
    return _motif;
}

sf::Color& Piece::getColor() {
    return _color;
}
