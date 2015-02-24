/**
 * @file  DNHumanPlayer.cpp
 * @brief Human player object
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#include "DNHumanPlayer.h"
#include "DNWindow.h"
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <curses.h>

DNHumanPlayer::DNHumanPlayer(string nick, DNCellState symbol, DNMap * map)
{
    this->nick = nick;
    this->symbol = symbol;
    this->game_map = map;
}

DNHumanPlayer::~DNHumanPlayer()
{
    this->game_map = NULL;
}


bool DNHumanPlayer::triggerTurn(int y, int x)
{
    char ch;
    int key;
    while ((key = getch())) {
        ch = key;
        if (key == KEY_UP) {
            DNWindow::getInstance().moveUp();
            continue;

        }
        if (key == KEY_DOWN) {
            DNWindow::getInstance().moveDown();
            continue;
        }
        if (key == KEY_LEFT) {
            DNWindow::getInstance().moveLeft();
            continue;
        }

        if (key == KEY_RIGHT) {
            DNWindow::getInstance().moveRight();
            continue;
        }
        
            if (ch == 'x') {
                int x = 0;
                int y = 0;
                DNCellState state;
                
                DNWindow::getInstance().getCursorPosition(x, y);
                if (this->game_map->recordMove(this->getSymbol(), x - 0, y - 3, state)) {
                    DNWindow::getInstance().drawSymbol(this->getSymbol(), y, x);
                    this->game_map->debugToFile();

                    if (state != EMPTY) {
                        if (state == this->getSymbol()) {
                            string win(" is Winner !!!");
                            win = this->getNick() + win;
                            DNWindow::getInstance().terminateWithErrorMessage(win);
                        }
                    }else{
                        return true;
                    }
                }
        }
        
        if (ch == 'q') {
                DNWindow::getInstance().terminate();
            }
    }
    return true;
}
