/**
 * @file  DNWindow.h
 * @brief Singleton to control NCURSES
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */


#ifndef __TicTacToe__DNWindow__
#define __TicTacToe__DNWindow__

#include <iostream>
#include "DNCellState.h"
#include <unistd.h> 
using namespace std;

class DNWindow {
public:

    /**
     * This is getter for instance of this singleton
     * @return instance of singleton;
     */
    static DNWindow& getInstance() {
        static DNWindow instance;
        return instance;
    }
    /**
     * Initialization of ncurses
     */
    void init();
    /**
     * Draws Header with name of program
     */
    void drawHeader();
    /**
     * Draws header with additional information such as how to play or if current network player is waiting or playing
     * @param[in] guide
     */
    void drawHeaderWithGuide(string guide);
    /**
     * Draws initial game options such as What kind of game to play
     */
    void drawOptions();
    /**
     * Puts string into middle of given line, using ncurses
     * @param[in] stringToPlace is string to place
     * @param[in] line number where to put string
     */
    void middleString(std::string stringToPlace, int line);
    /**
     * Draws menu -- string to inform that player is supposed to choose from options
     */
    void drawMenu();
    /**
     * Draws command line for users input
     */
    void drawCommandLine();
    /**
     * Draws main menu
     */
    void drawMainMenu();
    /**
     * Executes menu option
     * @param input - menu option 
     */
    void executeMenuOption(std::string input);
    /**
     * Executes menu options for network game
     * @param[out] input string for reading from
     * @return kind of network connection
     */
    int executeOptionsForNetworkgame(string & input);
    /**
     * Clears screen
     */
    void clearScreen();
    /**
     * Draws game board
     * @param start_Y - y map offset
     * @param start_X - x map offset
     * @param size  - size of map
     */
    void drawBoard(int start_Y, int start_X, int size);
    /**
     * Starts local game with two human players
     * @param nameOfPlayerOne name of player one
     * @param nameOfPlayerTwo name of player two
     * @return if is able to start game
     */
    bool startLocalGameTwoHumans(string & nameOfPlayerOne, string & nameOfPlayerTwo);
    /**
     * Starts local game with One human and One CPU player (AI)
     * @param nameOfPlayerOne name of human player
     * @return 
     */
    bool startLocalGameHumanVsCPU(string & nameOfPlayerOne);
    /**
     * Start network game over TCP server
     * @param nameOfPlayer name of player
     * @return returns game type
     */
    int startRemoteGameTwoHumans(string & nameOfPlayer);
    /**
     * Chooses type of network game
     * @param nameOfPlayer name of local player
     * @return returns game type
     */
    int chooseTypeOfNetworkGame(string &nameOfPlayer);
    /**
     * Draws options for network game
     */
    void drawOptionsForNetworkGame();
    /**
     * Method to allow keyboard debugging on MAC OS X 
     */
    void allowMacDev(void);
    /**
     * Moves cursor up
     */
    void moveUp();
    /**
     * Moves cursor down
     */
    void moveDown();
    /**
     * Moves cursor left
     */
    void moveLeft();
    /**
     * moves cursor right
     */
    void moveRight();
    /**
     * Gets cursor position
     * @param[out] x - x position
     * @param[out] y - y position
     */
    void getCursorPosition(int & x, int &y);
    /**
     * Draws symbol according to state of map cell
     * @param state symbol to draw
     * @param x x position
     * @param y y position
     */
    void drawSymbol(DNCellState state, int & x, int &y);
    /**
     * Draws symbol according to state of map cell better
     * @param state symbol to draw
     * @param x x position
     * @param y y position
     */
    void drawSymbolBetter(DNCellState state, int & x, int & y);
    /**
     * Getter for users input of ip address for network game
     * @param ip_address - inputed string
     */
    void enterServerIPAdress(string & ip_address);
    /**
     * Beeps
     */
    void sound();
    /**
     * Refreshes Ncurses
     */
    void refreshDN();
    /**
     * terminates program 
     */
    void terminate();
    /**
     * Terminates with error message
     * @param message
     */
    void terminateWithErrorMessage(string message);
    /**
     * Takes care of input string....
     * @param input
     */
    void inputString(string & input);
    /**
     * Moves cursor to center
     */
    void moveToCenter();




private:

    /**
     * implicit constructor
     */
    DNWindow() {}
    /**
     * Copy constructor
     * @param right hand side
     */
    DNWindow(DNWindow const&);
    /**
     * operator equality
     * @param right hand side
     */
    void operator=(DNWindow const&);
    int mx, my;
    
    ~DNWindow(){}
    
};


#endif /* defined(__TicTacToe__DNWindow__) */
