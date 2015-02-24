/**
 * @file  DNSmarterBotPlayer.cpp
 * @brief Child of DNPlayer Smarted AI
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#include "DNSmarterBotPlayer.h"
#include "DNCell.h"
#include <cstdlib>
#include "DNWindow.h"
#include "DNLogService.h"

DNSmarterBotPlayer::DNSmarterBotPlayer(string nick, DNCellState symbol, DNMap* map)
{
    this->nick = nick;
    this->symbol = symbol;
    this->game_map = map;
}

DNSmarterBotPlayer::~DNSmarterBotPlayer()
{
    this->game_map = NULL;
    
}

bool DNSmarterBotPlayer::triggerTurn(int y, int x)
{

    for (size_t i = 1; i < game_map->getMapSize() - 1; i++) {
        for (size_t j = 1; j < game_map->getMapSize() - 1; j++) {
            if (game_map->my_map[i][j]->getState() != EMPTY) {
                if (game_map->my_map[i + 1][j]->getState() == EMPTY) {
                    availableMoves.insert(make_pair(i + 1, j));
                }
                if (game_map->my_map[i][j + 1]->getState() == EMPTY) {
                    availableMoves.insert(make_pair(i, j + 1));
                }
                //                if (game_map->my_map[i+1][j+1]->getState() == EMPTY) {
                //                    availableMoves.insert(make_pair(i+1,j+1));
                //                }
                if (game_map->my_map[i - 1][j]->getState() == EMPTY) {
                    availableMoves.insert(make_pair(i - 1, j));
                }
                if (game_map->my_map[i][j - 1]->getState() == EMPTY) {
                    availableMoves.insert(make_pair(i, j - 1));
                }
                //                if (game_map->my_map[i-1][j-1]->getState() == EMPTY) {
                //                    availableMoves.insert(make_pair(i-1,j-1));
                //                }
                //                if (game_map->my_map[i+1][j-1]->getState() == EMPTY) {
                //                    availableMoves.insert(make_pair(i+1,j-1));
                //                }
                //                if (game_map->my_map[i-1][j+1]->getState() == EMPTY) {
                //                    availableMoves.insert(make_pair(i-1,j+1));
                //                }


            }
        }
    }


    int x_p;
    int y_p;
   // int y_plus;
    int x_plus;

    if (availableMoves.size() > 0) {
        srand(time(0));
        size_t ran = rand() % availableMoves.size();
        set <pair<int, int> >::iterator it = availableMoves.begin();
        for (; ran != 0; ran--) *it++;

        x_p = it->first;
        y_p = it->second;
     //   y_plus = y_p + 3;
        x_plus = x_p + 3;

        it = availableMoves.begin();
        for (; it != availableMoves.end(); it++) {
            DNLogService::sharedObject() << it->first << "-" << it->second << "\n";
        }
    }
    else {
        srand(time(0));
        x_p = (rand() % 10) + 1;
        y_p = (rand() % 10) + 1;
     //   y_plus = y_p + 3;
        x_plus = x_p + 3;
    }

    DNCellState state;
    if (this->game_map->recordMove(this->getSymbol(), y_p, x_p, state)) {
        usleep(100000);
        DNWindow::getInstance().drawSymbolBetter(this->getSymbol(), y_p, x_plus);
        this->game_map->debugToFile();
        if (state != EMPTY) {
            if (state == this->getSymbol()) {
                string win = " is Winner!!!";
                win = this->getNick() + win;
                sleep(3);
                DNWindow::getInstance().terminateWithErrorMessage(win);
            }

        }
        else {
            availableMoves.clear();
            return true;
        }
    }


    availableMoves.clear();

    return false;
}