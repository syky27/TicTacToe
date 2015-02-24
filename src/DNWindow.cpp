/**
 * @file  DNWindow.cpp
 * @brief Singleton to control NCURSES
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#include "DNWindow.h"
#include "ncurses.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "DNGame.h"
#include "cstdlib"
#include <curses.h>
#include <iosfwd>
#include "DNLogService.h"
using namespace std;

void DNWindow::init()
{
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
    for (int i = 0; i < w.ws_col; i++) {
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
    printw("TicTacToe\n");
    move(1, w.ws_col - 1);
    addch(ACS_VLINE);
    for (int i = 0; i < w.ws_col; i++) {
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
    refreshDN();
}


void DNWindow::drawHeaderWithGuide(string guide)
{
    
    int x_pos, y_pos;
    
    getsyx(y_pos, x_pos);
    
    move(0,0);
    
    
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    for (int i = 0; i < w.ws_col; i++) {
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
    printw(guide.c_str());
    move(1, w.ws_col - 1);
    addch(ACS_VLINE);
    for (int i = 0; i < w.ws_col; i++) {
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
    move(y_pos,x_pos);
    refreshDN();

}


void DNWindow::drawOptions()
{

    refresh();
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    mvprintw(w.ws_row / 3, w.ws_col / 10, "( ) Human vs. Human");
    mvprintw(w.ws_row / 3 + 1, w.ws_col / 10, "( ) Human vs. CPU");
    mvprintw(w.ws_row / 3 + 2, w.ws_col / 10, "( ) Human vs. Remote Human");
    mvprintw(w.ws_row / 3 + 3, w.ws_col / 10, "( ) Spectate 2 CPU");
    //mvprintw(w.ws_row / 3 + 5, w.ws_col / 10, "( ) Info");
    mvprintw(w.ws_row / 3 + 6, w.ws_col / 10, "( ) Quit");
    attron(COLOR_PAIR(1));

    mvaddch(w.ws_row / 3, w.ws_col / 10 + 1, '1');
    mvaddch(w.ws_row / 3 + 1, w.ws_col / 10 + 1, '2');
    mvaddch(w.ws_row / 3 + 2, w.ws_col / 10 + 1, '3');
    mvaddch(w.ws_row / 3 + 3, w.ws_col / 10 + 1, '4');
    
    //mvaddch(w.ws_row / 3 + 5, w.ws_col / 10 + 1, 'I');
    mvaddch(w.ws_row / 3 + 6, w.ws_col / 10 + 1, 'Q');
    attroff(COLOR_PAIR(1));
}

void DNWindow::middleString(string stringToPlace, int line)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    mvprintw(line, (w.ws_col - stringToPlace.size()) / 2, "%s", stringToPlace.c_str());
}

void DNWindow::drawMenu()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    move(w.ws_row + 3, w.ws_col);
    middleString(string("Please select one of these following options:"), 3);


}

void DNWindow::drawCommandLine()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvprintw(w.ws_row - 1, 0, "COMMAND> ");
    move(w.ws_col - 1, 10);
    attron(COLOR_PAIR(0));
}

void DNWindow::moveUp()
{
    int y, x;
    getsyx(y, x);
    move(y - 1, x);
    refresh();
}

void DNWindow::moveDown()
{
    int y, x;
    getsyx(y, x);
    move(y + 1, x);
    refresh();
}

void DNWindow::moveLeft()
{
    int y, x;
    getsyx(y, x);
    move(y, x - 1);
    refresh();
}

void DNWindow::moveRight()
{
    int y, x;
    getsyx(y, x);
    move(y, x + 1);
    refresh();

}

void DNWindow::drawMainMenu()
{
    drawHeader();
    drawMenu();
    drawOptions();
    drawCommandLine();
    string input = "";
    drawCommandLine();
    inputString(input);
    executeMenuOption(input);


}

void DNWindow::executeMenuOption(string input)
{

    if (isalnum(*input.c_str())) {
        switch (atoi(input.c_str())) {
        case 1:
        {
            DNGame a(1);
            drawBoard(3, 0, 100);
            a.play();
            break;
        }
        case 2:
        {
            DNGame a(2);
            drawBoard(3, 0, 100);
            a.play();
            break;
        }
            
        case 3:
        {
            DNGame game(3);
            
            DNLogService::sharedObject().log(string("Starting to draw board \n"));
            drawBoard(3,0,100);
            DNLogService::sharedObject().log(string("going to play"));
            game.playNetworkgame();
            break;
        }
        case 4:{
            DNGame a(27);
            drawBoard(3,0,100);
            a.play();
            break;
        }
            
        default:
            break;
        }
    }

    if (input == "I" || input == "i") {
        clearScreen();
        refresh();
        
    }

    if (input == "Q" || input == "q") {
        terminate();
    }else{
        terminateWithErrorMessage(string("Wrong Input"));
    }

    
}

void DNWindow::clearScreen()
{
    clear();
    refresh();
}

void DNWindow::drawBoard(int start_Y, int start_X, int size)
{
    this->clearScreen();
    this->drawHeaderWithGuide(string("TicTacToe - press 'x' to trigger turn"));
    this->drawHeader();
    this->refreshDN();
    
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    

    move(start_Y, start_X);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size * 2; x++) {
            mvaddch(start_Y + y, start_X + x, ACS_CKBOARD);
        }
    }

    this->refreshDN();
    this->moveToCenter();
    return;
}

bool DNWindow::startLocalGameTwoHumans(string & nameOfPlayerOne, string & nameOfPlayerTwo)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    clearScreen();
    drawHeader();
    middleString("Please enter name of first player: ", w.ws_row / 2);
    
    while(true){
        inputString(nameOfPlayerOne);
        if(nameOfPlayerOne.size() == 0){ clearScreen();  middleString("Name cannot be empty, try again: ", w.ws_row / 2); drawHeader();}
        else{
            DNWindow::getInstance().clearScreen();
            DNWindow::getInstance().drawHeader();
            middleString("Please enter name of second player: ", w.ws_row / 2);
            while(true){    
                inputString(nameOfPlayerTwo);
                if(nameOfPlayerTwo.size() == 0) {clearScreen(); middleString("Name cannot be empty, try again: ", w.ws_row / 2); drawHeader(); }
                else break;
            }
            break;
            
        }
    }
    
   
    return false;
}

bool DNWindow::startLocalGameHumanVsCPU(string &nameOfPlayerOne)
{
    //    noraw();a
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    clearScreen();
    drawHeader();

    middleString("Please enter name of human player: ", w.ws_row / 2);
    
    while(true){
        inputString(nameOfPlayerOne);
        if (!nameOfPlayerOne.length()) middleString("Name cannot be empty, try again: ", w.ws_row / 2);
        else break;
    }
    
    clearScreen();
    drawHeader();
    return true;

}



int DNWindow::startRemoteGameTwoHumans(string& nameOfPlayer)
{
    return chooseTypeOfNetworkGame(nameOfPlayer);
}

int DNWindow::chooseTypeOfNetworkGame(string &nameOfPlayer)
{
    string input;
    clearScreen();
    drawHeader();
    drawOptionsForNetworkGame();
    refreshDN();
    return executeOptionsForNetworkgame(nameOfPlayer);
    
    
}

void DNWindow::drawOptionsForNetworkGame()
{
    refresh();
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    mvprintw(w.ws_row / 3, w.ws_col / 10, "( ) Connect to Game");
    mvprintw(w.ws_row / 3 + 1, w.ws_col / 10, "( ) Create a game");
    
    mvprintw(w.ws_row / 3 + 6, w.ws_col / 10, "( ) Quit");
    

    mvaddch(w.ws_row / 3, w.ws_col / 10 + 1, '1');
    mvaddch(w.ws_row / 3 + 1, w.ws_col / 10 + 1, '2');
    mvaddch(w.ws_row / 3 + 6, w.ws_col / 10 + 1, 'Q');
    
}

int DNWindow::executeOptionsForNetworkgame(string & input)
{
    
    
    drawCommandLine();
    refreshDN();
    inputString(input);
    
    
    if (atoi(input.c_str())  == 1 || atoi(input.c_str()) == 2) {
        return atoi(input.c_str());
    }else if (input == "Q" || input == "q") {
        terminate();
    }else{
        terminateWithErrorMessage(string("Wrong input"));
    }

    return false;
}


void DNWindow::allowMacDev()
{
    keypad(stdscr, TRUE);
}

void DNWindow::getCursorPosition(int & x, int &y)
{
    getsyx(y, x);
}

void DNWindow::drawSymbolBetter(DNCellState state, int& x, int& y)
{
    if (state == CROSS) {
        mvaddch(y, x, 'X');
        beep();
        moveRight();
        moveLeft();
        this->refreshDN();
    }
    else if (state == CIRCLE) {
        mvaddch(y, x, 'O');
        beep();
        moveRight();
        moveLeft();
        this->refreshDN();
    }
    else {
        terminateWithErrorMessage(string("Fatal Error"));
    }
}

void DNWindow::drawSymbol(DNCellState state, int & x, int &y)
{
    getsyx(y, x);
    if (state == CROSS) {
        addch('X');
        beep();
        moveRight();
        moveLeft();
    }
    else if (state == CIRCLE) {
        addch('O');
        beep();
        moveRight();
        moveLeft();
    }
    else {
        terminateWithErrorMessage(string("Fatal Error"));
    }
}

void DNWindow::enterServerIPAdress(string& ip_address)
{

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    mvprintw(w.ws_row - 1, 0, "ENTER HOST IP ADDRESS> ");
    refreshDN();
    inputString(ip_address);
    

}

void DNWindow::inputString(string& input)
{
    
    refreshDN();

    char ch;
    int key;
    allowMacDev();

    while ((key = getch())) {
        ch = key;
        DNLogService::sharedObject().log(ch);

        if (key == KEY_BACKSPACE && input.size() > 0) {
            input = input.substr(0, input.size() - 1);
            moveLeft();
            addch(' ');
            refreshDN();
            moveLeft();
            refreshDN();
            continue;
        }
        else if (key == KEY_BACKSPACE) {
            sound();
            continue;
        }
        if (key == '\n') {
            break;
        }
        input += ch;
        addch(ch);
        moveRight();
        refreshDN();

    }

}







void DNWindow::sound()
{
    beep();
}


void DNWindow::refreshDN()
{
    refresh();
}



void DNWindow::terminate()
{

    endwin();
    exit(0);
}



void DNWindow::terminateWithErrorMessage(string  message)
{
    DNLogService::sharedObject() << "ERROR => " << message << "\n";
    DNWindow::getInstance().clearScreen();
    DNWindow::getInstance().middleString(message, 13);
    DNWindow:: getInstance().refreshDN();
    sleep(3);
    DNWindow::getInstance().terminate();
}

void DNWindow::moveToCenter()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    move(w.ws_row/2, w.ws_col/2);
    refreshDN();
}




