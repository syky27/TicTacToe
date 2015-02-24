/**
 * @file  DNRemoteHumanPlayer.cpp
 * @brief Child of DNHumanPlayer
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#include "DNRemoteHumanPlayer.h"
#include <stdio.h>
#include "DNWindow.h"
#include <sstream>
#include <string>
#include <curses.h>


DNRemoteHumanPlayer::DNRemoteHumanPlayer(string nick, DNCellState symbol, DNMap* map, bool server)
{
    
    this->nick = nick;
    this->symbol = symbol;
    this->game_map = map;
    this->amIServer = server;
    if(server) this->clientSocket = DNNetworkConnection::getInstance().startServer();
    else this->clientSocket = DNNetworkConnection::getInstance().connectToServer();
    cout << server;
}

bool DNRemoteHumanPlayer::triggerTurn(int y, int x)
{
    sleep(2);
    if(!amIServer){ DNWindow::getInstance().drawHeaderWithGuide(string("TicTacToe press 'x' to trigger turn ==> WAIT")); processOponentsTurn();}
    else {DNWindow::getInstance().drawHeaderWithGuide(string("TicTacToe press 'x' to trigger turn ==> PLAY"));}
    
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


        if (ch == 'q' || ch == 'Q') {
            transferQuitGame();
        }


        if (ch == 'x') {
            int x = 0;
            int y = 0;
            DNCellState state;

            DNWindow::getInstance().getCursorPosition(x, y);
            if (this->game_map->recordMove(this->getSymbol(), x - 0, y - 3, state)) {
                DNWindow::getInstance().drawSymbol(this->getSymbol(), y, x);
                this->game_map->debugToFile();
                transferTurn(y, x);


                if (state != EMPTY) {
                    if (state == this->getSymbol()) {
                        string you_winner("YOU are WINNER!!!");
                        DNWindow::getInstance().terminateWithErrorMessage(you_winner);
                    }

                }
                DNWindow::getInstance().drawHeaderWithGuide(string("TicTacToe press 'x' to trigger turn ==> WAIT"));
                processOponentsTurn();
                DNWindow::getInstance().drawHeaderWithGuide(string("TicTacToe press 'x' to trigger turn ==> PLAY"));

            }
            else {
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
    
//    while ((ch = getchar())) {
//        //        cout << ch << endl;
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
//        
//        
//        if (ch == 'q' || ch == 'Q') {
//            transferQuitGame();
//        }
//
//        
//            if (ch == 'x') {
//                int x = 0;
//                int y = 0;
//                DNCellState state;
//                
//                DNWindow::getInstance().getCursorPosition(x, y);
//                if (this->game_map->recordMove(this->getSymbol(), x - 0, y - 3, state)) {
//                    DNWindow::getInstance().drawSymbol(this->getSymbol(), y, x);
//                    this->game_map->debugToFile();
//                    transferTurn(y,x);
//                    
//
//                    if (state != EMPTY) {
//                        if (state == this->getSymbol()) {
//                            string you_winner("YOU are WINNER!!!");
//                            DNWindow::getInstance().terminateWithErrorMessage(you_winner);
//                        }
//                        
//                    }
//                    DNWindow::getInstance().drawHeaderWithGuide(string("TicTacToe press 'x' to trigger turn ==> WAIT"));
//                    processOponentsTurn();
//                    DNWindow::getInstance().drawHeaderWithGuide(string("TicTacToe press 'x' to trigger turn ==> PLAY"));
//                    
//                }else{
//                    DNWindow::getInstance().sound();
//                    DNWindow::getInstance().sound();
//                }
//                
//                
//            if (ch == 'q') {
//                DNWindow::getInstance().terminate();
//            }
//        }
//    }
//    return true;
//
//    
//    
//    
//
//    
//    
//    return false;
//}

void DNRemoteHumanPlayer::transferTurn(int y, int x)
{
    stringstream tmp;
    tmp << y << ';' << x << endl;
    DNLogService::sharedObject() << "going to sent data " << "\n";
    DNNetworkConnection::getInstance().sendData(this->clientSocket, tmp.str());
    DNLogService::sharedObject() << "data sent" << "\n";
}

void DNRemoteHumanPlayer::transferQuitGame()
{
    DNNetworkConnection::getInstance().sendData(this->clientSocket, string("QUIT"));
    //close connection;
    DNNetworkConnection::getInstance().closeConnection(this->clientSocket);
    DNWindow::getInstance().terminateWithErrorMessage(string("You Have Quited this game :(   "));
}



void DNRemoteHumanPlayer::processOponentsTurn()
{
    
    DNCellState opSymbol, state;
    if (this->symbol == CROSS) opSymbol = CIRCLE;
    else opSymbol = CROSS;

    string op = DNNetworkConnection::getInstance().receiveData(this->clientSocket);
    if (op == "QUIT") {
        //close connection;
        DNNetworkConnection::getInstance().closeConnection(this->clientSocket);
        DNWindow::getInstance().terminateWithErrorMessage("OPPONNET QUITED GAME");
    }

    
    stringstream tmp(op);
    string s_y, s_x;
    int y,x;
    getline(tmp, s_x, ';');
    getline(tmp, s_y, ';');
    y = atoi(s_y.c_str());
    x = atoi(s_x.c_str());


    if (this->game_map->recordMove(opSymbol, x - 0, y - 3, state)) {
        DNWindow::getInstance().drawSymbolBetter(opSymbol, x, y);
        this->game_map->debugToFile();
     if (state != EMPTY) {
            if (state == opSymbol) {
                string op_winner("Opponent is winner");
                DNWindow::getInstance().terminateWithErrorMessage(op_winner);
            }
            
        }
    }
    else {
        DNWindow::getInstance().sound();
        DNWindow::getInstance().sound();
        cout << "FATATTATATATATLLL ERRRROOORRR" <<endl;
        
    }



    
}









