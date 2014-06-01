#ifndef _MOTIFPIECE_HPP_
#define _MOTIFPIECE_HPP_

class MotifPiece{
    private:
        vector<bool> ligne;
        vector<vector<bool> > piece;
        vector<vector<vector<bool> > > pieces;

    public:
        MotifPiece();
        ~MotifPiece(){};

        vector<vector<bool> > getPiece();
        void multipleBlockPush(unsigned int n, bool b);
        void blockPush(bool b);
        void multipleLinePush(unsigned int n);
        void linePush();
        void lineMove();
        void pieceMove();
};

#endif // _MOTIFPIECE_HPP
