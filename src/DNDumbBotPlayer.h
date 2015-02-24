/**
 * @file  DNDumbBotPlayer.h
 * @brief Really stupid AI player.
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */
#ifndef __TicTacToe__DNDumbBotPlayer__
#define __TicTacToe__DNDumbBotPlayer__

#include <iostream>
#include "DNPlayer.h"
class DNDumbBotPlayer : public DNPlayer  {
    
    
public:
    /**
     * Constructor
     * @param nick name of player
     * @param symbol symbol of player
     * @param map pointer to map
     */
    DNDumbBotPlayer(string nick, DNCellState symbol, DNMap * map);
    /**
     * Destructor
     */
    ~DNDumbBotPlayer();
    /**
     * Triggers players turn
     * @param y y position
     * @param x x position
     * @return if is success
     */
    bool triggerTurn(int y, int x);
    
    DNMap * game_map;
    
};


#endif /* defined(__TicTacToe__DNDumbBotPlayer__) */
