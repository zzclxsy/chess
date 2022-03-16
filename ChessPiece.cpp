#include "ChessPiece.h"
#include <QPoint>
struct POS
{
    int x;
    int y;
    ChessPiece::TYPE type;
    bool isUsing = false;
};

POS tPos[16]{
    {0,0,ChessPiece::TYPE::E_CHE},
    {1,0,ChessPiece::TYPE::E_MA},
    {2,0,ChessPiece::TYPE::E_XIANG},
    {3,0,ChessPiece::TYPE::E_SHI},
    {5,0,ChessPiece::TYPE::E_KING},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
    {0,0,ChessPiece::TYPE::E_CHE},
};

ChessPiece::ChessPiece()
{

}
