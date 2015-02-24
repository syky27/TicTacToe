/**
 * @file  DNPlayer.cpp
 * @brief Player object parent of them all.
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#include "DNPlayer.h"
#include "DNMap.h"



void DNPlayer::setColorSet(int i)
{
    this->colorSet = i;
}


bool DNPlayer::triggerTurn(int y, int x)
{
    return false;
}


DNCellState DNPlayer::getSymbol()
{
    return symbol;
}

string DNPlayer::getNick()
{
    return nick;
}