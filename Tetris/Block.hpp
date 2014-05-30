#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "essential.hpp"

class Block {
    private:
        Vector2f &_taille_block;
        sf::RectangleShape _block;

    public:
        Block(float x, float y, sf::Color &c, Vector2f &taille_block);
        //~Block(){};

        float getX();

        float getY();

        RectangleShape& getBlock();

        void afficher();

        friend ostream& operator <<(ostream& output, Block& b);
};

#endif
