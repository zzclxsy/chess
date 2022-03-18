#ifndef CHESSPLAYER_H
#define CHESSPLAYER_H

#include "AbstractChessPlayer.h"

class ChessPlayer : public AbstractChessPlayer
{
public:
    ChessPlayer();
    virtual void startPlay(){};
    virtual bool move(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess = nullptr);
};

#endif // CHESSPLAYER_H
