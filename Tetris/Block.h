#ifndef _Block_h_
#define _Block_h_

#include "essential.h"

class Block {
    private:
        float width;
        float height;
        Color color;
    
    public:
        Block();
        
        //~Block();
        
        void afficher();
        
        //friend ostream& operator <<(ostream& output, Block& b);
};

#endif