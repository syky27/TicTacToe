//
//  DNDumbBotPlayer.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 19/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__DNDumbBotPlayer__
#define __TicTacToe__DNDumbBotPlayer__

#include <iostream>
#include "DNPlayer.h"
class DNDumbBotPlayer : public DNPlayer  {
    
    
public:
    DNDumbBotPlayer(string nick, DNCellState symbol, DNMap * map);
    ~DNDumbBotPlayer(){}
    
    bool triggerTurn(int y, int x);
    DNMap * game_map;
    
};


#endif /* defined(__TicTacToe__DNDumbBotPlayer__) */
