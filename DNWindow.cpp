//
//  DNWindow.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 12/05/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNWindow.h"
#include "ncurses.h"
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "DNGame.h"
#include "cstdlib"
using namespace std;


void DNWindow::init()
{
    int ch;
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
    
    drawMainMenu();
	refresh();

}



void DNWindow::drawHeader()
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

void DNWindow::drawOptions()
{
    
    refresh();
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
    
    int line = w.ws_row / 3;
    int col = w.ws_col;

    getsyx(line, col);
    
    mvprintw(w.ws_row / 3, w.ws_col /10, "( ) Human vs. Human");
    mvprintw(w.ws_row / 3 + 1, w.ws_col /10, "( ) Human vs. CPU");
    mvprintw(w.ws_row / 3 + 2, w.ws_col /10, "( ) Human vs. Remote Human");
    
    mvprintw(w.ws_row / 3 + 5, w.ws_col /10, "( ) Info");
    mvprintw(w.ws_row / 3 + 6, w.ws_col /10, "( ) Quit");
    
    
	attron(COLOR_PAIR(1));
	mvaddch(w.ws_row / 3, w.ws_col/10 + 1, '1');
    mvaddch(w.ws_row / 3 + 1, w.ws_col/10 + 1, '2');
    mvaddch(w.ws_row / 3 + 2, w.ws_col/10 + 1, '3');
    mvaddch(w.ws_row / 3 + 5, w.ws_col/10 + 1, 'I');
    mvaddch(w.ws_row / 3 + 6, w.ws_col/10 + 1, 'Q');
    
	attroff(COLOR_PAIR(1));
    
    
}

void DNWindow::middleString(string stringToPlace, int line)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    mvprintw(line, (w.ws_col - stringToPlace.size())/2, "%s", stringToPlace.c_str());
}

void DNWindow::drawMenu()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    move(w.ws_row + 3, w.ws_col);
    middleString(string("Please select on of these following options:"), 3);
    
    
}


void DNWindow::drawCommandLine()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvprintw(w.ws_row -1 , 0, "COMMAND> ");
    move(w.ws_col - 1, 10);
    attron(COLOR_PAIR(0));
    
    
    
    
}
void DNWindow::moveLeft()
{
    int y,x;
    getsyx(y, x);
     move(y, x-1);
}




void DNWindow::drawMainMenu()
{
    int ch;
//    
//	initscr();			/* Start curses mode 		*/
//	raw();				/* Line buffering disabled	*/
//	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
//	noecho();			/* Don't echo() while we do getch */
//    
    drawHeader();
    drawMenu();
    drawOptions();
    drawCommandLine();
    string input = "";
    
    drawCommandLine();
    while (ch = getch()) {
        if (ch == 127) {
            int y,x;
            getsyx(y, x);
            if (x == 9) {
                beep();
                continue;
            }
            mvdelch(y, x-1);
            continue;
        }
        if (ch == 260) {
            moveLeft();
            continue;
        }
        if (ch == 10) {
            executeMenuOption(input);
            break;
        }else{
            input += ch;
            addch(ch);
        }
        
        
    }
    
    
	refresh();			/* Print it on to the real screen */
    //    getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
    
    
    
}


bool DNWindow::executeMenuOption(string input)
{
    
    if(isalnum(*input.c_str())){
        switch (atoi(input.c_str())) {
            case 1:{
                DNGame a(1);
                drawBoard(3,0,10);
                a.play();
                break;
            }
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
        clearScreen();
        refresh();
        return true;
    }
    
    if (input == "Q" || input == "q") {
        endwin();
        exit;
    }
    
    return false;
}

void DNWindow::clearScreen()
{
    clear();
    refresh();
}


void DNWindow::drawBoard(int start_Y, int start_X, int size)
{
    start_color();
    use_default_colors();
	init_pair(2, COLOR_WHITE, -1);
    attroff(COLOR_PAIR(1));
    attron(2);
    clearScreen();
    drawHeader();
    move(start_Y,start_X);
    for (int y = 0; y < size; y++) {

        for (int x = 0; x < size * 2; x++) {
            if (x % 2) {
                mvaddch(start_Y + y, start_X + x, ' ');
            }else{
                mvaddch(start_Y + y, start_X + x, ACS_CKBOARD);
            }
            
        }
    }
    
    
    
    
    
    {
//    for (int i = 0; i < size * 2 + 1; i++) {
//        if (i == 0) {
//            mvaddch(start_Y, start_X + i, ACS_ULCORNER);
//            refresh();
//            continue;
//        }
//        if (i == size * 2) {
//            mvaddch(start_Y, start_X + i, ACS_URCORNER);
//            refresh();
//            continue;
//        }
//        if (i % 2 == 0) {
//            mvaddch(start_Y, start_X + i, ACS_TTEE);
//            refresh();
//            continue;
//        }else{
//            mvaddch(start_Y, start_X + i, ACS_HLINE);
//            refresh();
//            continue;
//        }
//        
//        
//    }
//    
//    for (int j = 2; j < 2 * size -1; j++) {
//
//    for (int i = 0; i < size * 2 + 1; i++) {
//        if ( j == 1 && i % 2 == 0) {
//            //mvaddch(start_Y +j, start_X + i, ACS_VLINE);
//            continue;
//        }else if (j == 1){
//            continue;
//        }
//        if ((j % 2 == 0 && i %2 == 0) ) {
//            mvaddch(start_Y +j, start_X + i, ACS_VLINE);
//            refresh();
//            continue;
//        }
//        if (j%2 == 0) {
//            continue;
//        }
//        if (i == 0) {
//            mvaddch(start_Y +j, start_X + i, ACS_LTEE);
//            refresh();
//            continue;
//        }
//        if (i == size * 2) {
//            mvaddch(start_Y +j, start_X + i, ACS_RTEE);
//            refresh();
//            continue;
//        }
//        if (i % 2 == 0) {
//            mvaddch(start_Y+j, start_X + i, ACS_PLUS);
//            refresh();
//            continue;
//        }else{
//            mvaddch(start_Y+j, start_X + i, ACS_HLINE);
//            refresh();
//            continue;
//        }
//        
//        
//    }
//    }
//    
//    
    
    }
    
    
    
    refresh();

    
    return;
    
    
}

bool DNWindow::startLocalGameTwoHumans(string & nameOfPlayerOne, string &  nameOfPlayerTwo)
{
//    noraw();a
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    clearScreen();
    drawHeader();
    char ch;
    middleString("Please enter name of first player: ", w.ws_row / 2);
    bool nameOfFirstPlayer = false;
    while (ch = getch()) {
        addch(ch);
        if (ch == 10) {
            if (nameOfFirstPlayer) {
                if (!nameOfPlayerTwo.length()) {
                    middleString("Name cannot be empty, try again: ", w.ws_row / 2);
                }else{
                    return true;
                }
            }else{
                if (!nameOfPlayerOne.length()) {
                    middleString("Name cannot be empty, try again: ", w.ws_row / 2);
                }else{
                    nameOfFirstPlayer = true;
                    clearScreen();
                    drawHeader();
                    middleString("Please enter name of second player: ", w.ws_row / 2);
                }
            }
            
        }else if (!nameOfFirstPlayer){
            nameOfPlayerOne += ch;
        }else{
            nameOfPlayerTwo += ch;
        }
    }
    
    return false;
}


void DNWindow::terminate()
{
    
    endwin();
    exit (0);
}











