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
        // Logique
        MotifPiece _mp;
        unsigned int _type[Config::NB_ROW_GAME][Config::NB_COL_GAME]; // Non utilisé pour l'instant.
        RegEvent _event;
        Piece *_pieceCourante;

        // Graphique
        vector<sf::Color> _couleurs;
        sf::RectangleShape _tBlock[Config::NB_ROW_GAME][Config::NB_COL_GAME];

    public:
        Grille(float x, float y, float w, float h);
        ~Grille(){};

        // Méthodes
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

        // Getter
        sf::Color& rndColor();

        // Affichage
        void draw(sf::RenderWindow& window);
        // Gestion des événements
        void handleEvent(const Event& evt);
        // Mise à jour suite aux événements
        void update();
};

#endif // _GRILLE_HPP_
