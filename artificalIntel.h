#ifndef ARTIFICIAL_INTEL_H
#define ARTIFICIAL_INTEL_H

#include <iostream>
#include "GameState.h"

Vec simpleAI(GameState state, bool currentTurn){
    for(int i = 0; i < state.size; i++){
        for(int j = 0; j < state.size; j++){
            if(!state.play(i, j)){
                return Vec(i, j);
            }
        }
    }
    return Vec(0, 0);
}

void sophisticatedAI(GameState state, bool currentTurn){

}

#endif