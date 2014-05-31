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
    vector<vector<bool> > tmpMotif = _mp.getPiece();
    ajouterPiece(0, 0, tmpMotif, rndColor());
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

void Grille::ajouterPiece(unsigned int col, unsigned int row, vector<vector<bool> > &tBool, sf::Color &color) {

    if(_pieceCourante == nullptr) {
        _pieceCourante = new Piece(col, row, tBool, color);
    }

    if(col + tBool[0].size()-1 >= Config::NB_COL_GAME) {
        col -= (col + tBool[0].size()-1) - (Config::NB_COL_GAME-1);
        _pieceCourante->setCol(col);
    }

    if(row + tBool.size()-1 >= Config::NB_ROW_GAME) {
        row -= (row + tBool.size()-1) - (Config::NB_ROW_GAME-1);
        _pieceCourante->setRow(row);
    }

    for(int i = 0; i < tBool.size(); ++i) {
        for(int j = 0; j < tBool[i].size(); ++j) {
            if(tBool[i][j]) {
                _tBlock[row+i][col+j].setFillColor(color);
            }
        }
    }

}

void Grille::rotationAntiHoraire() {
    vector<vector<bool> > tBool(_pieceCourante->getMotif()[0].size(), vector<bool>(_pieceCourante->getMotif().size(), false));

    for(int i = 0; i < _pieceCourante->getMotif().size(); ++i) {
        for(int j = 0; j < _pieceCourante->getMotif()[i].size(); ++j) {
            if(_pieceCourante->getMotif()[i][j]) {
                tBool[_pieceCourante->getMotif()[0].size()-1-j][i] = _pieceCourante->getMotif()[i][j];
            }
        }
    }

    erasePiece();

    _pieceCourante->getMotif().clear();
    _pieceCourante->getMotif() = tBool;

    ajouterPiece(_pieceCourante->getCol(), _pieceCourante->getRow(), _pieceCourante->getMotif(), _pieceCourante->getColor());
}

void Grille::rotationHoraire() {
    vector<vector<bool> > tBool(_pieceCourante->getMotif()[0].size(), vector<bool>(_pieceCourante->getMotif().size(), false));

    for(int i = 0; i < _pieceCourante->getMotif().size(); ++i) {
        for(int j = 0; j < _pieceCourante->getMotif()[i].size(); ++j) {
            if(_pieceCourante->getMotif()[i][j]) {
                tBool[j][_pieceCourante->getMotif().size()-1-i] = _pieceCourante->getMotif()[i][j];
            }
        }
    }

    erasePiece();

    _pieceCourante->getMotif().clear();
    _pieceCourante->getMotif() = tBool;

    ajouterPiece(_pieceCourante->getCol(), _pieceCourante->getRow(), _pieceCourante->getMotif(), _pieceCourante->getColor());
}

void Grille::erasePiece() {
    for(int i = 0; i < _pieceCourante->getMotif().size(); ++i) {
        for(int j = 0; j < _pieceCourante->getMotif()[i].size(); ++j) {
            if(_pieceCourante->getMotif()[i][j]) {
                _tBlock[_pieceCourante->getRow()+i][_pieceCourante->getCol()+j].setFillColor(sf::Color::White);
            }
        }
    }
}

void Grille::moveLeft() {
    if(_pieceCourante->getCol() > 0) {
        erasePiece();

        _pieceCourante->setCol(_pieceCourante->getCol()-1);
        ajouterPiece(_pieceCourante->getCol(), _pieceCourante->getRow(), _pieceCourante->getMotif(), _pieceCourante->getColor());
    }
}

void Grille::moveRight() {
    if(_pieceCourante->getCol() + _pieceCourante->getMotif()[0].size() < Config::NB_COL_GAME) {
        erasePiece();

        _pieceCourante->setCol(_pieceCourante->getCol()+1);
        ajouterPiece(_pieceCourante->getCol(), _pieceCourante->getRow(), _pieceCourante->getMotif(), _pieceCourante->getColor());
    }
}

void Grille::moveUp() {
    if(_pieceCourante->getRow() > 0) {
        erasePiece();

        _pieceCourante->setRow(_pieceCourante->getRow()-1);
        ajouterPiece(_pieceCourante->getCol(), _pieceCourante->getRow(), _pieceCourante->getMotif(), _pieceCourante->getColor());
    }
}

void Grille::moveDown() {
    if(_pieceCourante->getRow() + _pieceCourante->getMotif().size() < Config::NB_ROW_GAME) {
        erasePiece();

        _pieceCourante->setRow(_pieceCourante->getRow()+1);
        ajouterPiece(_pieceCourante->getCol(), _pieceCourante->getRow(), _pieceCourante->getMotif(), _pieceCourante->getColor());

        if(_pieceCourante->getRow() + _pieceCourante->getMotif().size() == Config::NB_ROW_GAME) {
            delete _pieceCourante;
            _pieceCourante = nullptr;

            vector<vector<bool> > tmpMotif = _mp.getPiece();
            ajouterPiece(0, 0, tmpMotif, rndColor());
        } else {
            isStuck();
        }
    }
}

void Grille::isStuck() {

    for(int i = 0; i < _pieceCourante->getMotif()[0].size()-1; ++i) {
        for(int j = _pieceCourante->getMotif().size()-1; j >= 0; --j) {
            if(_pieceCourante->getMotif()[j][i]) {

                sf::Color bc = _tBlock[_pieceCourante->getRow()+j+1][_pieceCourante->getCol()+i].getFillColor();

                if(!(bc.r == Config::DEFAULT_BLOCK_COLOR.r
                   && bc.g == Config::DEFAULT_BLOCK_COLOR.g
                   && bc.b == Config::DEFAULT_BLOCK_COLOR.b)) {

                    delete _pieceCourante;
                    _pieceCourante = nullptr;

                    vector<vector<bool> > tmpMotif = _mp.getPiece();
                    ajouterPiece(0, 0, tmpMotif, rndColor());
                } else {
                    j = -1;
                }
            }
        }
    }

}

void Grille::draw(sf::RenderWindow& window) {
    for(int i = 0; i < Config::NB_ROW_GAME; ++i) {
        for(int j = 0; j < Config::NB_COL_GAME; ++j) {
            window.draw(_tBlock[i][j]);
        }
    }
}

void Grille::handleEvent(const Event& evt) {
    if(evt.type == sf::Event::KeyPressed) {
        switch(evt.key.code) {
            case sf::Keyboard::Left:
                _event = KEY_LEFT;
                break;

            case sf::Keyboard::Right:
                _event = KEY_RIGHT;
                break;

            case sf::Keyboard::Up:
                _event = KEY_UP;
                break;

            case sf::Keyboard::Down:
                _event = KEY_DOWN;
                break;
        }
    } else if(evt.type == sf::Event::MouseButtonPressed) {
        switch(evt.mouseButton.button) {
            case sf::Mouse::Left:
                _event = MOUSE_LEFT;
                break;

            case sf::Mouse::Right:
                _event = MOUSE_RIGHT;
                break;
        }
    }
}

void Grille::update() {
    switch(_event) {
        case KEY_LEFT:
            moveLeft();
            break;

        case KEY_RIGHT:
            moveRight();
            break;

        case KEY_UP:
            moveUp();
            break;

        case KEY_DOWN:
            moveDown();
            break;

        case MOUSE_LEFT:
            rotationAntiHoraire();
            break;

        case MOUSE_RIGHT:
            rotationHoraire();
            break;
    }
    _event = NONE;
}
