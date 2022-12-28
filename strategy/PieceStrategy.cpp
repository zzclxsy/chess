#include "PieceStrategy.h"
#include <QDebug>
PieceStrategy* PieceStrategy::mp_instant = nullptr;
PieceStrategy::PieceStrategy()
{

}

bool PieceStrategy::IsPieceMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    switch (startChess->GetChessType())
    {
    case ChessPiece::E_BING:
        return IsBingMove(startChess, endPos,  endChess);

    case ChessPiece::E_CHE:
        return IsCheMove(startChess, endPos,  endChess);

    case ChessPiece::E_KING:
        break;

    case ChessPiece::E_MA:
        break;

    case ChessPiece::E_PAO:
        return IsPaoMove(startChess, endPos,  endChess);

    case ChessPiece::E_SHI:
        break;

    case ChessPiece::E_XIANG:
        break;

    default:
        break;
    }

    return false;
}

void PieceStrategy::SetTotalPiece(QVector<ChessPiece *> totalPiece)
{
    m_totalPiece = totalPiece;
}

PieceStrategy *PieceStrategy::instant()
{
    if (mp_instant == nullptr)
        mp_instant = new PieceStrategy;

    return mp_instant;
}

bool PieceStrategy::IsBingMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    if (endChess != nullptr)
        qDebug()<<endChess->GetChessCamp()<<endChess->GetChessName()<<endChess->GetChessPos();
    if (startChess->GetChessCamp() == ChessPiece::CAMP_HAN){
        if (startChess->GetChessPos().y() >= 5){
            if (endPos.y() == startChess->GetChessPos().y() - 1
                    && endPos.x() == startChess->GetChessPos().x())
            {
                if (endChess != nullptr)
                    endChess->SetAliveStatus(false);

                return true;
            }
        }else {
            if (((endPos.y() == startChess->GetChessPos().y() - 1) && (endPos.x() == startChess->GetChessPos().x()))||
                    ((endPos.y() == startChess->GetChessPos().y()) && (endPos.x() == startChess->GetChessPos().x() - 1))||
                    ((endPos.y() == startChess->GetChessPos().y()) && (endPos.x() == startChess->GetChessPos().x() + 1)))
            {
                if (endChess != nullptr)
                    endChess->SetAliveStatus(false);

                return true;
            }
        }
    }else if (startChess->GetChessCamp() == ChessPiece::CAMP_CHU){
        if (startChess->GetChessPos().y() <= 4){
            if (endPos.y() == startChess->GetChessPos().y() + 1
                    && endPos.x() == startChess->GetChessPos().x())
            {
                if (endChess != nullptr)
                    endChess->SetAliveStatus(false);

                return true;
            }
        }else {
            if (((endPos.y() == startChess->GetChessPos().y() + 1) && (endPos.x() == startChess->GetChessPos().x()))||
                    ((endPos.y() == startChess->GetChessPos().y()) && (endPos.x() == startChess->GetChessPos().x() - 1))||
                    ((endPos.y() == startChess->GetChessPos().y()) && (endPos.x() == startChess->GetChessPos().x() + 1)))
            {
                if (endChess != nullptr)
                    endChess->SetAliveStatus(false);

                return true;
            }
        }
    }

    return false;
}

