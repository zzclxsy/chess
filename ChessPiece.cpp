#include "ChessPiece.h"
#include <QPainter>



ChessPiece::ChessPiece(QPoint coord, QString chessName, TYPE chessType, CAMP camp)
{
    m_initCoord = coord;
    m_chessName = chessName;
    m_chessType = chessType;
    mb_isAlive = true;
    m_chessPos = coord;
    m_chessCamp = camp;
}

bool ChessPiece::isAlive()
{
    return mb_isAlive;
}

void ChessPiece::setAliveStatus(bool status)
{
    mb_isAlive = status;
}

QPoint ChessPiece::getChessPos()
{
    return m_chessPos;
}

void ChessPiece::setChessPos(QPoint pos)
{
    m_chessPos = pos;
}

void ChessPiece::drawChessPiece(QPainter &painter,const QPointF &origin,const double &interval)
{

}

ChessPiece::TYPE ChessPiece::getChessType()
{
    return m_chessType;
}

void ChessPiece::setChessType(TYPE type)
{
    m_chessType = type;
}

QString ChessPiece::getChessName()
{
    return m_chessName;
}

void ChessPiece::setChessName(QString chessName)
{
    m_chessName = chessName;
}

ChessPiece::CAMP ChessPiece::getChessCamp()
{
    return m_chessCamp;
}
