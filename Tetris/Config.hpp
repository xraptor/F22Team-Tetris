#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

class Config
{
public:
    static constexpr float PAS_BLOCK_X = 0;
    static constexpr float PAS_BLOCK_Y = 0;

    //static float TAILLE_BLOCK_X;
    //static float TAILLE_BLOCK_Y;

    static constexpr float TAILLE_BORDURE = 1;

    static constexpr int NB_COL_GAME = 10;
    static constexpr int NB_ROW_GAME = 20;

    static const sf::Color DEFAULT_BLOCK_COLOR;
};

#endif // _CONFIG_HPP_
