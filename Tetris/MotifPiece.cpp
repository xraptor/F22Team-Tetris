#include "essential.hpp"

MotifPiece::MotifPiece() {

    /*
    x
    x
    x
    x
    */
    blockPush(true);
    linePush();
    linePush();
    linePush();
    lineMove();
    pieceMove();

    /*
    x
    x
    xx
    */
    blockPush(true);
    blockPush(false);
    linePush();
    linePush();
    lineMove();
    multipleBlockPush(2, true);
    lineMove();
    pieceMove();

    /*
     x
     x
    xx
    */
    blockPush(false);
    blockPush(true);
    linePush();
    linePush();
    lineMove();
    multipleBlockPush(2, true);
    lineMove();
    pieceMove();

    /*
    xxx
     x
    */
    multipleBlockPush(3, true);
    lineMove();
    blockPush(false);
    blockPush(true);
    blockPush(false);
    lineMove();
    pieceMove();

    /*
    xx
    xx
    */
    multipleBlockPush(2, true);
    linePush();
    lineMove();
    pieceMove();

    /*
    xx
     xx
    */
    multipleBlockPush(2, true);
    blockPush(false);
    lineMove();
    blockPush(false);
    multipleBlockPush(2, true);
    lineMove();
    pieceMove();

    /*
     xx
    xx
    */

    blockPush(false);
    multipleBlockPush(2, true);
    lineMove();
    multipleBlockPush(2, true);
    blockPush(false);
    lineMove();
    pieceMove();
}

vector<vector<bool> > MotifPiece::getPiece() {
    if(pieces.size() == 0) {
        cerr << "Il n'y a pas de pieces dans la banque !" << endl;
        exit(1);
    }
    return pieces[Utils::rndInt(pieces.size())];
}

void MotifPiece::multipleBlockPush(unsigned int n, bool b) {
    for(int i = 0; i < n; ++i) {
        ligne.push_back(b);
    }
}

void MotifPiece::blockPush(bool b) {
    ligne.push_back(b);
}

void MotifPiece::multipleLinePush(unsigned int n) {
    for(int i = 0; i < n; ++i) {
        piece.push_back(ligne);
    }
    ligne.clear();
}

void MotifPiece::linePush() {
    piece.push_back(ligne);
}

void MotifPiece::lineMove() {
    piece.push_back(ligne);
    ligne.clear();
}

void MotifPiece::pieceMove() {
    pieces.push_back(piece);
    piece.clear();
}
