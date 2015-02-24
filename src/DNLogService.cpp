/**
 * @file  DNLogService.cpp
 * @brief Log Service
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */

#include "DNLogService.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <string>
#include <algorithm>



void DNLogService::log(string  message)
{
//    time_t t = time(0);
    ofstream myfile;
    myfile.open ("log.txt", ios_base::app);
//    struct tm * now = localtime( & t );
//    myfile  << (now->tm_year + 1900) << '-'
//            << (now->tm_mon + 1) << '-'
//            << now->tm_mday << " -> "
//            << now->tm_hour << ':'
//            << now->tm_min
//            << endl;
    myfile << message ;
    
}



void DNLogService::log(char  message)
{
//    time_t t = time(0);
    ofstream myfile;
    myfile.open ("log.txt", ios_base::app);
//    struct tm * now = localtime( & t );
//    myfile  << (now->tm_year + 1900) << '-'
//            << (now->tm_mon + 1) << '-'
//            << now->tm_mday << " -> "
//            << now->tm_hour << ':'
//            << now->tm_min
//            << endl;
    myfile << message ;
    
}

DNLogService & DNLogService::operator <<(const char* str)
{
    log(string(str));
    return sharedObject();
}

DNLogService &  DNLogService::operator << (const int num){
    stringstream tmp;
    tmp << num;
    log(tmp.str());
    return sharedObject();
}

DNLogService & DNLogService::operator <<(const string str)
{
    log(str);
    return sharedObject();
}

