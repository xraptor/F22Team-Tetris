#ifndef _GRILLE_HPP_
#define _GRILLE_HPP_

class Grille{
    private:
        unsigned int _type[Config::NB_ROW_GAME][Config::NB_COL_GAME];
        sf::RectangleShape _tBlock[Config::NB_ROW_GAME][Config::NB_COL_GAME];

    public:
        Grille(float x, float y, float w, float h);
        //~Grille(){};

        void ajouterPiece(unsigned int col, unsigned int row, vector<vector<bool> > &tBool, sf::Color &color);

        void draw(sf::RenderWindow& window);
};

#endif // _GRILLE_HPP_
