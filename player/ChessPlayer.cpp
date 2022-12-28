#include "ChessPlayer.h"
#include "strategy/PieceStrategy.h"
ChessPlayer::ChessPlayer()
{
    setPlayerType(PLAYER_TYPE::E_person);
}

bool ChessPlayer::move(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess)
{
    if (PieceStrategy::instant()->IsPieceMove(startChess,endPos,endChess)){
        m_callback();
        return true;
   }
   return false;
}
