#ifndef CHESSPIECE_H
#define CHESSPIECE_H


class ChessPiece
{
public:
     enum TYPE{
        E_BING,
        E_PAO,
        E_CHE,
        E_MA,
        E_XIANG,
        E_SHI,
        E_KING
    };

public:
    ChessPiece();

private:
    bool mb_isLive;

};

#endif // CHESSPIECE_H
