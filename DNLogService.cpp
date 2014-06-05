//
//  DNLogService.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 05/06/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNLogService.h"
#include <iostream>
#include <fstream>
#include <ctime>



void DNLogService::log(string  message)
{
    time_t t = time(0);
    ofstream myfile;
    myfile.open ("log.txt", ios_base::app);
    struct tm * now = localtime( & t );
    myfile  << (now->tm_year + 1900) << '-'
            << (now->tm_mon + 1) << '-'
            << now->tm_mday << " -> "
            << now->tm_hour << ':'
            << now->tm_min
            << endl;
    myfile << message << endl;
    
}