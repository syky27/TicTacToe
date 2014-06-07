//
//  DNDumbBotPlayer.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 19/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNDumbBotPlayer.h"
#include "DNWindow.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "DNLogService.h"


DNDumbBotPlayer::DNDumbBotPlayer(string nick, DNCellState symbol, DNMap * map)
{
    this->nick = nick;
    this->symbol = symbol;
    this->game_map = map;
}

bool DNDumbBotPlayer::triggerTurn(int y, int x)
{
    
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    int max_y, max_x;
    max_y = w.ws_row;
    max_x = w.ws_col;
    
    int size = this->game_map->getMapSize();
    char ch;
    int x_rand = 0;
    int y_rand = 0;
    DNCellState state;
        while(true){
        x_rand = rand() % w.ws_col;
        y_rand = rand() % w.ws_row;

        y_rand = abs(y_rand + y);

        y_rand = 2;
        x_rand = 1;
    
    
        if (this->game_map->recordMove(this->getSymbol(), y_rand, x_rand, state)) {
            DNWindow::getInstance().drawSymbolBetter(this->getSymbol(),  x_rand, y_rand);
               
                std::stringstream ss("fekal");
                ss << string("x_rand = ") << x_rand << " " << string("y_rand = ") << y_rand << endl;
                std::string to_log;
                std::getline(ss, to_log, '\n');
                DNLogService::sharedObject().log(to_log);

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
    }
            
           
        
    
    return true;
}
