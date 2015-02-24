/**
 * @file  DNGame.h
 * @brief Game object
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#ifndef __TicTacToe__DNGame__
#define __TicTacToe__DNGame__
#include "DNPlayer.h"
#include "DNMap.h"
#include "DNSmarterBotPlayer.h"
#include <iostream>
class DNGame {
    DNMap map;
    int y_sizeOfBoard;
    int x_sizeOfBoard;
    unsigned int y_offset, x_offset;
    /**
     * Initialization of game with two human players
     */
    void initLocalGameTwoHumans();
    /**
     * Initialization of game with one human and one AI player
     */
    void initLocalGameHumanVsCPU();
    /**
     * Initialization of game with two stupid players
     */
    void initLocalGameTwoDumb();
    /**
     * Initialization of network game
     */
    void initRemoteGameTwoHumans();
    

public:
    /**
     * Constructor
     * @param i game type
     */    
    DNGame(int i);
    /**
     * Destructor
     */
    ~DNGame();
    /**
     * Method to start playing game
     */
    void play();
    /**
     * Method to start playing network game
     */
    void playNetworkgame();
    DNPlayer *playerOne;
    DNPlayer *playerTwo;
};



#endif /* defined(__TicTacToe__DNGame__) */
