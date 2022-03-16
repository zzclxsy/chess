#include "Chessboard.h"
#include <QPainter>
#define BOARD_MARGIN_X 50
#define BOARD_MARGIN_Y 50

Chessboard::Chessboard(QWidget *parent)
    : QWidget(parent)
{
}

Chessboard::~Chessboard()
{
}

void Chessboard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //抗锯齿和使用平滑转换算法
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    //去掉留白，剩下就是棋盘外壳大小
    QSizeF realBoardSize = this->size() - QSize(BOARD_MARGIN_X * 2,BOARD_MARGIN_Y * 2);
    //棋盘外壳长宽比为10:9，正常棋盘长宽比为9:8，长宽多一格的原因是棋子摆放在线的边界处，上下左右会突出半格，合计1格
    //重新计算棋盘外壳大小，保持长宽比为10:9
    if (realBoardSize.width() * (10.0/9.0) <= realBoardSize.height())
        realBoardSize.setHeight(realBoardSize.width() * (10.0/9.0));
    else
        realBoardSize.setWidth(realBoardSize.height() * (9.0/10.0));

    //计算棋盘外壳起点坐标, 使棋盘外壳在界面最中间
    QPointF realOrigin((this->size().width() - realBoardSize.width())/2.0,
                       (this->size().height() - realBoardSize.height())/2.0);

    //画棋盘外壳
    painter.drawLine(realOrigin + QPointF(0, 0),                                          realOrigin + QPointF(0, realBoardSize.height()));
    painter.drawLine(realOrigin + QPointF(0, realBoardSize.height()),                     realOrigin + QPointF(realBoardSize.width(), realBoardSize.height()));
    painter.drawLine(realOrigin + QPointF(realBoardSize.width(), realBoardSize.height()), realOrigin + QPointF(realBoardSize.width(), 0));
    painter.drawLine(realOrigin + QPointF(realBoardSize.width(), 0),                      realOrigin + QPointF(0, 0));

    //计算格子大小
    double interval = realBoardSize.height()/10.0;

    //计算棋盘起点
    QPointF origin(realOrigin + QPointF(interval/2,interval/2));

    //画竖线 共9条
    QPointF originCopy = origin;
    for(int i =1; i <= 9; i++)
    {
        if (i != 1 && i != 9)
        {
            painter.drawLine(originCopy, originCopy + QPointF(0, interval * 4));
            painter.drawLine(originCopy + QPointF(0, interval * 5), originCopy + QPointF(0, interval * 9));
        }else
            painter.drawLine(originCopy, originCopy + QPointF(0, interval * 9));

        originCopy.setX(originCopy.x() + interval);
    }

    // 画横线 共10条
    originCopy = origin;
    for(int i =1; i <= 10; i++)
    {
        painter.drawLine(originCopy, originCopy + QPointF(interval * 8, 0));
        originCopy.setY(originCopy.y() + interval);
    }

    //画斜线
    painter.drawLine(origin + QPointF(interval * 3, 0), origin + QPointF(interval * 5, interval * 2));
    painter.drawLine(origin + QPointF(interval * 5, 0), origin + QPointF(interval * 3, interval * 2));

    painter.drawLine(origin + QPointF(interval * 3, interval * 9), origin + QPointF(interval * 5, interval * 7));
    painter.drawLine(origin + QPointF(interval * 5, interval * 9), origin + QPointF(interval * 3, interval * 7));

    //画位置标识
    paintPosStatus(painter, origin + QPointF(interval,    interval *2), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *7, interval *2), interval, origin);
    paintPosStatus(painter, origin + QPointF(0,           interval *3), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *2, interval *3), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *4, interval *3), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *6, interval *3), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *8, interval *3), interval, origin);

    paintPosStatus(painter, origin + QPointF(interval,    interval *7), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *7, interval *7), interval, origin);
    paintPosStatus(painter, origin + QPointF(0,           interval *6), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *2, interval *6), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *4, interval *6), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *6, interval *6), interval, origin);
    paintPosStatus(painter, origin + QPointF(interval *8, interval *6), interval, origin);

    //画楚河汉界


}

void Chessboard::paintPosStatus(QPainter &painter, QPointF pos, double interval, QPointF realorigin)
{
    //左上
    QVector<QPointF> leftTop;
    QPointF origin(pos + QPointF(-interval/10, -interval/10));
    leftTop.append(origin + QPointF(0, -interval/4));
    leftTop.append(origin);
    leftTop.append(origin);
    leftTop.append(origin + QPointF(-interval/4, 0));
    //右上
    QVector<QPointF> rightTop;
    origin = (pos + QPointF(interval/10, -interval/10));
    rightTop.append(origin + QPointF(0, -interval/4));
    rightTop.append(origin);
    rightTop.append(origin);
    rightTop.append(origin + QPointF(interval/4, 0));
    //左下
    QVector<QPointF> leftBottom;
    origin =(pos + QPointF(-interval/10, interval/10));
    leftBottom.append(origin + QPointF(0, interval/4));
    leftBottom.append(origin);
    leftBottom.append(origin);
    leftBottom.append(origin + QPointF(-interval/4, 0));
    //右下
    QVector<QPointF> rightBottom;
    origin =(pos + QPointF(interval/10, interval/10));
    rightBottom.append(origin + QPointF(0, interval/4));
    rightBottom.append(origin);
    rightBottom.append(origin);
    rightBottom.append(origin + QPointF(interval/4, 0));

    if (pos.x() <= realorigin.x())
    {
        painter.drawLines(rightTop);
        painter.drawLines(rightBottom);
    }
    else if (pos.x() >= realorigin.x() + interval*8)
    {
        painter.drawLines(leftTop);
        painter.drawLines(leftBottom);
    }
    else
    {
        painter.drawLines(rightTop);
        painter.drawLines(rightBottom);
        painter.drawLines(leftTop);
        painter.drawLines(leftBottom);
    }
}
