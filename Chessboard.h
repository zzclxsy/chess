#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>

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

};
#endif // CHESSBOARD_H
