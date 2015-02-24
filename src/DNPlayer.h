/**
 * @file  DNPlayer.h
 * @brief Player object parent of them all.
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#ifndef __TicTacToe__Player__
#define __TicTacToe__Player__



#include <iostream>
#include "DNCellState.h"
#include "DNMap.h"
using namespace std;

class DNPlayer{
protected:
    string nick;
    DNCellState symbol;
    size_t x_position;
    size_t y_position;
    int colorSet;
    
    
    
    
public:
    /**
     * Makes move
     * @param x_position
     * @param y_position
     * @return  success/failure
     */
    bool makeMove(size_t x_position, size_t y_position);
    /**
     * moves right
     */
    void moveRight();
    /**
     * moves left
     */
    void moveLeft();
    /**
     * moves up
     */
    void moveUp();
    /**
     * moves down
     */
    void moveDown();
    /**
     * Triggers turn
     * @param y position
     * @param x position
     * @return success/failure
     */
    virtual bool triggerTurn(int y, int x);
    /**
     * sets color set
     * @param i
     */
    void setColorSet(int i);
    /**
     * Getter for players symbol
     * @return symbol
     */
    DNCellState getSymbol();
    /**
     * getter for players nick
     * @return nick
     */
    string getNick();
    
    
};
#endif /* defined(__TicTacToe__Player__) */
