#include "essential.hpp"

Grille::Grille(float x, float y, float w, float h) :
_mp(), _event(NONE)
{
    _pieceCourante = nullptr;

    float bw = w / Config::NB_COL_GAME;
    float bh = h / Config::NB_ROW_GAME;

    for(int i = 0; i < Config::NB_ROW_GAME; ++i) {
        for(int j = 0; j < Config::NB_COL_GAME; ++j) {
            _tBlock[i][j].setPosition(x + bw*j, y + bh*i);
            _tBlock[i][j].setSize(Vector2f(bw, bh));
        }
    }

    genColors();

    ajouterPiece(0, 0, _mp.getPiece(), rndColor());
}

sf::Color& Grille::rndColor() {
    return _couleurs[Utils::rndInt(_couleurs.size())];
}

void Grille::genColors() {
    _couleurs.push_back(sf::Color::Blue);
    _couleurs.push_back(sf::Color::Green);
    _couleurs.push_back(sf::Color::Red);
    _couleurs.push_back(sf::Color::Yellow);
    _couleurs.push_back(sf::Color(128,0,0)); //Marron
    _couleurs.push_back(sf::Color(102,0,204)); //Violet
}

void Grille::ajouterPiece(unsigned int col, unsigned int row, vector<vector<bool> > tBool, sf::Color &color) {

    if(_pieceCourante == nullptr) {
        _pieceCourante = new Piece(col, row, tBool, color);
    }

    if((col - Config::NB_COL_GAME) >= tBool[0].size() && (row - Config::NB_ROW_GAME) >= tBool.size()) {
        for(int i = 0; i < tBool.size(); ++i) {
            for(int j = 0; j < tBool[i].size(); ++j) {
                if(tBool[i][j]) {
                    _tBlock[row+i][col+j].setFillColor(color);
                }
            }
        }
    } else {
        cerr << "Vous n'avez pas specifie une position adequate !" << endl;
        exit(1);
    }
}

void Grille::moveDown() {
    for(int i = 0; i < _pieceCourante->getMotif().size(); ++i) {
        for(int j = 0; j < _pieceCourante->getMotif()[i].size(); ++j) {
            if(_pieceCourante->getMotif()[i][j]) {
                _tBlock[_pieceCourante->getRow()+i][_pieceCourante->getCol()+j].setFillColor(sf::Color::White);
            }
        }
    }

    _pieceCourante->setRow(_pieceCourante->getRow()+1);
    ajouterPiece(_pieceCourante->getCol(), _pieceCourante->getRow(), _pieceCourante->getMotif(), _pieceCourante->getColor());
}

void Grille::draw(sf::RenderWindow& window) {
    for(int i = 0; i < Config::NB_ROW_GAME; ++i) {
        for(int j = 0; j < Config::NB_COL_GAME; ++j) {
            window.draw(_tBlock[i][j]);
            //cout << "r: " << (int)(_tBlock[i][j].getFillColor().r) << endl;
        }
    }
}

void Grille::handleEvent(const Event& evt) {
    if(evt.type == sf::Event::KeyPressed) {
        switch(evt.key.code) {
            case sf::Keyboard::Down:
                _event = DOWN;
                break;
        }
    }
}

void Grille::update() {
    switch(_event) {
        case DOWN:
            cout << "down" << endl;
            moveDown();
            break;
    }
    _event = NONE;
}
