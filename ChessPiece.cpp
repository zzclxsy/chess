#include "ChessPiece.h"
#include <QPainter>
#include <QDebug>


ChessPiece::ChessPiece(QPoint coord, QString chessName, CAMP camp)
{
    m_initCoord = coord;
    m_chessName = chessName;
    m_chessType = GetPieceTypeByName(chessName);
    mb_isAlive = true;
    m_chessPos = coord;
    m_chessCamp = camp;
    mb_pick = false;
}

bool ChessPiece::IsAlive()
{
    return mb_isAlive;
}

void ChessPiece::SetAliveStatus(bool status)
{
    mb_isAlive = status;
}

void ChessPiece::SetChooseStatus(bool isChoose)
{
    mb_pick = isChoose;
}

bool ChessPiece::GetChooseStatus()
{
    return mb_pick;
}

QPoint ChessPiece::GetChessPos()
{
    return m_chessPos;
}

void ChessPiece::SetChessPos(QPoint pos)
{
    m_chessPos = pos;
}

void ChessPiece::DrawChessPiece(QPainter &painter,const QPointF &origin,const double &interval)
{
    //死掉的棋子不用画
    if (!mb_isAlive)
        return;

    QPen pen;
    if (m_chessCamp == CAMP_HAN)
        pen.setColor(QColor(255,0,0));
    else
         pen.setColor(QColor(0,0,0));
    painter.setPen(pen);


    painter.setBrush(QBrush(QColor(255,255,255)));

	QPointF pieceOrigin = origin + QPoint(m_chessPos.x() * interval, m_chessPos.y() * interval);
	painter.drawEllipse(pieceOrigin, interval / 2 - 1, interval / 2 - 1);

    if (mb_pick)
    {
        painter.setBrush(QBrush(QColor(255,0,0,30)));
        QPointF pieceOrigin = origin + QPoint(m_chessPos.x() * interval, m_chessPos.y() * interval);
        painter.drawEllipse(pieceOrigin, interval / 2 - 1, interval / 2 - 1);
    }
    //设置字体
    QFont font;
    font.setFamily("楷体");
    font.setPointSize(interval / 3);
    painter.setFont(font);
    QFontMetrics fontMetrics(font);
    painter.drawText(pieceOrigin + QPointF(-fontMetrics.width("楷")/2,interval / 6),m_chessName);
}

ChessPiece::TYPE ChessPiece::GetChessType()
{
    return m_chessType;
}

void ChessPiece::SetChessType(TYPE type)
{
    m_chessType = type;
}

QString ChessPiece::GetChessName()
{
    return m_chessName;
}

void ChessPiece::SetChessName(QString chessName)
{
    m_chessName = chessName;
}

ChessPiece::CAMP ChessPiece::GetChessCamp()
{
    return m_chessCamp;
}

ChessPiece::TYPE ChessPiece::GetPieceTypeByName(QString chessName)
{
    if (chessName =="将"||chessName =="帅")
        return TYPE::E_KING;

    if (chessName =="马"||chessName =="馬")
        return TYPE::E_MA;

    if (chessName =="兵"||chessName =="卒")
        return TYPE::E_BING;

    if (chessName =="相"||chessName =="象")
        return TYPE::E_XIANG;

    if (chessName =="车"||chessName =="車")
        return TYPE::E_CHE;

    if (chessName =="炮"||chessName =="砲")
        return TYPE::E_PAO;

    if (chessName =="士")
        return TYPE::E_SHI;
}
