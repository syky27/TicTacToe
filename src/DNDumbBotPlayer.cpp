/**
 * @file  DNDumbBotPlayer.cpp
 * @brief Really stupid AI player.
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#include "DNDumbBotPlayer.h"
#include "DNWindow.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "DNLogService.h"
#include <ctime>



DNDumbBotPlayer::DNDumbBotPlayer(string nick, DNCellState symbol, DNMap * map)
{
    this->nick = nick;
    this->symbol = symbol;
    this->game_map = map;
}
DNDumbBotPlayer::~DNDumbBotPlayer()
{
    delete this->game_map;// = NULL;
 }

bool DNDumbBotPlayer::triggerTurn(int y, int x)
{
    
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int x_rand = 0;
    int y_rand = 0;
    DNCellState state;
    srand(time(0));
        while(true){
        x_rand =  rand() % w.ws_col;
        y_rand = rand()  % (w.ws_row -3 );

        

        y_rand += 3;
        
    
    
        if (this->game_map->recordMove(this->getSymbol(),  x_rand, y_rand - 3 , state)) {
            DNWindow::getInstance().drawSymbolBetter(this->getSymbol(),  x_rand, y_rand);
               
                std::stringstream ss("fekal");
                ss << string("x_rand = ") << x_rand << " " << string("y_rand = ") << y_rand << endl;
                std::string to_log;
                std::getline(ss, to_log, '\n');
                DNLogService::sharedObject().log(to_log);
                this->game_map->debugToFile();
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
