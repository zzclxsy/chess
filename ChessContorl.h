#ifndef CHESSCONTORL_H
#define CHESSCONTORL_H
#include "ChessPiece.h"
#include <QVector>
#include "player/ChessPlayer.h"
class ChessContorl
{
public:
    ChessContorl();
	void drawChessPiece(QPainter &painter, const QPointF &origin, const double &interval);

private:
    void initChessPiece();
    void initChessPlayer();

	void roundFinish();
private:
    QVector<ChessPiece *> m_allChessPiece;
	AbstractChessPlayer *mp_currPlayer;
	AbstractChessPlayer *chuPlay;
	AbstractChessPlayer *hanPlay;

};

#endif // CHESSCONTORL_H
