#ifndef CHESSCONTORL_H
#define CHESSCONTORL_H
#include "ChessPiece.h"
#include <QVector>
#include "player/ChessPlayer.h"
#include <QMap>
#include <QPoint>
class ChessContorl
{
    typedef QPair<QString, QPoint> PiecePoint;
public:
    ChessContorl();
    void DrawChessPiece(QPainter &painter, const QPointF &origin, const double &interval);
    bool IsPiece(QPoint point);

private:
    void CreateChessPiece();
    void ResetChessPiece();
    void CreatePlayer();


    void RoundFinished();
private:
    QVector<ChessPiece *> m_totalPiece;
	AbstractChessPlayer *mp_currPlayer;

    AbstractChessPlayer *mp_chuPlay;
    AbstractChessPlayer *mp_hanPlay;
    ChessPiece *mp_currPiece;
    QList<PiecePoint> m_totalPoint;

};

#endif // CHESSCONTORL_H
