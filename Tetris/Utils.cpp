#include "essential.hpp"

#include <cstdlib>
#include <ctime>

unsigned int Utils::rndInt(unsigned int m) {
    srand(time(NULL));
    return rand() % m;
}
