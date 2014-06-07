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
#include "DNLogService.h"
#include "DNBotPlayer.h"
#include "DNHumanPlayer.h"
#include <cstdlib>
DNGame::DNGame(int i): y_offset(3), x_offset(0), playerOne(NULL), playerTwo(NULL)
{
    switch (i) {
        case 1:{
                initLocalGameTwoHumans();
                break;
                }
        case 2:{
//                initLocalGameHumanVsCPU();
                break;
                }
        default:{
                break;
                }
    }
}

DNGame::~DNGame(){}

void DNGame::initLocalGameTwoHumans()
{
    string nameOfFirstPlayer, nameOfSecondPlayer;
    DNWindow::getInstance().startLocalGameTwoHumans(nameOfFirstPlayer, nameOfSecondPlayer);
    this->playerOne = new DNHumanPlayer(nameOfFirstPlayer, DNCellState(CROSS), &map);
    this->playerTwo = new DNHumanPlayer(nameOfSecondPlayer, DNCellState(CIRCLE), &map);
//    this->playerOne->setColorSet(1);
//    this->playerTwo->setColorSet(2);
}





void DNGame::play()
{
    DNWindow::getInstance().allowMacDev();
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



//void DNGame::initLocalGameHumanVsCPU()
//{
//    string nameOfFirstPlayer;
//    DNWindow::getInstance().startLocalGameHumanVsCPU(nameOfFirstPlayer);
//    this->playerOne = new DNPlayer(nameOfFirstPlayer, DNCellState(CROSS));
//    this->playerOne->setColorSet(1);
//        
//    
//
//}

//void DNGame::initLocalGameTwoHumans()
//{
//    string nameOfFirstPlayer, nameOfSecondPlayer;
//    DNWindow::getInstance().startLocalGameTwoHumans(nameOfFirstPlayer, nameOfSecondPlayer);
//    this->playerOne = new DNPlayer(nameOfFirstPlayer, DNCellState(CROSS));
//    this->playerTwo = new DNPlayer(nameOfSecondPlayer, DNCellState(CIRCLE));
//    this->playerOne->setColorSet(1);
//    this->playerTwo->setColorSet(2);
//}
//
//void DNGame::initLocalGameHumanVsCPU()
//{
//    string nameOfFirstPlayer;
//    DNWindow::getInstance().startLocalGameHumanVsCPU(nameOfFirstPlayer);
//    this->playerOne = new DNPlayer(nameOfFirstPlayer, DNCellState(CROSS));
//    this->playerOne->setColorSet(1);
//    
//    
//    
//}



//void DNGame::play()
//{
//    DNWindow::getInstance().allowMacDev();
//    char ch;
//    
//    int turnCounter = 0;
//    
//    
//    while ((ch = getchar())) {
////        cout << ch << endl;
//        if (ch == /*0x1B ||*/ '\e') {
//            ch = getchar();
//            if (ch == /*0x5B ||*/ 'O') {
//                ch = getchar();
//                if (ch == /*0x41 ||*/ 'A') {
//                    //Up Arrow
//                    DNWindow::getInstance().moveUp();
//                    continue;
//                }else if (ch == /*0x42 ||*/ 'B') {
//                    // Down Arrow
//                    DNWindow::getInstance().moveDown();
//                    continue;
//                }else if (ch == /*0x44 ||*/ 'D'){
//                    //Left Arrow
//                    DNWindow::getInstance().moveLeft();
//                    continue;
//                }else if (ch == /*0x43 ||*/ 'C'){
//                    //Right Arrow
//                    DNWindow::getInstance().moveRight();
//                    continue;
//                }
//            }
//        }
//        
//        if (ch == 'x') {
//            DNLogService::sharedObject().log(string("Test"));
//            int x = 0;
//            int y = 0;
//            turnCounter++;
//            DNCellState state;
//            if (turnCounter % 2) {
//                DNWindow::getInstance().getCursorPosition(x, y);
//                DNLogService::sharedObject().log(to_string(x));
//                if (map.recordMove(playerTwo, y - y_offset, x - x_offset, state)) {
//                    DNWindow::getInstance().drawSymbol(CIRCLE, y, x);
//                }else{
//                    DNWindow::getInstance().sound();
//                    DNWindow::getInstance().sound();
//                    turnCounter--;
//                }
//                
//            }else{
//                DNWindow::getInstance().getCursorPosition(x, y);
//                if (map.recordMove(playerOne, y - y_offset, x - x_offset, state)) {
//                    DNWindow::getInstance().drawSymbol(CROSS, y, x);
//                }else{
//                    DNWindow::getInstance().sound();
//                    DNWindow::getInstance().sound();
//                    turnCounter--;
//                }
//            }
//            if (state != EMPTY) {
//                if (state == playerTwo->getSymbol()) {
//                    cout << playerTwo->getNick() << " is WINNER!!!" << endl;
//                }else if(state == playerOne->getSymbol()){
//                    cout << playerOne->getNick() << " is WINNER!!!" << endl;
//                }else{
//                    cout << "fekal error wrong return of state" << endl;
//                }
//                sleep(2);
//                exit(0);
//            }
//        
//        }
//    
//        if (ch == 'q') {
//            exit(0);
//        }
//    }
//}


//void DNGame::playVsCPU()
//{
//    char ch;
//    int turnCounter = 0;
//    int x = 0;
//    int y = 0;
//    DNCellState state;
//    while ((ch = getchar())) {
//        if (ch == /*0x1B ||*/ '\e') {
//            ch = getchar();
//            if (ch == /*0x5B ||*/ 'O') {
//                ch = getchar();
//                if (ch == /*0x41 ||*/ 'A') {
//                    //Up Arrow
//                    DNWindow::getInstance().moveUp();
//                    continue;
//                }else if (ch == /*0x42 ||*/ 'B') {
//                    // Down Arrow
//                    DNWindow::getInstance().moveDown();
//                    continue;
//                }else if (ch == /*0x44 ||*/ 'D'){
//                    //Left Arrow
//                    DNWindow::getInstance().moveLeft();
//                    continue;
//                }else if (ch == /*0x43 ||*/ 'C'){
//                    //Right Arrow
//                    DNWindow::getInstance().moveRight();
//                    continue;
//                }
//            }
//        }
//        
//        if (ch == 'x') {
//            turnCounter++;
//
//            if (turnCounter % 2) {
//                DNWindow::getInstance().getCursorPosition(x, y);
//                if (map.recordMove(playerOne, y - y_offset, x - x_offset, state)) {
//                    DNWindow::getInstance().drawSymbol(CIRCLE, y, x);
//                }else{
//                    DNWindow::getInstance().sound();
//                    DNWindow::getInstance().sound();
//                }
//                
//                if (state != EMPTY) {
//                    if (state == playerTwo->getSymbol()) {
//                        cout << playerTwo->getNick() << " is WINNER!!!" << endl;
//                        sleep(5);
//                        exit(0);
//                    }else if(state == playerOne->getSymbol()){
//                        cout << playerOne->getNick() << " is WINNER!!!" << endl;
//                        sleep(5);
//                        exit(0);
//                    }else{
//                        cout << "fekal error wrong return of state" << endl;
//                    }
//                    
//                }
//                
//                bool run = false;
//                while (!run) {
//                    int y_rand = (rand() % 100)+3;
//                    int x_rand = rand() % 100;
//                    
//                    run = map.recordMove(playerOne, y_rand - y_offset, x_rand - x_offset, state);
//                    DNWindow::getInstance().drawSymbol(CROSS, y_rand, x_rand);
//
//                }
//
//                if (state != EMPTY) {
//                    if (state == playerTwo->getSymbol()) {
//                        cout << playerTwo->getNick() << " is WINNER!!!" << endl;
//                        sleep(5);
//                        exit(0);
//                    }else if(state == playerOne->getSymbol()){
//                        cout << playerOne->getNick() << " is WINNER!!!" << endl;
//                        sleep(5);
//                        exit(0);
//                    }else{
//                        cout << "fekal error wrong return of state" << endl;
//                    }
//                    
//                }
//                
//            }
//            }
//        
//            
//        }
//        
//        if (ch == 'q') {
//            exit(0);
//        }
//    
//}


