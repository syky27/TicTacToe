#include "curses.h"
#include <iostream>
#include "DNMap.h"
#include "DNCellState.h"
#include "DNMenuScreen.h"
#include "DNWindow.h"
using namespace std;

//#include "CellState.h"
int main(){
 
    DNMap *test = new DNMap;
    test->my_map[0][0]->setState(CROSS);
    test->my_map[0][1]->setState(CROSS);
    test->my_map[0][2]->setState(CROSS);
    test->my_map[0][3]->setState(CROSS);
//    test->my_map[0][4]->setState(CROSS);
    
//    test->my_map[1][0]->setState(CROSS);
    
    bool  b =( test->my_map[1][0]->getState() == test->my_map[0][0]->getState());
//
//
//    DNCellState x = test->checkForWinnerWithSymbol(CROSS);
//
//    
//
//    
//    cout << test->my_map[15][15]->getX_pos();
    
    
//    DNMenuScreen * screen = new DNMenuScreen();
//    screen->drawMainMenu();
//
    DNWindow::getInstance().init();
   // DNWindow::getInstance().drawHeader();
  //  DNWindow::getInstance().terminate();
    
    
    
       return 0;
}
