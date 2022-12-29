#include "ChessContorl.h"
#include "player/ChessPlayer.h"
#include <functional>
#include <QDebug>
#include <strategy/PieceStrategy.h>
ChessContorl::ChessContorl()
{
    m_totalPoint.append(PiecePoint("車",QPoint(0,0)));m_totalPoint.append(PiecePoint("馬",QPoint(1,0)));m_totalPoint.append(PiecePoint("象",QPoint(2,0)));m_totalPoint.append(PiecePoint("士",QPoint(3,0)));
    m_totalPoint.append(PiecePoint("将",QPoint(4,0)));m_totalPoint.append(PiecePoint("士",QPoint(5,0)));m_totalPoint.append(PiecePoint("象",QPoint(6,0)));m_totalPoint.append(PiecePoint("馬",QPoint(7,0)));
    m_totalPoint.append(PiecePoint("車",QPoint(8,0)));m_totalPoint.append(PiecePoint("卒",QPoint(0,3)));m_totalPoint.append(PiecePoint("卒",QPoint(2,3)));m_totalPoint.append(PiecePoint("卒",QPoint(4,3)));
    m_totalPoint.append(PiecePoint("卒",QPoint(6,3)));m_totalPoint.append(PiecePoint("卒",QPoint(8,3)));m_totalPoint.append(PiecePoint("砲",QPoint(1,2)));m_totalPoint.append(PiecePoint("砲",QPoint(7,2)));

    m_totalPoint.append(PiecePoint("车",QPoint(0,9)));m_totalPoint.append(PiecePoint("马",QPoint(1,9)));m_totalPoint.append(PiecePoint("相",QPoint(2,9)));m_totalPoint.append(PiecePoint("士",QPoint(3,9)));
    m_totalPoint.append(PiecePoint("帅",QPoint(4,9)));m_totalPoint.append(PiecePoint("士",QPoint(5,9)));m_totalPoint.append(PiecePoint("相",QPoint(6,9)));m_totalPoint.append(PiecePoint("马",QPoint(7,9)));
    m_totalPoint.append(PiecePoint("车",QPoint(8,9)));m_totalPoint.append(PiecePoint("兵",QPoint(0,6)));m_totalPoint.append(PiecePoint("兵",QPoint(2,6)));m_totalPoint.append(PiecePoint("兵",QPoint(4,6)));
    m_totalPoint.append(PiecePoint("兵",QPoint(6,6)));m_totalPoint.append(PiecePoint("兵",QPoint(8,6)));m_totalPoint.append(PiecePoint("炮",QPoint(1,7)));m_totalPoint.append(PiecePoint("炮",QPoint(7,7)));

    mp_currPiece = nullptr;
    CreateChessPiece();
    CreatePlayer();
}

void ChessContorl::ResetChessPiece()
{

}


void ChessContorl::CreatePlayer()
{
    mp_chuPlay = new ChessPlayer;
    mp_hanPlay = new ChessPlayer;
    mp_chuPlay->setNextPlayer(mp_hanPlay);
    mp_hanPlay->setNextPlayer(mp_chuPlay);

    mp_hanPlay->setCallBack(std::bind(&ChessContorl::RoundFinished, this));
    mp_chuPlay->setCallBack(std::bind(&ChessContorl::RoundFinished, this));

    mp_currPlayer = mp_hanPlay;
}

void ChessContorl::RoundFinished()
{
    mp_currPlayer = mp_currPlayer->nextPlayer();
    qDebug() << "回合结束";
}

void ChessContorl::DrawChessPiece(QPainter & painter, const QPointF & origin, const double & interval)
{
    for (ChessPiece *chess : qAsConst(m_totalPiece))
    {
        chess->DrawChessPiece(painter, origin, interval);
    }
}

bool ChessContorl::IsPiece(QPoint point)
{
    for (ChessPiece *chess : qAsConst(m_totalPiece))
    {
        if (chess->IsAlive() == false)
            continue;

        //该棋子被点击
        if (chess->GetChessPos() == point)
        {
            //判断是否是同一个阵营的棋子，如果是则改变挑选，如果不是则移动棋子到对应位置
            if (((mp_currPlayer == mp_chuPlay) && (chess->GetChessCamp() == ChessPiece::CAMP_CHU))
                    ||((mp_currPlayer == mp_hanPlay) && (chess->GetChessCamp() == ChessPiece::CAMP_HAN)))
            {
                if (mp_currPiece != nullptr)
                    mp_currPiece->SetChooseStatus(false);

                chess->SetChooseStatus(true);
                mp_currPiece = chess;
            }else{
                MovePiece(point,chess);
            }

            return true;
        }
    }

    MovePiece(point);
    return false;
}

bool ChessContorl::MovePiece(QPoint point,ChessPiece *endPiece)
{
    if (mp_currPiece == nullptr)
        return false;

    //只有同阵营棋手和棋子才能移动
    if (((mp_currPlayer == mp_chuPlay) && (mp_currPiece->GetChessCamp() == ChessPiece::CAMP_CHU))
            ||((mp_currPlayer == mp_hanPlay) && (mp_currPiece->GetChessCamp() == ChessPiece::CAMP_HAN))){

        if(mp_currPlayer->move(mp_currPiece,point,endPiece)){
            mp_currPiece->SetChessPos(point);

            return true;
        }
    }

    return false;
}

void ChessContorl::CreateChessPiece()
{
    for (int i = 0; i < m_totalPoint.size(); i++)
    {
        PiecePoint Point = m_totalPoint[i];
        if (i < 16)
            m_totalPiece.append(new ChessPiece(Point.second, Point.first, ChessPiece::CAMP_CHU));
        else
            m_totalPiece.append(new ChessPiece(Point.second, Point.first, ChessPiece::CAMP_HAN));
    }

    PieceStrategy::instant()->SetTotalPiece(m_totalPiece);
}


