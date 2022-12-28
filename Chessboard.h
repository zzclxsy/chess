#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include "ChessContorl.h"
class Chessboard : public QWidget
{
    Q_OBJECT

public:
    Chessboard(QWidget *parent = nullptr);
    ~Chessboard();

private:
    void paintPosStatus(QPainter &painter, QPointF pos, double interval, QPointF origin);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
	ChessContorl *mp_chessContorl;
    QPointF m_realOrigin;
    double m_interval;
};
#endif // CHESSBOARD_H
