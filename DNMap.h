//
//  Map.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 18/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__Map__
#define __TicTacToe__Map__

#include <iostream>
#include "DNCell.h"
#include "DNPlayer.h"
using namespace std;


class DNMap {
public:
    size_t size;
    int row;
    int col;
    int goal;
    DNCell *my_map[100][100];
    
    
public:
    DNMap();
    ~DNMap();

    /**
     * returns given symbol back if player with this symbol has won
     * returns EMPTY when no winner
     */
    DNCellState checkForWinnerWithSymbol(DNCellState symbol);
    bool recordMove(DNPlayer * player, int y, int x, DNCellState & winner);
    

};


#endif /* defined(__TicTacToe__Map__) */
