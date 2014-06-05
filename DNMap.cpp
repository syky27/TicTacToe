//
//  Map.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 18/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNMap.h"
#include "DNCell.h"
#include "DNCellState.h"
#include "DNLogService.h"



DNMap::DNMap(){
    this->size = 100;
    this->col = 100;
    this->row = 100;
    this->goal = 5;
    for (size_t i = 0; i < 100; i++) {
        for (size_t j = 0; j < 100; j++) {
            my_map[i][j] = new DNCell(i,j);
        }
    }
   
}

DNMap::~DNMap(){
    for (size_t i = 0; i < 100; i++) {
        for (size_t j = 0; j < 100; j++) {
            delete my_map[i][j];
        }
    }
    

    
}


DNCellState DNMap::checkForWinnerWithSymbol(DNCellState symbol){                                                           // check, which checks for backwards diagonal runs below >>>
    int row = 0, col = 0, i = 0;

    
    
    for ( row = 0; row < this->row; row++)                       // This first for loop checks every row
    {
        for ( col = 0; col < (this->col-(this->goal-1)); col++)           // And all columns until N away from the end
        {
            while (this->my_map[row][col]->getState() == symbol)      // For consecutive rows of the current player's mark
            {
                col++;
                i++;
                if (i == this->goal)
                {
                    return symbol;
                }
            }
            i = 0;
        }
    }
    
    for ( col = 0; col < this->col; col++)                       // This one checks for columns of consecutive marks
    {
        for ( row = 0; row < (this->row-(this->goal-1)); row++)
        {
            while (this->my_map[row][col]->getState() == symbol)
            {
                row++;
                i++;
                if (i == this->goal)
                {
                    return symbol;
                }
            }
            i = 0;
        }
    }
    
    for ( col = 0; col < (this->col - (this->goal-1)); col++)             // This one checks for "forwards" diagonal runs
    {
        for ( row = 0; row < (this->row-(this->goal-1)); row++)
        {
            while (this->my_map[row][col]->getState() == symbol)
            {
                row++;
                col++;
                i++;
                if (i == this->goal)
                {
                    return symbol;
                }
            }
            i = 0;
        }
    }
    // Finally, the backwards diagonals:
    for ( col = this->col-1; col > 0+(this->goal-2); col--)           // Start from the last column and go until N columns from the first
    {                                                   // The math seems strange here but the numbers work out when you trace them
        for ( row = 0; row < (this->row-(this->goal-1)); row++)       // Start from the first row and go until N rows from the last
        {
            while (this->my_map[row][col]->getState() == symbol)  // If the current player's character is there
            {
                row++;                                  // Go down a row
                col--;                                  // And back a column
                i++;                                    // The i variable tracks how many consecutive marks have been found
                if (i == this->goal)                             // Once i == N
                {
                    return symbol;                      // Return the current player number to the
                }                                       // winnner variable in the playGame function
            }                                           // If it breaks out of the while loop, there weren't N consecutive marks
            i = 0;                                      // So make i = 0 again
        }                                               // And go back into the for loop, incrementing the row to check from
    }
    
    return EMPTY;                                           // If we got to here, no winner has been detected,
}

bool DNMap::recordMove(DNPlayer * player, int y, int x, DNCellState & winner){
    DNLogService::sharedObject().log(string("x = ") + string(to_string(y)));
    
    if (this->my_map[x][y]->getState() == EMPTY) {
        this->my_map[x][y]->setState(player->getSymbol());
        winner = this->checkForWinnerWithSymbol(player->getSymbol());
        return true;
    }
    
    
    
    return false;
}







