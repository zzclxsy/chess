#ifndef CHESSCONTORL_H
#define CHESSCONTORL_H
#include "ChessPiece.h"
#include <QVector>

class ChessContorl
{
public:
    ChessContorl();
    void initChessPiece();
    void initChessPlayer();

private:
    QVector<ChessPiece *> m_allChessPiece;
};

#endif // CHESSCONTORL_H
