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
using namespace std;


class DNMap {
public:
    size_t size;
    int row;
    int col;
    int goal;
    DNCell *my_map[25][25];
    
    
public:
    DNMap();
    ~DNMap();

    /**
     * returns given symbol back if player with this symbol has won
     * returns EMPTY when no winner
     */
    DNCellState checkForWinnerWithSymbol(DNCellState symbol);

};


#endif /* defined(__TicTacToe__Map__) */
