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

DNGame::DNGame(int i): y_offset(4), x_offset(0)
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
    DNWindow::getInstance().allowMacDev();
    char ch;
    
    int turnCounter = 0;
    
    
    while (ch = getchar()) {
//        cout << ch << endl;
        if (ch == /*0x1B ||*/ '\e') {
            ch = getchar();
            if (ch == /*0x5B ||*/ 'O') {
                ch = getchar();
                if (ch == /*0x41 ||*/ 'A') {
                    //Up Arrow
                    DNWindow::getInstance().moveUp();
                    continue;
                }else if (ch == /*0x42 ||*/ 'B') {
                    // Down Arrow
                    DNWindow::getInstance().moveDown();
                    continue;
                }else if (ch == /*0x44 ||*/ 'D'){
                    //Left Arrow
                    DNWindow::getInstance().moveLeft();
                    continue;
                }else if (ch == /*0x43 ||*/ 'C'){
                    //Right Arrow
                    DNWindow::getInstance().moveRight();
                    continue;
                }
            }
        }
        
        if (ch == 'x') {
            int x = 0;
            int y = 0;
            turnCounter++;
            DNCellState state;
            if (turnCounter % 2) {
                DNWindow::getInstance().getCursorPosition(x, y);
                if (map.recordMove(playerTwo, y - y_offset, x - x_offset, state)) {
                    DNWindow::getInstance().drawSymbol(CIRCLE, y, x);
                }else{
                    DNWindow::getInstance().sound();
                }
                
            }else{
                DNWindow::getInstance().getCursorPosition(x, y);
                if (map.recordMove(playerOne, y - y_offset, x - x_offset, state)) {
                    DNWindow::getInstance().drawSymbol(CROSS, y, x);
                }else{
                    DNWindow::getInstance().sound();
                }
            }
            if (state != EMPTY) {
                if (state == playerTwo->getSymbol()) {
                    cout << playerTwo->getNick() << " is WINNER!!!" << endl;
                }else{
                    cout << playerOne->getNick() << " is WINNER!!!" << endl;
                }
                sleep(2);
                exit(0);
            }
        
        }
    
        if (ch == 'q') {
            exit(0);
        }
    }
}


