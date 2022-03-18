#include "ChessContorl.h"
#include "player/ChessPlayer.h"
#include <functional>
#include <QDebug>
ChessContorl::ChessContorl()
{
	initChessPiece();
	initChessPlayer();
}

void ChessContorl::initChessPiece()
{
    m_allChessPiece.append(new ChessPiece(QPoint(0,0), "車",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(1,0), "馬",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(2,0), "象",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(3,0), "士",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(4,0), "将",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(5,0), "士",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(6,0), "象",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(7,0), "馬",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(8,0), "車",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(0,3), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(2,3), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(4,3), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(6,3), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(8,3), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
	m_allChessPiece.append(new ChessPiece(QPoint(1,2), "砲",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
	m_allChessPiece.append(new ChessPiece(QPoint(7,2), "砲",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
}


void ChessContorl::initChessPlayer()
{
	chuPlay = new ChessPlayer;
	hanPlay = new ChessPlayer;
	chuPlay->setNextPlayer(hanPlay);
	hanPlay->setNextPlayer(chuPlay);

	hanPlay->setCallBack(std::bind(&ChessContorl::roundFinish, this));
	chuPlay->setCallBack(std::bind(&ChessContorl::roundFinish, this));

	mp_currPlayer = chuPlay;
}

void ChessContorl::roundFinish()
{
	qDebug() << "回合结束";
}

void ChessContorl::drawChessPiece(QPainter & painter, const QPointF & origin, const double & interval)
{
	for (ChessPiece *chess : m_allChessPiece)
	{
		chess->drawChessPiece(painter, origin, interval);
	}
}


