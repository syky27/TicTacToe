//
//  HumanPlayer.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 19/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__HumanPlayer__
#define __TicTacToe__HumanPlayer__
#include "DNPlayer.h"
#include "DNMap.h"
class DNHumanPlayer : public DNPlayer  {
    
    
public:
    DNHumanPlayer(string nick, DNCellState symbol, DNMap * map);
    ~DNHumanPlayer(){}
    
    bool triggerTurn(int y, int x);
    DNMap * game_map;

};

#endif
