//
//  Cell.cpp
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 18/03/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#include "DNCell.h"
#include "DNCellState.h"

DNCell::DNCell(){

}

DNCell::DNCell(size_t x_pos, size_t y_pos){
    this->state = EMPTY;//DNCellState::EMPTY;
    this->x_pos = x_pos;
    this->y_pos = y_pos;

}

DNCell::~DNCell(void){

}

void DNCell::setState(DNCellState state){
    this->state = state;
}

DNCellState DNCell::getState()const{
    return this->state;
}

size_t DNCell::getX_pos(){
    return this->x_pos;
}

size_t DNCell::getY_pos(){
    return this->y_pos;
}


inline bool operator==(const DNCell& lhs, const DNCell& rhs){ return lhs.getState() == rhs.getState(); }
inline bool operator!=(const DNCell& lhs, const DNCell& rhs){return !(lhs == rhs);}
