//
//  DNWindow.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 12/05/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__DNWindow__
#define __TicTacToe__DNWindow__

#include <iostream>
#include "DNCellState.h"
#include <unistd.h> 
using namespace std;
class DNWindow
{
public:
    static DNWindow& getInstance()
    {
        static DNWindow instance;
        return instance;
    }
    void init ();
    void drawHeader();
    void drawOptions();
    void middleString(std::string stringToPlace, int line);
    void drawMenu();
    void drawCommandLine();

    void drawMainMenu();
    bool executeMenuOption(std::string input);
    void clearScreen();
    void drawBoard(int start_Y, int start_X, int size);
    bool startLocalGameTwoHumans(string & nameOfPlayerOne, string & nameOfPlayerTwo);
    bool startLocalGameHumanVsCPU(string & nameOfPlayerOne);
    void allowMacDev(void);
    
    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    
    void getCursorPosition(int & x, int &y);
    void drawSymbol(DNCellState state, int & x, int &y);
    
    
    void sound();
    
    
    
    
    

    void terminate();
    
    
private:
    DNWindow() {}
    DNWindow(DNWindow const&);
    void operator=(DNWindow const&);
    int mx,my;
};


#endif /* defined(__TicTacToe__DNWindow__) */
