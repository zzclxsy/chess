#ifndef ABSTRACTCHESSPLAYER_H
#define ABSTRACTCHESSPLAYER_H
#include "ChessPiece.h"
#include <functional>
#include <QVector>
class AbstractChessPlayer
{
public:
    enum PLAYER_TYPE
    {
        E_robot,
        E_person
    };
public:
    AbstractChessPlayer(){};
    virtual ~AbstractChessPlayer(){}
    virtual void startPlay() = 0;
    virtual bool move(ChessPiece *startChess, QPoint endPos, ChessPiece *endChess = nullptr)=0;
    PLAYER_TYPE getPlayerType(){return m_type;};

	void setNextPlayer(AbstractChessPlayer *player) { mp_nextPlayer = player;}
	AbstractChessPlayer *nextPlayer() {return mp_nextPlayer;}

    //设置回调 ，移动完成，通知控制类
    void setCallBack(std::function<void()> callback){m_callback = callback;}

protected:
    void setPlayerType(PLAYER_TYPE type){m_type = type;}
    std::function<void()> m_callback;
private:
    PLAYER_TYPE m_type;
	AbstractChessPlayer *mp_nextPlayer;
};

#endif // ABSTRACTCHESSPLAYER_H
