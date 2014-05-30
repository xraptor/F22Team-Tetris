#include "essential.hpp"

Piece::Piece(float x, float y, vector<vector<bool> > tBool, sf::Color &c, sf::Vector2f &taille_block, Scene &scene) :
_color(c), _minp(Vector2f(0,0)), _maxp(Vector2f(0,0)), _taille_block(taille_block), _scene(scene), _event(NONE)
{
    for(int i = 0; i < tBool.size(); ++i) {
        for(int j = 0; j < tBool[i].size(); ++j) {
            if(tBool[i][j]) {
                _tBlock.push_back(Block(x + Config::TAILLE_BORDURE + (_taille_block.x + Config::TAILLE_BORDURE*2 + Config::PAS_BLOCK_X) * j,
                                        y + Config::TAILLE_BORDURE + (_taille_block.y + Config::TAILLE_BORDURE*2 + Config::PAS_BLOCK_Y) * i,
                                        _color,
                                        _taille_block));
            }
        }
    }

    genBounds();
    //_tBlock[0].afficher();
    //_tBlock[0].getBlock().setPosition(_tBlock[0].getBlock().getPosition().x, 200);
}

void Piece::rotation() {
    float ox = _minp.x + wSize()/2;
    float oy = _minp.y + hSize()/2;
    float x, y;

    for(int i = 0; i < _tBlock.size(); ++i) {
        x = _tBlock[i].getX() - ox;
        y = _tBlock[i].getY() - oy;
        _tBlock[i].getBlock().setPosition((cos(Config::DEGRE)*x - sin(Config::DEGRE)*y) + ox,
                                          (sin(Config::DEGRE)*x + cos(Config::DEGRE)*y) + oy);
    }
}

void Piece::hcenter() {
    //float tmp = wSize()/2;
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

        //cout << "_minp.y : " << _minp.y << endl;
        //cout << "_maxp.y : " << _maxp.y << endl;
        //cout << "_minp.x : " << _minp.x << endl;
        //cout << "_maxp.x : " << _maxp.x << endl;
}

float Piece::wSize() {
    //cout << _maxp.x - _minp.x + _taille_block.x + Config::TAILLE_BORDURE*2 << endl;
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

void Piece::draw(sf::RenderWindow& renderer) {

    for(int i = 0; i < _tBlock.size(); ++i) {
        renderer.draw(_tBlock[i].getBlock());
    }

}

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
    } else if(evt.type == sf::Event::MouseButtonPressed) {
        switch(evt.mouseButton.button) {
            case sf::Mouse::Right:
                rotation();
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

/*Piece& Piece::operator=(const Piece &p) {
    _tBlock = p.getTBlock();
    _color = p.getColor();
    return *this;
}*/

vector<Block> Piece::getTBlock() const {
    return _tBlock;
}

sf::Color Piece::getColor() const {
    return _color;
}
