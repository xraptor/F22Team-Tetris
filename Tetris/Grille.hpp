#ifndef _GRILLE_HPP_
#define _GRILLE_HPP_

#include "essential.hpp"

class Piece;

class Grille{

    enum RegEvent {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        NONE
    };

    private:
        MotifPiece _mp;
        vector<sf::Color> _couleurs;

        unsigned int _type[Config::NB_ROW_GAME][Config::NB_COL_GAME];
        sf::RectangleShape _tBlock[Config::NB_ROW_GAME][Config::NB_COL_GAME];
        RegEvent _event;
        Piece *_pieceCourante;

    public:
        Grille(float x, float y, float w, float h);
        //~Grille(){};

        sf::Color& rndColor();
        void genColors();
        void ajouterPiece(unsigned int col, unsigned int row, vector<vector<bool> > tBool, sf::Color &color);
        void moveDown();

        void draw(sf::RenderWindow& window);
        void handleEvent(const Event& evt);
        void update();
};

#endif // _GRILLE_HPP_
