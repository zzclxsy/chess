#include "PieceStrategy.h"
#include <QDebug>
PieceStrategy* PieceStrategy::mp_instant = nullptr;
PieceStrategy::PieceStrategy()
{

}

bool PieceStrategy::IsPieceMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    //如果endPos位置在棋盘外面，则直接返回false
    if (endPos.x() < 0 || endPos.x() >8){
        return false;
    }
    if (endPos.y() < 0 || endPos.x() >9){
        return false;
    }

    switch (startChess->GetChessType())
    {
    case ChessPiece::E_BING:
        return IsBingMove(startChess, endPos,  endChess);

    case ChessPiece::E_CHE:
        return IsCheMove(startChess, endPos,  endChess);

    case ChessPiece::E_KING:
        return IsKingMove(startChess, endPos,  endChess);

    case ChessPiece::E_MA:
        return IsMaMove(startChess, endPos,  endChess);

    case ChessPiece::E_PAO:
        return IsPaoMove(startChess, endPos,  endChess);

    case ChessPiece::E_SHI:
        return IsShiMove(startChess, endPos,  endChess);

    case ChessPiece::E_XIANG:
        return IsXiangMove(startChess, endPos,  endChess);

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

bool PieceStrategy::IsShiMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    if (startChess->GetChessCamp() == ChessPiece::CAMP_HAN){
        //判断是否出界
        if (endPos.x() < 3|| endPos.y() <7|| endPos.x() > 5||endPos.y() >9)
            return false;

        if (((endPos.x() == (startChess->GetChessPos().x() + 1))&&(endPos.y() == (startChess->GetChessPos().y() + 1)))||
                ((endPos.x() == (startChess->GetChessPos().x() + 1))&&(endPos.y() == (startChess->GetChessPos().y() - 1)))||
                ((endPos.x() == (startChess->GetChessPos().x() - 1))&&(endPos.y() == (startChess->GetChessPos().y() + 1)))||
                ((endPos.x() == (startChess->GetChessPos().x() - 1))&&(endPos.y() == (startChess->GetChessPos().y() - 1)))){

            if (endChess != nullptr){
                endChess->SetAliveStatus(false);
            }

            return true;
        }
    }else if (startChess->GetChessCamp() == ChessPiece::CAMP_CHU){
        //判断是否出界
        if (endPos.x() < 3|| endPos.y() < 0|| endPos.x() > 5||endPos.y() >2)
            return false;

        if (((endPos.x() == (startChess->GetChessPos().x() + 1))&&(endPos.y() == (startChess->GetChessPos().y() + 1)))||
                ((endPos.x() == (startChess->GetChessPos().x() + 1))&&(endPos.y() == (startChess->GetChessPos().y() - 1)))||
                ((endPos.x() == (startChess->GetChessPos().x() - 1))&&(endPos.y() == (startChess->GetChessPos().y() + 1)))||
                ((endPos.x() == (startChess->GetChessPos().x() - 1))&&(endPos.y() == (startChess->GetChessPos().y() - 1)))){

            if (endChess != nullptr){
                endChess->SetAliveStatus(false);
            }

            return true;
        }
    }

    return false;
}

bool PieceStrategy::IsKingMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    if (startChess->GetChessCamp() == ChessPiece::CAMP_HAN){
        //判断是否出界
        if (endPos.x() < 3|| endPos.y() <7|| endPos.x() > 5||endPos.y() >9)
            return false;

        if (((endPos.x() == (startChess->GetChessPos().x()))&&(endPos.y() == (startChess->GetChessPos().y() + 1)))||
                ((endPos.x() == (startChess->GetChessPos().x()))&&(endPos.y() == (startChess->GetChessPos().y() - 1)))||
                ((endPos.x() == (startChess->GetChessPos().x() - 1))&&(endPos.y() == (startChess->GetChessPos().y())))||
                ((endPos.x() == (startChess->GetChessPos().x() + 1))&&(endPos.y() == (startChess->GetChessPos().y())))){

            if (endChess != nullptr){
                endChess->SetAliveStatus(false);
            }

            return true;
        }
    }else if (startChess->GetChessCamp() == ChessPiece::CAMP_CHU){
        //判断是否出界
        if (endPos.x() < 3|| endPos.y() < 0|| endPos.x() > 5||endPos.y() >2)
            return false;

        if (((endPos.x() == (startChess->GetChessPos().x()))&&(endPos.y() == (startChess->GetChessPos().y() + 1)))||
                ((endPos.x() == (startChess->GetChessPos().x()))&&(endPos.y() == (startChess->GetChessPos().y() - 1)))||
                ((endPos.x() == (startChess->GetChessPos().x() - 1))&&(endPos.y() == (startChess->GetChessPos().y())))||
                ((endPos.x() == (startChess->GetChessPos().x() + 1))&&(endPos.y() == (startChess->GetChessPos().y())))){

            if (endChess != nullptr){
                endChess->SetAliveStatus(false);
            }

            return true;
        }
    }

    return false;
}

bool PieceStrategy::IsXiangMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    //象不能过河
    if (startChess->GetChessCamp() == ChessPiece::CAMP_CHU){
        if (endPos.y() > 4)
            return false;
    }else if (startChess->GetChessCamp() == ChessPiece::CAMP_HAN){
        if (endPos.y() < 5)
            return false;
    }

    if ((endPos.x() == startChess->GetChessPos().x()+2)&&(endPos.y() == startChess->GetChessPos().y()+2))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x()+1,startChess->GetChessPos().y()+1);
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()+2)&&(endPos.y() == startChess->GetChessPos().y()-2)){
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x()+1,startChess->GetChessPos().y()-1);
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }
        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()-2)&&(endPos.y() == startChess->GetChessPos().y()+2)){
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x()-1,startChess->GetChessPos().y()+1);
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }
        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()-2)&&(endPos.y() == startChess->GetChessPos().y()-2)){
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x()-1,startChess->GetChessPos().y()-1);
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }
        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }

    return false;
}

bool PieceStrategy::IsMaMove(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    if ((endPos.x() == startChess->GetChessPos().x()+1)&&(endPos.y() == startChess->GetChessPos().y()+2))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x(),startChess->GetChessPos().y()+1);
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()-1)&&(endPos.y() == startChess->GetChessPos().y()+2))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x(),startChess->GetChessPos().y()+1);
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()-2)&&(endPos.y() == startChess->GetChessPos().y()+1))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x() - 1,startChess->GetChessPos().y());
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()-2)&&(endPos.y() == startChess->GetChessPos().y()-1))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x() - 1,startChess->GetChessPos().y());
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()-1)&&(endPos.y() == startChess->GetChessPos().y()-2))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x(),startChess->GetChessPos().y() - 1);
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()+1)&&(endPos.y() == startChess->GetChessPos().y()-2))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x(),startChess->GetChessPos().y() - 1);
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()+2)&&(endPos.y() == startChess->GetChessPos().y()-1))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x() + 1,startChess->GetChessPos().y());
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }else if ((endPos.x() == startChess->GetChessPos().x()+2)&&(endPos.y() == startChess->GetChessPos().y()+1))
    {
        //判断是否有撇脚
        foreach(ChessPiece *piece, m_totalPiece){
            if (piece->IsAlive() == false)
                continue;

            QPoint pieJiaoPos = QPoint(startChess->GetChessPos().x() + 1,startChess->GetChessPos().y());
            if (piece->GetChessPos() == pieJiaoPos){
                return false;
            }
        }

        if (endChess != nullptr){
            endChess->SetAliveStatus(false);
        }
        return true;
    }

    return false;
}
