/**
 * @file  DNHumanPlayer.h
 * @brief Human player object
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#ifndef __TicTacToe__HumanPlayer__
#define __TicTacToe__HumanPlayer__
#include "DNPlayer.h"
#include "DNMap.h"
class DNHumanPlayer : public DNPlayer  {
    
    
public:
    /**
     * Implicit Constructor
     */
    DNHumanPlayer(){};
    /**
     * Constructor 
     * @param nick players name
     * @param symbol symbol of player
     * @param map pointer to map
     */
    DNHumanPlayer(string nick, DNCellState symbol, DNMap * map);
    /**
     * Destructor
     */
    ~DNHumanPlayer();
    /**
     * Triggers players turn
     * @param y y position
     * @param x x position
     * @return if is success
     */
    bool triggerTurn(int y, int x);
    DNMap * game_map;

};

#endif