bool PieceStrategy::IsCheMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    if (startChess->GetChessPos().x() == endPos.x())
    {
        if (startChess->GetChessPos().y() > endPos.y())
        {
            foreach(ChessPiece *piece, m_totalPiece){
                if (piece->IsAlive() == false)
                    continue;

                if ((piece->GetChessPos().x() == startChess->GetChessPos().x())
                        && (piece->GetChessPos().y() < startChess->GetChessPos().y())
                        && (piece->GetChessPos().y() > endPos.y())){

                    return false;
                }
            }
        }else if (startChess->GetChessPos().y() < endPos.y()){
            foreach(ChessPiece *piece, m_totalPiece){
                if (piece->IsAlive() == false)
                    continue;

                if ((piece->GetChessPos().x() == startChess->GetChessPos().x())
                        && (piece->GetChessPos().y() > startChess->GetChessPos().y())
                        && (piece->GetChessPos().y() < endPos.y())){
                    return false;
                }
            }
        }

    }else if (startChess->GetChessPos().y() == endPos.y())
    {
        if (startChess->GetChessPos().x() > endPos.x())
        {
            foreach(ChessPiece *piece, m_totalPiece){
                if (piece->IsAlive() == false)
                    continue;

                if ((piece->GetChessPos().y() == startChess->GetChessPos().y())
                        && (piece->GetChessPos().x() < startChess->GetChessPos().x())
                        && (piece->GetChessPos().x() > endPos.x())){
                    return false;
                }
            }
        }else if (startChess->GetChessPos().x() < endPos.x()){
            foreach(ChessPiece *piece, m_totalPiece){
                if (piece->IsAlive() == false)
                    continue;

                if ((piece->GetChessPos().y() == startChess->GetChessPos().y())
                        && (piece->GetChessPos().x() > startChess->GetChessPos().x())
                        && (piece->GetChessPos().x() < endPos.x())){
                    return false;
                }
            }
        }

    }else {
        return false;
    }

    if (endChess != nullptr)
        endChess->SetAliveStatus(false);

    return true;
}

bool PieceStrategy::IsPaoMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    if (startChess->GetChessPos().x() == endPos.x())
    {
        if (startChess->GetChessPos().y() > endPos.y())
        {
            unsigned char index = 0;
            foreach(ChessPiece *piece, m_totalPiece){
                if (piece->IsAlive() == false)
                    continue;

                if ((piece->GetChessPos().x() == startChess->GetChessPos().x())
                        && (piece->GetChessPos().y() < startChess->GetChessPos().y())
                        && (piece->GetChessPos().y() > endPos.y())){

                    index++;
                }
            }

            if (index == 1)
            {
                if (endChess != nullptr){
                    endChess->SetAliveStatus(false);
                    return true;
                }
            }else if (index == 0)
            {
                if (endChess != nullptr)
                    return false;
                else
                    return true;
            }

            return false;

        }else if (startChess->GetChessPos().y() < endPos.y()){
            unsigned char index = 0;
            foreach(ChessPiece *piece, m_totalPiece){
                if (piece->IsAlive() == false)
                    continue;

                if ((piece->GetChessPos().x() == startChess->GetChessPos().x())
                        && (piece->GetChessPos().y() > startChess->GetChessPos().y())
                        && (piece->GetChessPos().y() < endPos.y())){

                  index++;
                }
            }

            if (index == 1)
            {
                if (endChess != nullptr){
                    endChess->SetAliveStatus(false);
                    return true;
                }
            }else if (index == 0)
            {
                if (endChess != nullptr)
                    return false;
                else
                    return true;
            }

            return false;
        }

    }else if (startChess->GetChessPos().y() == endPos.y())
    {
        if (startChess->GetChessPos().x() > endPos.x())
        {
            unsigned char index = 0;
            foreach(ChessPiece *piece, m_totalPiece){
                if (piece->IsAlive() == false)
                    continue;

                if ((piece->GetChessPos().y() == startChess->GetChessPos().y())
                        && (piece->GetChessPos().x() < startChess->GetChessPos().x())
                        && (piece->GetChessPos().x() > endPos.x())){

                   index++;
                }
            }

            if (index == 1)
            {
                if (endChess != nullptr){
                    endChess->SetAliveStatus(false);
                    return true;
                }
            }else if (index == 0)
            {
                if (endChess != nullptr)
                    return false;
                else
                    return true;
            }

            return false;

        }else if (startChess->GetChessPos().x() < endPos.x()){
            unsigned char index = 0;
            foreach(ChessPiece *piece, m_totalPiece){
                if (piece->IsAlive() == false)
                    continue;

                if ((piece->GetChessPos().y() == startChess->GetChessPos().y())
                        && (piece->GetChessPos().x() > startChess->GetChessPos().x())
                        && (piece->GetChessPos().x() < endPos.x())){

                   index++;
                }
            }

            if (index == 1)
            {
                if (endChess != nullptr){
                    endChess->SetAliveStatus(false);
                    return true;
                }
            }else if (index == 0)
            {
                if (endChess != nullptr)
                    return false;
                else
                    return true;
            }

            return false;
        }

    }else {
        return false;
    }


    return true;
}
