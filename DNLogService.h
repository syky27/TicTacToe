//
//  DNLogService.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 05/06/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__DNLogService__
#define __TicTacToe__DNLogService__

#include <iostream>
#include <string>
using namespace std;

class DNLogService {
public:
        
    static DNLogService & sharedObject()
    {
        static DNLogService instance;
        return instance;
    }
    
    
    

    DNLogService(){}
    DNLogService(DNLogService const&);
    void operator=(DNLogService const&);
    
    void log(string  message);
};


#endif /* defined(__TicTacToe__DNLogService__) */
