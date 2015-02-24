/**
 * @file  main.cpp
 * @brief Main
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */


#include "DNWindow.h"

using namespace std;

int main(){
    DNWindow::getInstance().init();
    return 0;
}
