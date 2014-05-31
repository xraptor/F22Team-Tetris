#include "essential.hpp"

Piece::Piece(unsigned int col, unsigned int row, vector<vector<bool> > &tBool, sf::Color &color) :
_col(col), _row(row), _motif(tBool), _color(color), _event(NONE)
{
    //_scene.getGrille().ajouterPiece(col, row, tBool, color);
}

void Piece::setCol(unsigned int col) {
    _row = col;
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
/*
Vector2f& Piece::getMinP() {
    return _minp;
}

Vector2f& Piece::getMaxP() {
    return _maxp;
}

Piece Piece::rotationAntiHoraire() {
    vector<vector<bool> > tBool(_motif[0].size(), vector<bool>(_motif.size(), false));

    for(int i = 0; i < _motif.size(); ++i) {
        for(int j = 0; j < _motif[i].size(); ++j) {
            if(_motif[i][j]) {
                tBool[_motif[0].size()-1-j][i] = _motif[i][j];
            }
        }
    }

    for(int i = 0; i < tBool.size(); ++i) {
        for(int j = 0; j < tBool[i].size(); ++j) {
            if(tBool[i][j]) {
                cout << "x";
            } else {
                cout << " ";
            }
        }
        if(i < tBool.size()-1) {
            cout << endl;
        }
    }
    cout << endl << endl;;

    _motif.clear();
    _motif = tBool;

    return Piece(_minp.x, _minp.y, _motif, _scene.rndColor(), _taille_block, _scene);
}

Piece Piece::rotationHoraire() {

    vector<vector<bool> > tBool(_motif[0].size(), vector<bool>(_motif.size(), false));

    for(int i = 0; i < _motif.size(); ++i) {
        for(int j = 0; j < _motif[i].size(); ++j) {
            if(_motif[i][j]) {
                tBool[j][_motif.size()-1-i] = _motif[i][j];
            }
        }
    }

    for(int i = 0; i < tBool.size(); ++i) {
        for(int j = 0; j < tBool[i].size(); ++j) {
            if(tBool[i][j]) {
                cout << "x";
            } else {
                cout << " ";
            }
        }
        if(i < tBool.size()-1) {
            cout << endl;
        }
    }
    cout << endl << endl;;

    _motif.clear();
    _motif = tBool;

    return Piece(_minp.x, _minp.y, _motif, _scene.rndColor(), _taille_block, _scene);

}

void Piece::hcenter() {

    float mxblock = _taille_block.x + Config::PAS_BLOCK_X + Config::TAILLE_BORDURE*2;
    float xdecal = (int)((wSize()/2)/mxblock) * mxblock;
    cout << xdecal << endl;

    for(int i = 0; i < _tBlock.size(); ++i) {
        _tBlock[i].getBlock().setPosition(_tBlock[i].getX() - xdecal,
                               _tBlock[i].getY());
    }

    _minp.x -= xdecal;
    _maxp.x -= xdecal;
}

void Piece::vcenter() {
    float ydecal = hSize()/2;

    for(int i = 0; i < _tBlock.size(); ++i) {
        _tBlock[i].getBlock().setPosition(_tBlock[i].getX(),
                               _tBlock[i].getY() - ydecal);
    }

    _minp.y -= ydecal;
    _maxp.y -= ydecal;
}

void Piece::genBounds() {

        float minb = 0;
        float maxb = 0;

        for(int i = 1; i < _tBlock.size(); ++i) {
            if(_tBlock[i].getX() < _tBlock[minb].getX()) {
                minb = i;
            }
            else if(_tBlock[i].getX() > _tBlock[maxb].getX()) {
                maxb = i;
            }
        }

        _minp.x = _tBlock[minb].getX();
        _maxp.x = _tBlock[maxb].getX();

        minb = 0;
        maxb = 0;

        for(int i = 1; i < _tBlock.size(); ++i) {
            if(_tBlock[i].getY() < _tBlock[minb].getY()) {
                minb = i;
            }
            else if(_tBlock[i].getY() > _tBlock[maxb].getY()) {
                maxb = i;
            }
        }

        _minp.y = _tBlock[minb].getY();
        _maxp.y = _tBlock[maxb].getY();

}

float Piece::wSize() {
    return _maxp.x - _minp.x + _taille_block.x + Config::TAILLE_BORDURE*2;
}

float Piece::hSize() {
    return _maxp.y - _minp.y + _taille_block.y + Config::TAILLE_BORDURE*2;
}

void Piece::moveX(int x) {

    for(int i = 0; i < _tBlock.size(); ++i) {
        _tBlock[i].getBlock().setPosition(_tBlock[i].getX() + ((float)x * (_taille_block.x + Config::TAILLE_BORDURE*2 + Config::PAS_BLOCK_X)),
        _tBlock[i].getY());
    }

    _minp.x += (float)x * (_taille_block.x + Config::TAILLE_BORDURE*2 + Config::PAS_BLOCK_X);
    _maxp.x += (float)x * (_taille_block.x + Config::TAILLE_BORDURE*2 + Config::PAS_BLOCK_X);
}

void Piece::moveY(int y) {
    for(int i = 0; i < _tBlock.size(); ++i) {
        _tBlock[i].getBlock().setPosition(_tBlock[i].getX(),
        _tBlock[i].getY() + ((float)y * (_taille_block.y + Config::TAILLE_BORDURE*2 + Config::PAS_BLOCK_Y)));
    }

    _minp.y += (float)y * (_taille_block.y + Config::TAILLE_BORDURE*2 + Config::PAS_BLOCK_Y);
    _maxp.y += (float)y * (_taille_block.y + Config::TAILLE_BORDURE*2 + Config::PAS_BLOCK_Y);
}

bool Piece::estBloque() {
    switch(_event) {
        case LEFT:
            if(_minp.x <= Config::TAILLE_BORDURE) {
                return true;
            }
            break;
        case RIGHT:
            if(_maxp.x + _taille_block.x + Config::PAS_BLOCK_X + Config::TAILLE_BORDURE*2 >= _scene.getCenter().x*2) {
                return true;
            }
            break;
        case UP:
            if(_minp.y <= Config::TAILLE_BORDURE) {
                return true;
            }
            break;
        case DOWN:
            if(_maxp.y + _taille_block.y + Config::PAS_BLOCK_Y + Config::TAILLE_BORDURE*2 >= _scene.getCenter().y*2) {
                return true;
            }
            break;
    }

    return false;
}
*/
/*
void Piece::draw(sf::RenderWindow& renderer) {

    for(int i = 0; i < _tBlock.size(); ++i) {
        renderer.draw(_tBlock[i].getBlock());
    }

}
*/
/*
void Piece::handleEvent(const sf::Event &evt) {
    if(evt.type == sf::Event::KeyPressed) {
        switch(evt.key.code) {
            case sf::Keyboard::Left:
                _event = LEFT;
                break;
            case sf::Keyboard::Right:
                _event = RIGHT;
                break;
            case sf::Keyboard::Up:
                _event = UP;
                break;
            case sf::Keyboard::Down:
                _event = DOWN;
                break;
        }
    }
}

void Piece::update(sf::Time &tau) {
    switch(_event) {
        case LEFT:
            if(estBloque()) {
                cout << "bloque" << endl;
            } else {
                cout << "pas bloque" << endl;
                moveX(-1);
                cout << _minp.x << endl;
            }
            cout << "left" << endl;
            break;
        case RIGHT:
            if(estBloque()) {
                cout << "bloque" << endl;
            } else {
                cout << "pas bloque" << endl;
                moveX(1);
                cout << _maxp.x << endl;
            }
            cout << "right" << endl;
            break;
        case UP:
            if(estBloque()) {
                cout << "bloque" << endl;
            } else {
                cout << "pas bloque" << endl;
                moveY(-1);
                cout << _minp.y << endl;
            }
            cout << "up" << endl;
            break;
        case DOWN:
            if(estBloque()) {
                cout << "bloque" << endl;
            } else {
                cout << "pas bloque" << endl;
                moveY(1);
                cout << _maxp.y << endl;
            }
            cout << "down" << endl;
            break;
    }

    _event = NONE;
}

vector<Block> Piece::getTBlock() const {
    return _tBlock;
}

sf::Color Piece::getColor() const {
    return _color;
}

void Piece::setEtat(bool b) {
    _etat = b;
}
*/
