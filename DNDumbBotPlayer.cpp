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

#include "DNLogService.h"


DNDumbBotPlayer::DNDumbBotPlayer(string nick, DNCellState symbol, DNMap * map)
{
    this->nick = nick;
    this->symbol = symbol;
    this->game_map = map;
}

bool DNDumbBotPlayer::triggerTurn(int y, int x)
{
    int size = this->game_map->getMapSize();
    char ch;
    int x_rand = 0;
    int y_rand = 0;
    DNCellState state;
    
    x_rand = (random() % size);
    y_rand = (random() % size);
    
    std::stringstream ss("fekal");
    
    ss << string("x_rand = ") << x_rand << string("y_rand = ") << y_rand << endl;
    std::string to_log;
    std::getline(ss, to_log, '\n');
    DNLogService::sharedObject().log(to_log);
    
    
    if (this->game_map->recordMove(this->getSymbol(), abs(y_rand - 3), x - 0, state)) {
        DNWindow::getInstance().drawSymbolBetter(this->getSymbol(), y, x);
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
            
            
           
        
    
    return true;
}
