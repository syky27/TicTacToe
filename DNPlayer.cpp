//
//  Player.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 19/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNPlayer.h"


DNPlayer::DNPlayer(string name, DNCellState symbol){
    this->nick = name;
    this->symbol = symbol;
}

void DNPlayer::setColorSet(int i)
{
    this->colorSet = i;
}