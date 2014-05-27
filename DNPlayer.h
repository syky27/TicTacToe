//
//  Player.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 19/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__Player__
#define __TicTacToe__Player__

using namespace std;

#include <iostream>
#include "DNCellState.h"


class DNPlayer{
private:
    string nick;
    DNCellState symbol;
    size_t x_position;
    size_t y_position;
    int colorSet;
    
    
    /*
    DNMap * game_map;
    */
public:
    DNPlayer(string name, DNCellState symbol);
    bool makeMove(size_t x_position, size_t y_position);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    bool triggerTurn();
    void setColorSet(int i);
    
    
};
#endif /* defined(__TicTacToe__Player__) */
