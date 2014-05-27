//
//  DNBoard.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 12/05/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNBoard.h"
#include <ncurses.h>
using namespace std;

DNBoard::DNBoard()
{
    initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();
    mvprintw(5,5,"dsad");
}