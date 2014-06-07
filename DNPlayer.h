//
//  Player.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 19/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__Player__
#define __TicTacToe__Player__



#include <iostream>
#include "DNCellState.h"
using namespace std;

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
    DNPlayer(){}
    DNPlayer(string name, DNCellState symbol);
    bool makeMove(size_t x_position, size_t y_position);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    bool triggerTurn(int y, int x);
    void setColorSet(int i);
    DNCellState getSymbol();
    string getNick();
    
    
};
#endif /* defined(__TicTacToe__Player__) */
