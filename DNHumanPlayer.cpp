//
//  HumanPlayer.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 19/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNHumanPlayer.h"
#include "DNWindow.h"
#include <cstdlib>
#include <iostream>
#include <cstdio>

DNHumanPlayer::DNHumanPlayer(string nick, DNCellState symbol, DNMap * map)
{
    this->nick = nick;
    this->symbol = symbol;
    this->game_map = map;
}

bool DNHumanPlayer::triggerTurn(int y, int x)
{
    char ch;
    while ((ch = getchar())) {
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
                DNCellState state;
                
                DNWindow::getInstance().getCursorPosition(x, y);
                if (this->game_map->recordMove(this->getSymbol(), y - 3, x - 0, state)) {
                    DNWindow::getInstance().drawSymbol(this->getSymbol(), y, x);
                    if (state != EMPTY) {
                        if (state == this->getSymbol()) {
                            cout << this->getNick() << " is WINNER!!!" << endl;
                        }
                        sleep(2);
                        DNWindow::getInstance().terminate();
                    }else{
                        return true;
                    }
                }else{
                    DNWindow::getInstance().sound();
                    DNWindow::getInstance().sound();
                }
                
                
            if (ch == 'q') {
                DNWindow::getInstance().terminate();
            }
        }
    }
    return true;
}
