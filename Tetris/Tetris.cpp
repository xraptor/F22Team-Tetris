#include "essential.hpp"

int main() {
    sf::Color a(sf::Color::Blue);
    //vector<Block> b(7, Block((float)7,(float)7, a));
    //b[0].afficher();
    Color c(255,255,255,0);
    //Piece p(b, c);
    cout << (int)a.b << (int)a.r << a.g << "ok" << endl;

    Application app;
	app.run();
	return 0;
}
