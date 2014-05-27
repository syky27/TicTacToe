//
//  DNGame.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 13/05/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNGame.h"
#include "DNWindow.h"
#include "DNPlayer.h"
#include "DNCellState.h"
#include "stdio.h"

DNGame::DNGame(int i)
{
    switch (i) {
        case 1:
            initLocalGameTwoHumans();
            break;
            
        default:
            break;
    }
}

DNGame::~DNGame()
{
    
}

void DNGame::initLocalGameTwoHumans()
{
    string nameOfFirstPlayer, nameOfSecondPlayer;
    DNWindow::getInstance().startLocalGameTwoHumans(nameOfFirstPlayer, nameOfSecondPlayer);
    this->playerOne = new DNPlayer(nameOfFirstPlayer, DNCellState(CROSS));
    this->playerTwo = new DNPlayer(nameOfSecondPlayer, DNCellState(CIRCLE));
    this->playerOne->setColorSet(1);
    this->playerTwo->setColorSet(2);
}

void DNGame::initLocalGameHumanVsCPU()
{
    
}

void DNGame::play()
{
    char ch;
    while (ch = getchar()) {
        if (ch == '\e') {
            if (1) {
                
            }
            cout << "Arrow UP" << endl;
        }
    }
}