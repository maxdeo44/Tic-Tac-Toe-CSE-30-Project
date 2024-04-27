#ifndef ARTIFICIAL_INTEL_H
#define ARTIFICIAL_INTEL_H

#include <iostream>
#include <vector>
#include "gamestate.h"

Vec validMove(GameState game){
    for(int i = 0; i < game.size; i++){
        for(int j = 0; j < game.size; j++){
            if(game.grid[i][j] == -1){
                return Vec(i,j);
            }
        }
    }
    return Vec(0,0);
}

Vec findBestMove(GameState state){
    
    return Vec(1,1);
}

#endif