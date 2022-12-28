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
    ChessPiece(QPoint coord, QString chessName, CAMP camp);

    //存活
    bool IsAlive();
    void SetAliveStatus(bool status);

    //挑选
    void SetChooseStatus(bool isChoose);
    bool GetChooseStatus();

    //坐标
    QPoint GetChessPos();
    void   SetChessPos(QPoint pos);

    //画棋子界面
    void DrawChessPiece(QPainter &painter,const QPointF &origin,const double &interval);

    //棋子类型
    TYPE GetChessType();
    void SetChessType(TYPE type);

    //棋子名称
    QString GetChessName();
    void SetChessName(QString chessName);

    //阵营
    CAMP GetChessCamp();

private:
    TYPE GetPieceTypeByName(QString chessName);

private:
    bool mb_isAlive;
    QPoint m_chessPos;
    QPoint m_initCoord;
    TYPE m_chessType;
    QString m_chessName;
    CAMP m_chessCamp;
    bool mb_pick;
};

#endif // CHESSPIECE_H
