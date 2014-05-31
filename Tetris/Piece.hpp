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

        Scene& _scene;
        //Vector2f& _taille_block;
        //vector<Block> _tBlock;
        sf::Color _color;
        RegEvent _event;

        //sf::Vector2f _minp;
        //sf::Vector2f _maxp;

        vector<vector<bool> > _currentPattern;
        //bool _etat;
        //Block &_bb;

    public:
        //Constructeur & destructeur
        Piece(unsigned int col, unsigned int row, vector<vector<bool> > tBool, sf::Color &color, Scene &scene);
        ~Piece(){};

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
