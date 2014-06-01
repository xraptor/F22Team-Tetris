#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

class Config
{
public:

    static constexpr int NB_COL_GAME = 10;
    static constexpr int NB_ROW_GAME = 20;

    static const sf::Color DEFAULT_BLOCK_COLOR;

    static constexpr float TAILLE_BLOCK_BORDURE = 1;
    static const sf::Color BLOCK_BORDURE_COLOR;
};

#endif // _CONFIG_HPP_
