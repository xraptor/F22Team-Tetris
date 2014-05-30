#include "essential.hpp"

MotifPiece::MotifPiece() {

    /*
    xxxxx
      x
      x
      x
    */
    multipleBlockPush(5, true);
    lineMove();
    multipleBlockPush(2, false);
    blockPush(true);
    multipleBlockPush(2, false);
    linePush();
    linePush();
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
