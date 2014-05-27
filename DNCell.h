//
//  Cell.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 18/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__Cell__
#define __TicTacToe__Cell__

#include <iostream>
#include "DNCellState.h"
class DNCell{
private:
    DNCellState state;
    size_t x_pos;
    size_t y_pos;
    
    
public:
    DNCell();
    DNCell(size_t, size_t);
    ~DNCell(void);
    size_t getX_pos();
    size_t getY_pos();
    DNCellState getState()const;
//    bool operator==(const DNCell& lhs, const DNCell& rhs)const;
//    inline bool operator!=(const DNCell& lhs, const DNCell& rhs);
    void setState(DNCellState);
    
    
    
    
};

#endif /* defined(__TicTacToe__Cell__) */
