#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QPoint>
#include <QString>
class QPainter;
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

     enum CAMP{
         CAMP_CHU,
         CAMP_HAN
     };

public:
    ChessPiece(QPoint coord, QString chessName, TYPE chessType, CAMP camp);

    //存活
    bool isAlive();
    void setAliveStatus(bool status);

    //坐标
    QPoint getChessPos();
    void   setChessPos(QPoint pos);

    //画棋子界面
    void drawChessPiece(QPainter &painter,const QPointF &origin,const double &interval);

    //棋子类型
    TYPE getChessType();
    void setChessType(TYPE type);

    //棋子名称
    QString getChessName();
    void setChessName(QString chessName);

    //阵营
    CAMP getChessCamp();

private:
    bool mb_isAlive;
    QPoint m_chessPos;
    QPoint m_initCoord;
    TYPE m_chessType;
    QString m_chessName;
    CAMP m_chessCamp;
};

#endif // CHESSPIECE_H
