#include "essential.hpp"

Grille::Grille(float x, float y, float w, float h) {
    float bw = w / Config::NB_COL_GAME;
    float bh = h / Config::NB_ROW_GAME;

    for(int i = 0; i < Config::NB_ROW_GAME; ++i) {
        for(int j = 0; j < Config::NB_COL_GAME; ++j) {
            _tBlock[i][j].setPosition(x + bw*j, y + bh*i);
            _tBlock[i][j].setSize(Vector2f(bw, bh));
        }
    }
}

void Grille::ajouterPiece(unsigned int col, unsigned int row, vector<vector<bool> > &tBool, sf::Color &color) {
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

void Grille::draw(sf::RenderWindow& window) {
    for(int i = 0; i < Config::NB_ROW_GAME; ++i) {
        for(int j = 0; j < Config::NB_COL_GAME; ++j) {
            window.draw(_tBlock[i][j]);
            cout << "r: " << (int)(_tBlock[i][j].getFillColor().r) << endl;
        }
    }
}
