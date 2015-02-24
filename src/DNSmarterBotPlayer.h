/**
 * @file  DNSmarterBotPlayer.h
 * @brief Child of DNPlayer Smarted AI
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#ifndef __TicTacToe__DNSmarterBotPlayer__
#define __TicTacToe__DNSmarterBotPlayer__

#include <iostream>
#include "DNPlayer.h"
#include "DNCell.h"
#include <vector>
#include <set>

using namespace std;
class DNSmarterBotPlayer : public DNPlayer{
    
    public:
        /**
         * Constructor
         * @param nick name of player
         * @param symbol 
         * @param map pointer to map
         */
        DNSmarterBotPlayer(string nick, DNCellState symbol, DNMap * map);
        /**
         * 
         */
        ~DNSmarterBotPlayer();
        
        bool triggerTurn(int y, int x);
        bool addToLogical(int y, int x, DNCellState state);
        DNMap * game_map;
        
        set < pair<int,int> > availableMoves;
        

    
    
};


#endif /* defined(__TicTacToe__DNSmarterBotPlayer__) */
