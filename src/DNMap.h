/**
 * @file  DNMap.h
 * @brief Map Object
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#ifndef __TicTacToe__Map__
#define __TicTacToe__Map__

#include <iostream>
#include "DNCell.h"
#include "DNPlayer.h"
#include <vector>
using namespace std;


class DNMap {
public:
    size_t size;
    int row;
    int col;
    int goal;
    DNCell *my_map[100][100];
//    vector < DNCell * > filled;
    
    
public:
    /**
     * Constructor
     */
    DNMap();
    /**
     * Destructor
     */
    ~DNMap();
    /**
     * Debug helper print hole map to file
     */
    void debugToFile();
    
    /**
     * Getter for map size
     * @return map size
     */
    size_t getMapSize();

    /**
     * Winner Checker
     * @param symbol check for this symbol
     * @return given symbol back if player with this symbol has won, else EMPTY
     */
    DNCellState checkForWinnerWithSymbol(DNCellState symbol);
    
    
    
    /**
     * Records move for player
     * @param player
     * @param y
     * @param x
     * @param winnner check if player is winner
     * @return success/failure
     */
    bool recordMove(DNCellState player, int y, int x, DNCellState & winnner);

    
    

};


#endif /* defined(__TicTacToe__Map__) */
