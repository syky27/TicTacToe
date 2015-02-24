/**
 * @file  DNGame.cpp
 * @brief Game object
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */
#include "DNGame.h"
#include "DNWindow.h"
#include "DNPlayer.h"
#include "DNCellState.h"
#include "stdio.h"
#include "DNLogService.h"
#include "DNSmarterBotPlayer.h"
#include "DNHumanPlayer.h"
#include "DNDumbBotPlayer.h"
#include "DNRemoteHumanPlayer.h"
#include <cstdlib>

DNGame::DNGame(int i) : y_offset(3), x_offset(0), playerOne(NULL), playerTwo(NULL)
{
    switch (i) {
    case 1:
    {
        initLocalGameTwoHumans();
        break;
    }
    case 2:
    {
        initLocalGameHumanVsCPU();
        break;
    }
    case 3:
    {
        initRemoteGameTwoHumans();
        break;
    }
    case 27:
    {
        initLocalGameTwoDumb();
        break;
    }
    default:
    {
        break;
    }
    }
}

DNGame::~DNGame(){
    delete this->playerOne;
    delete this->playerTwo;
    
}

void DNGame::initLocalGameTwoHumans()
{
    string nameOfFirstPlayer, nameOfSecondPlayer;
    DNWindow::getInstance().startLocalGameTwoHumans(nameOfFirstPlayer, nameOfSecondPlayer);
    this->playerOne = new DNHumanPlayer(nameOfFirstPlayer, DNCellState(CROSS), &map);
    this->playerTwo = new DNHumanPlayer(nameOfSecondPlayer, DNCellState(CIRCLE), &map);
}

void DNGame::initLocalGameTwoDumb()
{
    this->playerOne = new DNSmarterBotPlayer("Dumb",DNCellState(CROSS), & map);
    this->playerTwo = new DNSmarterBotPlayer("Dummer",DNCellState(CIRCLE), & map);
}


void DNGame::initLocalGameHumanVsCPU()
{
    string nameOfFirstPlayer;
    DNWindow::getInstance().startLocalGameHumanVsCPU(nameOfFirstPlayer);
    this->playerOne = new DNHumanPlayer(nameOfFirstPlayer, DNCellState(CROSS), &map);
//    this->playerTwo = new DNDumbBotPlayer("CPU",DNCellState(CIRCLE), & map);
    this->playerTwo =new DNSmarterBotPlayer("CPU", CIRCLE, &map);
}

void DNGame::initRemoteGameTwoHumans()
{
    string nameOfPlayer;
    int server = DNWindow::getInstance().startRemoteGameTwoHumans(nameOfPlayer);
    server--;
    this->playerOne = new DNRemoteHumanPlayer(nameOfPlayer, DNCellState(CROSS), &map, (bool)server);
}


void DNGame::play()
{
//    DNWindow::getInstance().allowMacDev();
    int turnCounter = 0;
    while (true) {
        turnCounter++;
        if (turnCounter % 2) {
            this->playerOne->triggerTurn(3, 0);
        }else{
            this->playerTwo->triggerTurn(3, 0);
        }
    }
 
    
}

void DNGame::playNetworkgame()
{
    this->playerOne->triggerTurn(3,0);
}
