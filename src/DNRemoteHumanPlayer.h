/**
 * @file  DNRemoteHumanPlayer.h
 * @brief Child of DNPlayer
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#ifndef __TicTacToe__DNRemoteHumanPlayer__
#define __TicTacToe__DNRemoteHumanPlayer__

#include <iostream>
#include "DNHumanPlayer.h"
#include "DNLogService.h"
#include "DNNetworkConnection.h"

class DNRemoteHumanPlayer : public DNHumanPlayer{
private:
    bool amIServer;
    int clientSocket;
    /**
     * Send turn to other player
     * @param y position
     * @param x position
     */
    void transferTurn(int y, int x);
    /**
     * Sends quit message to other player
     */
    void transferQuitGame();
    /**
     * Processes oponents turn
     */
    void processOponentsTurn();
    
public:
    /**
     * Constructor
     * @param nick name of player
     * @param symbol of player
     * @param map pointer to game map
     * @param server is this player playing on server or client
     */
    DNRemoteHumanPlayer(string nick, DNCellState symbol, DNMap * map, bool server);
    /**
     * Triggers turn
     * @param y position
     * @param x position
     * @return success/failure
     */
    virtual bool triggerTurn(int y, int x);
    

};



#endif /* defined(__TicTacToe__DNRemoteHumanPlayer__) */
