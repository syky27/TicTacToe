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
#include "DNBotPlayer.h"
#include <iostream>
class DNGame {
    

    
    DNMap map;
    int y_sizeOfBoard;
    int x_sizeOfBoard;
    
    unsigned int y_offset, x_offset;
    
    void initLocalGameTwoHumans();
//    void initLocalGameHumanVsCPU();
    void initLocalGameTwoDumb();
    

public:
    DNGame(int i);
    ~DNGame();
    void play();
    DNPlayer *playerOne;
    DNPlayer *playerTwo;
};



#endif /* defined(__TicTacToe__DNGame__) */
