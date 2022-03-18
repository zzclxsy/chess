#include "ChessContorl.h"


ChessContorl::ChessContorl()
{


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
    m_allChessPiece.append(new ChessPiece(QPoint(2,0), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(4,0), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(6,0), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
    m_allChessPiece.append(new ChessPiece(QPoint(8,0), "卒",ChessPiece::E_CHE, ChessPiece::CAMP_CHU));
}


void ChessContorl::initChessPlayer()
{

}


