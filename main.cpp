#include "curses.h"
#include <iostream>
#include "DNMap.h"
#include "DNCellState.h"
#include "DNWindow.h"
using namespace std;

int main(){
    DNWindow::getInstance().init();
    return 0;
}
