/**
 * @file DNCell.h
 * @brief Cell of game map.
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */
#ifndef __TicTacToe__Cell__
#define __TicTacToe__Cell__

#include <iostream>
#include "DNCellState.h"
class DNCell{
private:
    
    DNCellState state;
    size_t x_pos;
    size_t y_pos;
    
    
public:
    /**
     * Constructor
     */
    DNCell();
    /**
     * Constructor
     * @param y position 
     * @param x position
     */
    DNCell(size_t y, size_t x);
    /**
     * Destructor
     */
    ~DNCell(void);
    /**
     * Getter for X position
     * @return x position
     */
    size_t getX_pos();
    /**
     * Getter for Y position
     * @return y position
     */
    size_t getY_pos();
    /**
     * Getter for cell state
     * @return 
     */
    DNCellState getState()const;
    /**
     * Setter for cell state
     * @param state cellstate CROSS/CIRCLE/EMPTY
     */
    void setState(DNCellState state);
    
    
    
    
};

#endif /* defined(__TicTacToe__Cell__) */
