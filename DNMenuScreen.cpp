//
//  DNMenuScreen.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 11/05/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//
/*
#include "DNMenuScreen.h"
#include "DNBoard.h"
#include <ncurses.h>
#include <string>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
DNMenuScreen::DNMenuScreen()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    this->my = w.ws_col;
    this->mx = w.ws_row;
}

DNMenuScreen::~DNMenuScreen()
{
    
}
void DNMenuScreen::drawOptions()
{
    start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
    
    int line = this->mx / 3;
    int col  = this->my /10;

    mvprintw(line, this->my /10, "( ) Human vs. Human");
    mvprintw(line + 1, this->my /10, "( ) Human vs. CPU");
    mvprintw(line + 2, this->my /10, "( ) Human vs. Remote Human");
    
    mvprintw(line + 5, this->my /10, "( ) Info");
    mvprintw(line + 6, this->my /10, "( ) Quit");
    

	attron(COLOR_PAIR(1));
	mvaddch(line, col + 1, '1');
    mvaddch(line + 1, col + 1, '2');
    mvaddch(line + 2, col + 1, '3');
    mvaddch(line + 5, col + 1, 'I');
    mvaddch(line + 6, col + 1, 'Q');
    
	attroff(COLOR_PAIR(1));
    
    
}
void DNMenuScreen::middleString(string stringToPlace, int line)
{
       mvprintw(line, (this->my - stringToPlace.size())/2, "%s", stringToPlace.c_str());
}



void drawHeader()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    for (int i = 0; i < w.ws_col ; i++) {
        if (i == 0) {
            addch(ACS_ULCORNER);
            continue;
        }
        if (i == w.ws_col - 1) {
            addch(ACS_URCORNER);
            continue;
        }
        addch(ACS_HLINE);
    }
    addch(ACS_VLINE);
    printw("TicTacToe CTU FIT BI-PA2 Project\n");
    move(1, w.ws_col - 1);
    addch(ACS_VLINE);
    for (int i = 0; i < w.ws_col ; i++) {
        if (i == 0) {
            addch(ACS_LLCORNER);
            continue;
        }
        if (i == w.ws_col - 1) {
            addch(ACS_LRCORNER);
            continue;
        }
        addch(ACS_HLINE);
    }
}

void DNMenuScreen::drawMenu()
{
    int x, y;
    getsyx(x, y);
    move(x + 3, y);
    middleString(string("Please select on of these following options:"), 3);
    drawMainMenu();
    
}

bool DNMenuScreen::executeMenuOption(string input)
{
    
    if(isalnum(*input.c_str())){
        switch (atoi(input.c_str())) {
            case 1:
                DNBoard();
                break;
            case 2:
                //TODO: Player player
                break;
            case 3:
                //TODO: Player player
                break;
                
            default:
                break;
        }
    }

    if (input == "I" || input == "i") {
        //TODO: INPUT
    }
    
    if (input == "Q" || input == "q") {
        endwin();
        exit;
    }
    
    return false;
}
void DNMenuScreen::drawCommandLine()
{
    start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvprintw(this->mx -1 , 0, "COMMAND> ");
    move(this->mx - 1, 10);
    attron(COLOR_PAIR(0));

    
    
}

void moveLeft()
{
    int y,x;
    getsyx(y, x);
    move(y, x-1);
}

void DNMenuScreen::drawMainMenu()
{
    int ch;
  /*
	initscr();			/* Start curses mode 		*/
//	raw();				/* Line buffering disabled	*/
//	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
//	noecho();			/* Don't echo() while we do getch */
//    
//    drawHeader();
//    drawMenu();
//    drawOptions();
//    drawCommandLine();
//    string input = "";
//    
//    drawCommandLine();
//    while (ch = getch()) {
//        if (ch == 127) {
//            int y,x;
//            getsyx(y, x);
//            if (x == 10) {
//                beep();
//                continue;
//            }
//            mvdelch(y, x-1);
//            continue;
//        }
//        if (ch == 260) {
//            moveLeft();
//            continue;
//        }
//        if (ch == 10) {
//            executeMenuOption(input);
//            break;
//        }else{
//            input += ch;
//            addch(ch);
//        }
//        
//        
//    }
//    
//
//	refresh();			/* Print it on to the real screen */
////    getch();			/* Wait for user input */
//	endwin();			/* End curses mode		  */
//    
//

//}*/