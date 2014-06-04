//
//  DNGame.h
//  TicTacToe
//
//  Created by Tomas Sykora, jr. on 13/05/14.
//  Copyright (c) 2014 Tomas Sykora, jr. All rights reserved.
//

#ifndef __TicTacToe__DNGame__
#define __TicTacToe__DNGame__
#include "DNPlayer.h"
#include "DNMap.h"
#include <iostream>
class DNGame {
    DNPlayer *playerOne;
    DNPlayer *playerTwo;
    DNMap map;
    int y_sizeOfBoard;
    int x_sizeOfBoard;
    
    unsigned int y_offset, x_offset;
    
    void initLocalGameTwoHumans();
    void initLocalGameHumanVsCPU();
    

public:
    DNGame(int i);
    ~DNGame();
    void play();
    
};



#endif /* defined(__TicTacToe__DNGame__) */
