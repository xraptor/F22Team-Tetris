#ifndef _GRILLE_HPP_
#define _GRILLE_HPP_

#include "essential.hpp"

class Piece;

class Grille{

    enum RegEvent {
        KEY_LEFT,
        KEY_RIGHT,
        KEY_UP,
        KEY_DOWN,
        MOUSE_LEFT,
        MOUSE_RIGHT,
        NONE
    };

    private:
        MotifPiece _mp;
        vector<sf::Color> _couleurs;

        //unsigned int _type[Config::NB_ROW_GAME][Config::NB_COL_GAME];
        sf::RectangleShape _tBlock[Config::NB_ROW_GAME][Config::NB_COL_GAME];
        RegEvent _event;
        Piece *_pieceCourante;

    public:
        Grille(float x, float y, float w, float h);
        //~Grille(){};

        sf::Color& rndColor();
        void genColors();
        void ajouterPiece(unsigned int col, unsigned int row, vector<vector<bool> > &tBool, sf::Color &color);
        void erasePiece();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void rotationAntiHoraire();
        void rotationHoraire();
        void isStuck();

        void draw(sf::RenderWindow& window);
        void handleEvent(const Event& evt);
        void update();
};

#endif // _GRILLE_HPP_
