#ifndef PIECESTRATEGY_H
#define PIECESTRATEGY_H
#include "ChessPiece.h"
#include <QVector>
class PieceStrategy
{
public:
    PieceStrategy();
    bool IsPieceMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess = nullptr);
    void SetTotalPiece(QVector<ChessPiece *> totalPiece);

    static PieceStrategy *instant();

private:
    bool IsBingMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess = nullptr);
    bool IsCheMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess = nullptr);
    bool IsPaoMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess = nullptr);

private:
    static PieceStrategy* mp_instant;
    QVector<ChessPiece *> m_totalPiece;
};

#endif // PIECESTRATEGY_H
