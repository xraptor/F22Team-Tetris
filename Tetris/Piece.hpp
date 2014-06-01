#ifndef _PIECE_H_
#define _PIECE_H_

#include "essential.hpp"


class Scene;

class Piece {
    private:
        enum RegEvent{
            LEFT,
            RIGHT,
            UP,
            DOWN,
            NONE
        };

        // Logique
        unsigned int                _col;
        unsigned int                _row;
        vector<vector<bool> >       _motif;
        RegEvent                    _event;

        // Graphique
        sf::Color                   _color;

    public:
        //Constructeur & destructeur
        Piece(unsigned int col, unsigned int row, vector<vector<bool> > &tBool, sf::Color &color);
        ~Piece(){};

        // Getter
        unsigned int getRow();
        unsigned int getCol();
        vector<vector<bool> >& getMotif();
        sf::Color& getColor();

        // Setter
        void setCol(unsigned int col);
        void setRow(unsigned int row);
};

#endif
