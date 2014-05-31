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

        //Scene& _scene;
        //Vector2f& _taille_block;
        //vector<Block> _tBlock;
        unsigned int _col;
        unsigned int _row;
        vector<vector<bool> > _motif;
        sf::Color _color;
        RegEvent _event;

        //sf::Vector2f _minp;
        //sf::Vector2f _maxp;

        //bool _etat;
        //Block &_bb;

    public:
        //Constructeur & destructeur
        Piece(unsigned int col, unsigned int row, vector<vector<bool> > &tBool, sf::Color &color);
        ~Piece(){};

        unsigned int getRow();
        unsigned int getCol();
        vector<vector<bool> >& getMotif();
        sf::Color& getColor();

        void setCol(unsigned int col);
        void setRow(unsigned int row);
        /*bool estBloque();
        void hcenter();
        void vcenter();
        float wSize();
        float hSize();
        void moveX(int x);
        void moveY(int y);
        void genBounds();
        Piece rotationAntiHoraire();
        Piece rotationHoraire();
        Vector2f& getMinP();
        Vector2f& getMaxP();
        void setEtat(bool b);
		//Etat initial
		void init();*/

		//Gestiondesevenements
		//void handleEvent(const sf::Event &evt);

		//Miseajour
		//void update(sf::Time& tau);

		//Rendu
		//void draw(sf::RenderWindow& renderer);

		//Piece& operator=(const Piece &p);

		//vector<Block> getTBlock() const;
		//sf::Color getColor() const;
};

#endif
