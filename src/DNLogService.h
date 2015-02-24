/**
 * @file  DNLogService.h
 * @brief Log Service
 * 
 * @author Tomas Sykora, jr. jump@syky.cz
 * @version 1.0
 */


#ifndef __TicTacToe__DNLogService__
#define __TicTacToe__DNLogService__

#include <iostream>
#include <string>
using namespace std;

class DNLogService {
public:
    /**
     * Getter for singleton
     * @return  singleton
     */    
    static DNLogService & sharedObject()
    {
        static DNLogService instance;
        return instance;
    }
    
    
    
    /**
     * Constructor
     */
    DNLogService(){}
    /**
     * Initial copy constructor
     * @param rhs rhs
     */
    DNLogService(DNLogService const& rhs);
    /**
     * Initial copy constructor
     * @param rhs rhs
     */
    void operator=(DNLogService const& rhs);
    /**
     * operator =
     * @param str message
     * @return it self
     */
    DNLogService & operator << (const char * str);
    /**
     * operator =
     * @param num message
     * @return it self
     */
    DNLogService &  operator << (const int num);
    /**
     * operator =
     * @param str message
     * @return it self
     */
    DNLogService &  operator << (const string str);
    
    /**
     * Log a message
     * @param message
     */
    void log(string  message);
    /**
     * Log a message
     * @param message
     */
    void log(char  message);
};


#endif /* defined(__TicTacToe__DNLogService__) */
